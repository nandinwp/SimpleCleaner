#pragma once
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

using namespace System;
using namespace System::IO;



public ref class Logger
{
public:
    static void LogInfo(String^ message) {
        Log("INFO", message);
        MessageBeep(MB_ICONINFORMATION);
    }

    static void LogWarning(String^ message) {
        Log("WARNING", message);
        MessageBeep(MB_ICONWARNING);
    }

    static void LogCaution(String^ message) {
        Log("CAUTION", message);
        MessageBeep(MB_ICONWARNING);
    }

    static void LogError(String^ message) {
        Log("ERROR", message);
        MessageBeep(MB_ICONERROR);
    }

    static void LogCatastrophe(String^ message) {
        Log("CATASTROPHE", message);
        MessageBeep(MB_ICONHAND);
    }

private:
    static void Log(String^ level, String^ message) {
        // Obtém o caminho para a pasta "Documentos"
        String^ documentsPath = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);

        // Cria o caminho para a pasta "Agiu"
        String^ agiuPath = Path::Combine(documentsPath, "Agiu");

        // Cria a pasta se ela não existir
        if (!Directory::Exists(agiuPath)) {
            Directory::CreateDirectory(agiuPath);
        }

        // Obtém a data atual para criar o nome do arquivo
        String^ currentDate = DateTime::Now.ToString("yyyyMMdd");
        String^ filePath = Path::Combine(agiuPath, currentDate + ".txt");

        // Abre ou cria o arquivo em modo de anexo (append)
        FileStream^ fs = gcnew FileStream(filePath, FileMode::Append, FileAccess::Write);
        StreamWriter^ sw = gcnew StreamWriter(fs);

        // Escreve a mensagem no arquivo
        sw->WriteLine("[" + DateTime::Now.ToString() + "] [" + level + "] " + message);

        // Fecha os fluxos
        sw->Close();
        fs->Close();
    }
};

