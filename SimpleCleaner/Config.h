#pragma once
#include "StaticClass.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SimpleCleaner {

	/// <summary>
	/// Sumário para Config
	/// </summary>
	public ref class Config : public System::Windows::Forms::UserControl
	{
		
	public:
		Config(void)
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
		~Config()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabConfig;
	protected:
	private: System::Windows::Forms::TabPage^ tbPage1;

	public: System::Windows::Forms::Button^ btnAction;
	private: System::Windows::Forms::CheckBox^ ckbAutoSearch;
	private: System::Windows::Forms::CheckBox^ ckbAutoStart;
	private: System::Windows::Forms::CheckBox^ ckbisTopMost;
	private: System::Windows::Forms::CheckBox^ ckbcloseIsDone;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	public:

	public:
	private:

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
			this->tabConfig = (gcnew System::Windows::Forms::TabControl());
			this->tbPage1 = (gcnew System::Windows::Forms::TabPage());
			this->ckbcloseIsDone = (gcnew System::Windows::Forms::CheckBox());
			this->ckbisTopMost = (gcnew System::Windows::Forms::CheckBox());
			this->ckbAutoStart = (gcnew System::Windows::Forms::CheckBox());
			this->ckbAutoSearch = (gcnew System::Windows::Forms::CheckBox());
			this->btnAction = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tabConfig->SuspendLayout();
			this->tbPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabConfig
			// 
			this->tabConfig->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabConfig->Controls->Add(this->tbPage1);
			this->tabConfig->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabConfig->Location = System::Drawing::Point(0, 0);
			this->tabConfig->Multiline = true;
			this->tabConfig->Name = L"tabConfig";
			this->tabConfig->SelectedIndex = 0;
			this->tabConfig->Size = System::Drawing::Size(441, 455);
			this->tabConfig->TabIndex = 0;
			// 
			// tbPage1
			// 
			this->tbPage1->Controls->Add(this->groupBox1);
			this->tbPage1->Location = System::Drawing::Point(4, 4);
			this->tbPage1->Name = L"tbPage1";
			this->tbPage1->Padding = System::Windows::Forms::Padding(3);
			this->tbPage1->Size = System::Drawing::Size(433, 426);
			this->tbPage1->TabIndex = 0;
			this->tbPage1->Text = L"Modo operacional";
			this->tbPage1->UseVisualStyleBackColor = true;
			// 
			// ckbcloseIsDone
			// 
			this->ckbcloseIsDone->AutoSize = true;
			this->ckbcloseIsDone->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ckbcloseIsDone->FlatAppearance->BorderSize = 0;
			this->ckbcloseIsDone->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ckbcloseIsDone->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ckbcloseIsDone->Location = System::Drawing::Point(59, 144);
			this->ckbcloseIsDone->Name = L"ckbcloseIsDone";
			this->ckbcloseIsDone->Size = System::Drawing::Size(195, 23);
			this->ckbcloseIsDone->TabIndex = 3;
			this->ckbcloseIsDone->Text = L"Botão fechar minimiza";
			this->ckbcloseIsDone->UseVisualStyleBackColor = true;
			this->ckbcloseIsDone->CheckedChanged += gcnew System::EventHandler(this, &Config::ckbcloseIsDone_CheckedChanged);
			// 
			// ckbisTopMost
			// 
			this->ckbisTopMost->AutoSize = true;
			this->ckbisTopMost->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ckbisTopMost->FlatAppearance->BorderSize = 0;
			this->ckbisTopMost->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ckbisTopMost->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ckbisTopMost->Location = System::Drawing::Point(59, 115);
			this->ckbisTopMost->Name = L"ckbisTopMost";
			this->ckbisTopMost->Size = System::Drawing::Size(136, 23);
			this->ckbisTopMost->TabIndex = 2;
			this->ckbisTopMost->Text = L"Sempre visivel";
			this->ckbisTopMost->UseVisualStyleBackColor = true;
			this->ckbisTopMost->CheckedChanged += gcnew System::EventHandler(this, &Config::ckbisTopMost_CheckedChanged);
			// 
			// ckbAutoStart
			// 
			this->ckbAutoStart->AutoSize = true;
			this->ckbAutoStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ckbAutoStart->FlatAppearance->BorderSize = 0;
			this->ckbAutoStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ckbAutoStart->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ckbAutoStart->Location = System::Drawing::Point(59, 86);
			this->ckbAutoStart->Name = L"ckbAutoStart";
			this->ckbAutoStart->Size = System::Drawing::Size(195, 23);
			this->ckbAutoStart->TabIndex = 1;
			this->ckbAutoStart->Text = L"Iniciar com o windows";
			this->ckbAutoStart->UseVisualStyleBackColor = true;
			this->ckbAutoStart->CheckedChanged += gcnew System::EventHandler(this, &Config::ckbAutoStart_CheckedChanged);
			// 
			// ckbAutoSearch
			// 
			this->ckbAutoSearch->AutoSize = true;
			this->ckbAutoSearch->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ckbAutoSearch->FlatAppearance->BorderSize = 0;
			this->ckbAutoSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ckbAutoSearch->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ckbAutoSearch->Location = System::Drawing::Point(59, 57);
			this->ckbAutoSearch->Name = L"ckbAutoSearch";
			this->ckbAutoSearch->Size = System::Drawing::Size(206, 23);
			this->ckbAutoSearch->TabIndex = 0;
			this->ckbAutoSearch->Text = L"Varrer automaticamente";
			this->ckbAutoSearch->UseVisualStyleBackColor = true;
			this->ckbAutoSearch->CheckedChanged += gcnew System::EventHandler(this, &Config::ckbAutoSearch_CheckedChanged);
			// 
			// btnAction
			// 
			this->btnAction->BackColor = System::Drawing::Color::LightGreen;
			this->btnAction->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAction->FlatAppearance->BorderSize = 0;
			this->btnAction->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAction->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAction->Location = System::Drawing::Point(326, 451);
			this->btnAction->Name = L"btnAction";
			this->btnAction->Size = System::Drawing::Size(98, 31);
			this->btnAction->TabIndex = 5;
			this->btnAction->Text = L"Aplicar";
			this->btnAction->UseVisualStyleBackColor = false;
			this->btnAction->Click += gcnew System::EventHandler(this, &Config::btnAction_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->ckbAutoSearch);
			this->groupBox1->Controls->Add(this->ckbcloseIsDone);
			this->groupBox1->Controls->Add(this->ckbAutoStart);
			this->groupBox1->Controls->Add(this->ckbisTopMost);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Location = System::Drawing::Point(56, 93);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(326, 231);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ações";
			// 
			// Config
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->Controls->Add(this->btnAction);
			this->Controls->Add(this->tabConfig);
			this->Name = L"Config";
			this->Size = System::Drawing::Size(441, 497);
			this->Load += gcnew System::EventHandler(this, &Config::Config_Load);
			this->tabConfig->ResumeLayout(false);
			this->tbPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAction_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Stream^ meuStream = gcnew FileStream("define.bin", FileMode::Create);
		StaticClass::WriteData(meuStream);
		meuStream->Close();

		StaticClass::Show("Configurações salva com sucesso!", "", "Ok",5);
	}
	private: System::Void ckbAutoSearch_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ManagerSettings::_autoSearch = ckbAutoSearch->Checked;
	}
	private: System::Void ckbAutoStart_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ManagerSettings::_startUpWindows = ckbAutoStart->Checked;
	}
	private: System::Void ckbisTopMost_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ManagerSettings::_topMost = ckbisTopMost->Checked;
	}
	private: System::Void ckbcloseIsDone_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ManagerSettings::_minimizeClose = ckbcloseIsDone->Checked;
	}
	private: System::Void Config_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		ckbAutoSearch->Checked = ManagerSettings::_autoSearch;
		ckbAutoStart->Checked = ManagerSettings::_startUpWindows;
		ckbisTopMost->Checked = ManagerSettings::_topMost;
		ckbcloseIsDone->Checked = ManagerSettings::_minimizeClose;
	}
};
}
