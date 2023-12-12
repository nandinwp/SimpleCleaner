#include "Registro.h"
#include <Windows.h>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Microsoft::Win32;
using namespace msclr::interop;


Registro::Registro(){

}

bool Registro::IsRunAsAdmin()
{
    BOOL isAdmin = FALSE;
    PSID adminGroup;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup)) {
        if (!CheckTokenMembership(NULL, adminGroup, &isAdmin)) {
            isAdmin = FALSE;
        }

        FreeSid(adminGroup);
    }

    return isAdmin == TRUE;
}

void Registro::addDirectoryToRegistry(const char* directoryPath, bool standard)
{
    const char* subKey = "Software\\SimpleCleaner\\Diretorios";

    try {
        // Abrir a chave do Registro (ou criar se não existir)
        RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

        if (registryKey == nullptr) {
            throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
        }

        //Obtém valor atual.
        int _value = Get_Atual_Index();

        registryKey->SetValue(_value.ToString(), gcnew String(directoryPath), RegistryValueKind::String);

        // Fechar a chave do Registro
        registryKey->Close();

        //Salva nova chave unica.
        Set_atual_index((_value + 1));

    }
    catch (Exception^ ex) {
        String^ errorMessage = gcnew String(ex->Message);
        MessageBox::Show(errorMessage, "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

int Registro::Get_Atual_Index() 
{
    const char* subKey = "Software\\SimpleCleaner\\index";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

    if (registryKey == nullptr) {
        throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
    }
    String^ _value = (String^)registryKey->GetValue("Index");
    registryKey->Close();

    _value = (_value == nullptr) ? "0" : _value;


    return INT32::Parse(_value);
}

void Registro::Set_atual_index(int index)
{
    const char* subKey = "Software\\SimpleCleaner\\index";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

    if (registryKey == nullptr) {
        throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
    }

    registryKey->SetValue("Index", "" + index, RegistryValueKind::String);
    registryKey->Close();
}

void Registro::Set_First_Use(bool IsFirst) 
{
    const char* subKey = "Software\\SimpleCleaner\\config";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

        if (registryKey == nullptr) {
            throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
        }

        registryKey->SetValue("FirstUse", "" + IsFirst, RegistryValueKind::String);
        registryKey->Close();
}

bool Registro::Get_First_Use_status()
{
    const char* subKey = "Software\\SimpleCleaner\\config";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

    if (registryKey == nullptr) {
        throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
    }

    bool result;

    try
    {
       String^ _value  = (String^)registryKey->GetValue("FirstUse");
       
       result = !(_value->Equals("False"));
    }
    catch (Exception^ ex)
    {
        result = false;
        Set_First_Use(false);
    }

    registryKey->Close();
    
    return result;

}

void Registro::Delete_this_index(int index) 
{
    const char* subKey = "Software\\SimpleCleaner\\Diretorios";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

    if (registryKey == nullptr) {
        throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
    }

    int lastDelete = Get_Atual_delete();
    int selectendIndex = index;
    int atualInclude = Get_Atual_Index();

    String^ forDelete = ""+index;

    registryKey->DeleteValue(forDelete);
    registryKey->Close();

    int _atualIndex = atualInclude;

    Set_atual_index((_atualIndex - 1));


}

void Registro::Set_Atual_delete(int index)
{
    const char* subKey = "Software\\SimpleCleaner\\index";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

    if (registryKey == nullptr) {
        throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
    }

    registryKey->SetValue("Deleted", "" + index, RegistryValueKind::String);
    registryKey->Close();
}

int Registro::Get_Atual_delete()
{
    const char* subKey = "Software\\SimpleCleaner\\index";
    RegistryKey^ registryKey = Registry::CurrentUser->CreateSubKey(gcnew String(subKey));

    if (registryKey == nullptr) {
        throw gcnew Exception("Erro ao abrir/criar a chave do Registro.");
    }

    String^ result = (String^)registryKey->GetValue("Deleted");
    try
    {
        int value = INT32::Parse(result);
        return value;
    }
    catch (...)
    {
        return -1;
    }
    registryKey->Close();
}
