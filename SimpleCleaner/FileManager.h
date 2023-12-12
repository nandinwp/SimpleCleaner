#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <string.h>

using namespace System::Windows::Forms;
using namespace System;
#define APPNAME "SimpleCleaner"

struct Config_ {
    bool autoSearch;
    bool startup;
    bool isTopMost;
    bool closeIsDone;
};

void deleteFilesAndFolders(const char* path);
void getDirectoriesFromRegistry(char*** directories, int* count);
void LoadConfig(struct Config_* config, const char* filename);
void SaveConfig(const struct Config_* config, const char* filename);


void deleteFilesAndFolders(const char* path) {
    WIN32_FIND_DATAA findData;
    HANDLE hFind;
    char filePath[MAX_PATH];

    std::string expandedPath = path;
    if (expandedPath.find('%') != std::string::npos) {
        // Se o caminho cont�m vari�veis de ambiente, expanda o caminho
        char expandedBuffer[MAX_PATH];
        if (ExpandEnvironmentStringsA(path, expandedBuffer, MAX_PATH) != 0) {
            expandedPath = expandedBuffer;
        }
        else {
            std::cout << "Erro ao expandir o caminho: " << path << std::endl;
            return;
        }
    }

    sprintf(filePath, "%s\\*", expandedPath.c_str());

    hFind = FindFirstFileA(filePath, &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cout << "Erro ao abrir o diret�rio: " << expandedPath << std::endl;
        return;
    }

    do {
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) {
            continue; // Ignorar os diret�rios "." e ".."
        }

        sprintf(filePath, "%s\\%s", expandedPath.c_str(), findData.cFileName);

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // Item � um diret�rio
            deleteFilesAndFolders(filePath); // Recursivamente excluir arquivos e subdiret�rios
            RemoveDirectoryA(filePath); // Excluir diret�rio vazio
        }
        else {
            // Item � um arquivo
            DeleteFileA(filePath); // Excluir arquivo
        }
    } while (FindNextFileA(hFind, &findData) != 0);

    FindClose(hFind);
}

void getDirectoriesFromRegistry(char*** directories, int* count) {
    HKEY hKey;
    const char* subKey = "Software\\" APPNAME "\\Diretorios";

    // Abrir a chave do Registro
    if (RegOpenKeyExA(HKEY_CURRENT_USER, subKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS) {
        MessageBox::Show("Erro ao abrir a chave do Registro.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Obter o n�mero de valores na chave
    DWORD valueCount;
    if (RegQueryInfoKey(hKey, NULL, NULL, NULL, NULL, NULL, NULL, &valueCount, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) {
        MessageBox::Show("Erro ao obter informa��es da chave do Registro.\n");
        RegCloseKey(hKey);
        return;
    }

    // Alocar mem�ria para a matriz de diret�rios
    *count = valueCount;
    *directories = (char**)malloc(valueCount * sizeof(char*));

    // Iterar sobre os valores da chave e preencher a matriz
    for (DWORD i = 0; i < valueCount; i++) {
        char valueName[MAX_PATH];
        DWORD valueNameSize = sizeof(valueName);

        if (RegEnumValueA(hKey, i, valueName, &valueNameSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            (*directories)[i] = _strdup(valueName);
        }
    }

    // Fechar a chave do Registro
    RegCloseKey(hKey);
}

// Fun��o para carregar configura��es de um arquivo INI
void LoadConfig(struct Config_* config, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        fscanf(file, "autoSearch=%d\n", &config->autoSearch);
        fscanf(file, "startup=%d\n", &config->startup);
        fscanf(file, "isTopMost=%d\n", &config->isTopMost);
        fscanf(file, "closeIsDone=%d\n", &config->closeIsDone);
        fclose(file);
    }
    else {
        // Se o arquivo n�o existe, carrega configura��es padr�o
        config->autoSearch = false;
        config->startup = false;
        config->isTopMost = false;
        config->closeIsDone = false;
    }
}

void SaveConfig(const struct Config_* config, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "autoSearch=%d\n", config->autoSearch);
        fprintf(file, "startup=%d\n", config->startup);
        fprintf(file, "isTopMost=%d\n", config->isTopMost);
        fprintf(file, "closeIsDone=%d\n", config->closeIsDone);
        fclose(file);
    }
}