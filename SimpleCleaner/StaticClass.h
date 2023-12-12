#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "ManagerSettings.h"
#include "Logger.h"
#include "ShowMessage.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace Microsoft::Win32;
using namespace System::IO;
using namespace System::Net;
using namespace System::Text;
using namespace System::Reflection;


#pragma comment(lib, "shlwapi.lib")

#ifndef STATICCLASS_H
#define STATICCLASS_H

public ref class StaticClass : Logger
{
public:
    static String^ aboutThis = "Ainda n�o foi detalhado";// "Bem-vindo ao SimpleCleaner! Desenvolvido por Lu�s Fernando Andrade Cordeiro, um profissional altamente qualificado\n com forma��o em An�lise e Desenvolvimento de Sistemas, e p�s-graduado em Ci�ncia de Dados e Analytics.\n\n Desde 2015, Lu�s tem dedicado sua jornada de estudos para aprimorar suas habilidades e aplic�-las na cria��o deste inovador sistema de gerenciamento de cache.\n\n O prop�sito central deste software � proporcionar uma solu��o intuitiva e eficaz para o monitoramento e limpeza de diret�rios do sistema.\n\n Lu�s projetou o sistema com a vis�o de oferecer aos usu�rios a capacidade total de personaliza��o, permitindo que definam facilmente os diret�rios que desejam monitorar e limpar.\n\n Isso significa que o usu�rio mant�m o controle total sobre as configura��es, eliminando qualquer preocupa��o sobre o sistema n�o atender �s expectativas.\n\n Acreditamos que SimpleCleaner oferece uma experi�ncia �nica e indispens�vel para otimizar o gerenciamento de cache do sistema.\n\n Sinta-se � vontade para explorar as funcionalidades e aproveitar ao m�ximo essa ferramenta desenvolvida com paix�o e expertise.\n\n Obrigado por escolher SimpleCleaner!";
    static const char* SubChave = "Software\\SimpleCleaner\\Diretorios";

	static void getDirectoriesFromRegistry(char*** directories, int* count, char*** tagItem) {
        HKEY hKey;

        // Abrir a chave do Registro
        if (RegOpenKeyExA(HKEY_CURRENT_USER, SubChave, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS) {
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
        *tagItem = (char**)malloc(32 * sizeof(char*));

        // Iterar sobre os valores da chave e preencher a matriz
        for (DWORD i = 0; i < valueCount; i++) {
            char valueName[MAX_PATH];
            DWORD valueNameSize = sizeof(valueName);

            if (RegEnumValueA(hKey, i, valueName, &valueNameSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
                (*directories)[i] = _strdup(valueName);
                (*tagItem)[i] = _strdup(valueName);
            }
        }

        // Fechar a chave do Registro
        RegCloseKey(hKey);
    }

    static char* getValuesFromRegistry(const char* valueName)
    {
        
        HKEY hKey;

        // Abrir a chave do Registro
        if (RegOpenKeyExA(HKEY_CURRENT_USER, SubChave, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
            MessageBox::Show("Erro ao abrir a chave do Registro.");
            return "";
        }

        DWORD valueType;
        DWORD valueSize = 0;

        // Obter o tamanho necess�rio do valor
        if (RegQueryValueExA(hKey, valueName, NULL, &valueType, NULL, &valueSize) != ERROR_SUCCESS) {
            MessageBox::Show("Erro ao obter informa��es do valor do Registro.");
            RegCloseKey(hKey);
            return "";
        }

        // Verificar se o tipo de valor � REG_SZ (string)
        if (valueType != REG_SZ) {
            MessageBox::Show("O valor do Registro n�o � uma string.");
            RegCloseKey(hKey);
            return "";
        }

        // Alocar mem�ria para armazenar o valor
        char* valueData = new char[valueSize];

        // Obter o valor do Registro
        if (RegQueryValueExA(hKey, valueName, NULL, &valueType, (LPBYTE)valueData, &valueSize) != ERROR_SUCCESS) {
            MessageBox::Show("Erro ao obter o valor do Registro.");
            delete[] valueData;
            RegCloseKey(hKey);
            return "";
        }
        RegCloseKey(hKey);

        return valueData;
       
    }

    static bool IsDirectory(const char* path)
    {
        DWORD attributes = GetFileAttributesA(path);
        return (attributes != INVALID_FILE_ATTRIBUTES) && (attributes & FILE_ATTRIBUTE_DIRECTORY);
    }

    static void DeleteRegistryValue(const char* valueName) 
    {
        try
        {
           

        }
        catch (Exception^ex)
        {
                
        }
    }

    static long TotalSize(String^ diretorio) 
    {
        long long int tamanhoTotal = 0;

        try
        {
            cli::array<String^>^ arquivos = Directory::GetFiles(diretorio);
            cli::array<String^>^ subdiretorios = Directory::GetDirectories(diretorio);

            for each (String ^ arquivo in arquivos)
            {
                FileInfo^ fileInfo = gcnew FileInfo(arquivo);
                tamanhoTotal += fileInfo->Length;
            }

            for each (String ^ subdiretorio in subdiretorios)
            {
                tamanhoTotal += TotalSize(subdiretorio);
            }
        }
        catch (Exception^ ex)
        {
            LogError("Erro ao calcular o tamanho dos arquivos: " + ex->Message);
        }

        return tamanhoTotal;
    }

    static String^ ConvertSize(long long int sizeInBytes, double& size)
    {
        const long long int kb = 1024;
        const long long int mb = kb * 1024;
        const long long int gb = mb * 1024;

        if (sizeInBytes < kb)
        {
            size = static_cast<double>(sizeInBytes);
            return size + " Bytes";
        }
        else if (sizeInBytes < mb)
        {
            size = static_cast<double>(sizeInBytes) / kb;
            return size + " KB";
        }
        else if (sizeInBytes < gb)
        {
            size = static_cast<double>(sizeInBytes) / mb;
            return size + " MB";
        }
        else
        {
            size = static_cast<double>(sizeInBytes) / gb;
            return size + " GB";
        }
    }

    static long long TotalSizeListaDiretorios(List<String^>^ diretorios)
    {
        long long int tamanhoTotal = 0;

        try
        {
            for each (String ^ diretorio in diretorios)
            {
                tamanhoTotal += TotalSize(diretorio);
            }
        }
        catch (Exception^ ex)
        {
            LogError("Erro ao calcular o tamanho dos arquivos: " + ex->Message);
        }

        return tamanhoTotal;
    }

    static void DeleteDirectory(String^ path)
    {
        try
        {
            // Exclua todos os arquivos no diret�rio
            cli::array<String^>^ files = Directory::GetFiles(path);
            for each (String ^ file in files)
            {
                File::Delete(file);
            }

            // Exclua todos os subdiret�rios chamando a fun��o recursivamente
            cli::array<String^>^ subdirectories = Directory::GetDirectories(path);
            for each (String ^ subdirectory in subdirectories)
            {
                DeleteDirectory(subdirectory);
            }

            // Finalmente, remova o diret�rio principal
            Directory::Delete(path);
        }
        catch (Exception^ ex)
        {
            LogError("Erro ao excluir diret�rio:" + ex->Message);
        }
    }

    static void WriteData(Stream^ strm) {
        BinaryWriter^ writer = gcnew BinaryWriter(strm);
        writer->Write(ManagerSettings::_minimizeClose);
        writer->Write(ManagerSettings::_autoSearch);
        writer->Write(ManagerSettings::_startUpWindows);
        writer->Write(ManagerSettings::_topMost);
        writer->Close();
    }

    static void ReadData(Stream^ strm) {
        try
        {
            BinaryReader^ reader = gcnew BinaryReader(strm);

            ManagerSettings::_minimizeClose = reader->ReadBoolean();
            ManagerSettings::_autoSearch = reader->ReadBoolean();
            ManagerSettings::_startUpWindows = reader->ReadBoolean();
            ManagerSettings::_topMost = reader->ReadBoolean();

            reader->Close();
        }
        catch (Exception^ ex)
        {
            Logger::LogError(ex->Message);
        }
    }

    static int Show(String^ title, String^ neg, String^ pos,int timer) {
        SimpleCleaner::ShowMessage^ msg = gcnew SimpleCleaner::ShowMessage
        (
            title, pos, neg, timer
        );
        auto resp = msg->ShowDialog();

        if (resp == System::Windows::Forms::DialogResult::OK) {
            delete msg;
            return 1;
        }
        else {
            delete msg;
            return 0;
        }
    }

   static void AdicionarAoInicioDoWindows() {
       
       // Obtenha o caminho do execut�vel do pr�prio programa
        String^ caminhoDoAplicativo = Assembly::GetExecutingAssembly()->Location;

        Microsoft::Win32::RegistryKey^ chaveRun = Microsoft::Win32::Registry::CurrentUser->OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);

        // Verifique se a chave de execu��o j� existe
        if (chaveRun == nullptr) {
            // Se n�o existir, crie-a
            chaveRun = Microsoft::Win32::Registry::CurrentUser->CreateSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
        }

        // Adicione o caminho do seu aplicativo � chave de execu��o
        chaveRun->SetValue("SimpleCleaner", caminhoDoAplicativo);

        // Feche a chave de execu��o
        chaveRun->Close();
    }

   static void RemoverDoInicioDoWindows() {
       // Abra a chave de execu��o no registro
       Microsoft::Win32::RegistryKey^ chaveRun = Microsoft::Win32::Registry::CurrentUser->OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);

       // Verifique se a chave de execu��o existe
       if (chaveRun != nullptr) {
           // Remova a entrada associada ao seu aplicativo
           chaveRun->DeleteValue("SimpleCleaner", false);

           // Feche a chave de execu��o
           chaveRun->Close();
       }
   }

};
#endif // STATICCLASS_H
