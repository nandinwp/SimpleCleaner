#pragma once
#include "StaticClass.h"
#include "Registro.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Runtime::InteropServices;
using namespace System::Drawing;


namespace SimpleCleaner {

	/// <summary>
	/// Sumário para AddKey
	/// </summary>
	public ref class AddKey : public System::Windows::Forms::UserControl
	{
		Registro rg;
	public:
		AddKey(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~AddKey()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::TextBox^ txbNewDir;
	protected:

	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::ListView^ listDir;
	private: System::Windows::Forms::ColumnHeader^ directory;
	private: System::Windows::Forms::Button^ btnDeleteDir;
	private: System::Windows::Forms::Button^ btnDef;



	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->txbNewDir = (gcnew System::Windows::Forms::TextBox());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->listDir = (gcnew System::Windows::Forms::ListView());
			this->directory = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnDeleteDir = (gcnew System::Windows::Forms::Button());
			this->btnDef = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdd->Location = System::Drawing::Point(322, 86);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(98, 31);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"Adicionar";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &AddKey::btnAdd_Click);
			// 
			// txbNewDir
			// 
			this->txbNewDir->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txbNewDir->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txbNewDir->Location = System::Drawing::Point(18, 89);
			this->txbNewDir->Name = L"txbNewDir";
			this->txbNewDir->Size = System::Drawing::Size(278, 25);
			this->txbNewDir->TabIndex = 1;
			// 
			// lblTitle
			// 
			this->lblTitle->BackColor = System::Drawing::SystemColors::ControlLight;
			this->lblTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(0, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(441, 51);
			this->lblTitle->TabIndex = 2;
			this->lblTitle->Text = L"Adicione um novo diretório para ser limpo";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listDir
			// 
			this->listDir->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->listDir->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listDir->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->directory });
			this->listDir->FullRowSelect = true;
			this->listDir->HideSelection = false;
			this->listDir->Location = System::Drawing::Point(18, 132);
			this->listDir->Name = L"listDir";
			this->listDir->Size = System::Drawing::Size(402, 310);
			this->listDir->TabIndex = 3;
			this->listDir->UseCompatibleStateImageBehavior = false;
			this->listDir->View = System::Windows::Forms::View::Details;
			this->listDir->SelectedIndexChanged += gcnew System::EventHandler(this, &AddKey::listDir_SelectedIndexChanged);
			// 
			// directory
			// 
			this->directory->Text = L"Diretório:";
			this->directory->Width = 402;
			// 
			// btnDeleteDir
			// 
			this->btnDeleteDir->BackColor = System::Drawing::Color::IndianRed;
			this->btnDeleteDir->Enabled = false;
			this->btnDeleteDir->FlatAppearance->BorderSize = 0;
			this->btnDeleteDir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteDir->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeleteDir->Location = System::Drawing::Point(322, 460);
			this->btnDeleteDir->Name = L"btnDeleteDir";
			this->btnDeleteDir->Size = System::Drawing::Size(98, 31);
			this->btnDeleteDir->TabIndex = 4;
			this->btnDeleteDir->Text = L"Apagar";
			this->btnDeleteDir->UseVisualStyleBackColor = false;
			this->btnDeleteDir->Click += gcnew System::EventHandler(this, &AddKey::btnDeleteDir_Click);
			// 
			// btnDef
			// 
			this->btnDef->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->btnDef->Enabled = false;
			this->btnDef->FlatAppearance->BorderSize = 0;
			this->btnDef->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDef->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDef->Location = System::Drawing::Point(218, 460);
			this->btnDef->Name = L"btnDef";
			this->btnDef->Size = System::Drawing::Size(98, 31);
			this->btnDef->TabIndex = 5;
			this->btnDef->Text = L"Padrão";
			this->btnDef->UseVisualStyleBackColor = false;
			this->btnDef->Click += gcnew System::EventHandler(this, &AddKey::btnDef_Click);
			// 
			// AddKey
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Controls->Add(this->btnDef);
			this->Controls->Add(this->btnDeleteDir);
			this->Controls->Add(this->listDir);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->txbNewDir);
			this->Controls->Add(this->btnAdd);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"AddKey";
			this->Size = System::Drawing::Size(441, 518);
			this->Load += gcnew System::EventHandler(this, &AddKey::AddKey_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void LoadKeys() 
	{
		char** directories;
		char** tagItem;
		int count;

		StaticClass::getDirectoriesFromRegistry(&directories, &count, &tagItem);

		if (count == 0) 
		{
			btnDef->Enabled = true;
			rg.Set_atual_index(0);
		}
		else 
		{
			btnDef->Enabled = false;
		}

		// Imprimir os diretórios da matriz
		for (int i = 0; i < count; i++) {
			String^ Value;
			Value = gcnew String(StaticClass::getValuesFromRegistry(directories[i]));

			ListViewItem^ dirItem = (gcnew ListViewItem(gcnew cli::array<String^>(1) {
				(Value)
			}, -1));

			dirItem->Tag = gcnew String(tagItem[i]);
			listDir->Items->Add(dirItem);
		}

		// Liberar memória alocada
		for (int i = 0; i < count; i++) {
			free(directories[i]);
			free(tagItem[i]);
		}
		free(directories);
		free(tagItem);
	}
	private: System::Void AddKey_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		LoadKeys();
	}
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (StaticClass::IsDirectory((char*)(void*)Marshal::StringToHGlobalAnsi(txbNewDir->Text))) 
		{

			listDir->Items->Clear();

			rg.addDirectoryToRegistry((char*)(void*)Marshal::StringToHGlobalAnsi(txbNewDir->Text), false);
			
			txbNewDir->Text = "";
			
			StaticClass::Show("Adicionando com sucesso!","","Ok",5);
			LoadKeys();

		}
		else {
			StaticClass::Show("Por favor digite um diretorio válido", "", "Ok", 5);
		}
	}
	private: System::Void listDir_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (listDir->SelectedItems->Count > 0)
			btnDeleteDir->Enabled = true;
		else
			btnDeleteDir->Enabled = false;
	}
	private: System::Void btnDeleteDir_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (listDir->SelectedItems->Count > 0) 
		{
			ListViewItem^ selected = listDir->SelectedItems[0];

			int thisIndex = Int32::Parse((String^)selected->Tag);

			rg.Delete_this_index(thisIndex);
			rg.Set_Atual_delete(thisIndex);

			StaticClass::DeleteRegistryValue((char*)(void*)Marshal::StringToHGlobalAnsi(selected->Text));
			
			listDir->Items->Remove(selected);
			listDir->Refresh();
		}
		else
		{
			MessageBox::Show("Nenhum item selecionado!", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnDef_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (rg.Get_First_Use_status())
		{
			rg.addDirectoryToRegistry("c:\\Windows\\Prefetch", true);
			rg.addDirectoryToRegistry("C:\\Users\\luyfe\\AppData\\Local\\Temp", true);
			rg.addDirectoryToRegistry("C:\\Windows\\Temp", true);
			rg.addDirectoryToRegistry("%WINDIR%\\SoftwareDistribution\\Download", true);
			rg.addDirectoryToRegistry("%WINDIR%\\Fonts\\cache", true);
			rg.addDirectoryToRegistry("%LOCALAPPDATA%\\Microsoft\\Windows\\Explorer", true);
			rg.addDirectoryToRegistry("%LOCALAPPDATA%\\Microsoft\\Windows\\INetCache", true);

			rg.Set_First_Use(true);
		}

	}
};
}
