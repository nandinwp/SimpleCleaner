#pragma once
#include "AddKey.h"
#include "StaticClass.h"
#include "Registro.h"


namespace SimpleCleaner {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::UserControl
	{
		Registro rg;
	public:
		Home(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
			if (ManagerSettings::_autoSearch) {

				Varrer();

				if (btnClear->Visible) {
					Clear();
					StaticClass::Logger::LogInfo("Auto varredura realizado com sucesso!");
				}
				else {
					StaticClass::Logger::LogInfo("Auto varredura realizada, nada para limpar");
				}
			}

		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Button^ btnAction;
	private: System::Windows::Forms::Label^ lblTotalSize;
	private: System::Windows::Forms::Button^ btnClear;

	protected:

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
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnAction = (gcnew System::Windows::Forms::Button());
			this->lblTotalSize = (gcnew System::Windows::Forms::Label());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitle
			// 
			this->lblTitle->BackColor = System::Drawing::SystemColors::ControlLight;
			this->lblTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(0, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(441, 34);
			this->lblTitle->TabIndex = 3;
			this->lblTitle->Text = L"Bem-vindo ao Simple Cleaner";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnAction
			// 
			this->btnAction->BackColor = System::Drawing::Color::LightGreen;
			this->btnAction->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAction->FlatAppearance->BorderSize = 0;
			this->btnAction->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAction->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAction->Location = System::Drawing::Point(327, 436);
			this->btnAction->Name = L"btnAction";
			this->btnAction->Size = System::Drawing::Size(98, 31);
			this->btnAction->TabIndex = 4;
			this->btnAction->Text = L"Varrer";
			this->btnAction->UseVisualStyleBackColor = false;
			this->btnAction->Click += gcnew System::EventHandler(this, &Home::btnAction_Click);
			// 
			// lblTotalSize
			// 
			this->lblTotalSize->AutoSize = true;
			this->lblTotalSize->Location = System::Drawing::Point(15, 50);
			this->lblTotalSize->Name = L"lblTotalSize";
			this->lblTotalSize->Size = System::Drawing::Size(134, 13);
			this->lblTotalSize->TabIndex = 5;
			this->lblTotalSize->Text = L"Nenhum arquivo verificado";
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::LightGreen;
			this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(223, 436);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(98, 31);
			this->btnClear->TabIndex = 6;
			this->btnClear->Text = L"Limpar";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Visible = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &Home::btnClear_Click);
			// 
			// Home
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->lblTotalSize);
			this->Controls->Add(this->btnAction);
			this->Controls->Add(this->lblTitle);
			this->Name = L"Home";
			this->Size = System::Drawing::Size(441, 479);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnAction_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (rg.IsRunAsAdmin()) 
		{
			Varrer();
		}
		else {
			StaticClass::Show("Você precisa executar este programa como administrador!", "", "Ok", 5);
		}
	}
	public:System::Void Varrer() {
			   char** directories;
			   char** tagItem;
			   int count;
			   this->Cursor = System::Windows::Forms::Cursors::WaitCursor;

			   StaticClass::getDirectoriesFromRegistry(&directories, &count, &tagItem);
			   List<String^>^ totalDir = gcnew List<String^>();


			   for (int i = 0; i < count; i++) {
				   String^ Value;
				   Value = gcnew String(StaticClass::getValuesFromRegistry(directories[i]));
				   totalDir->Add(Value);
			   }

			   double values;
			   String^ result =
				   StaticClass::ConvertSize(
					   StaticClass::TotalSizeListaDiretorios(totalDir),
					   values
				   );

			   cli::array<wchar_t>^ separator = { ' ' };
			   cli::array<String^>^ parts = result->Split(separator, StringSplitOptions::RemoveEmptyEntries);

			   String^ OnlyValue = parts[0];
			   String^ OnlyType = parts[1];

			   result = String::Format("{0:0.00}", Double::Parse(OnlyValue));

			   lblTotalSize->Text = "Tamanho total de lixo: " + (result + OnlyType);

			   if (values < 0.10) {
				   lblTotalSize->Text = "Tudo limpo por aqui!";
			   }

			   // Liberar memória alocada
			   for (int i = 0; i < count; i++) {
				   free(directories[i]);
				   free(tagItem[i]);
			   }
			   free(directories);
			   free(tagItem);

			   this->Cursor = System::Windows::Forms::Cursors::Default;
			   if (values > 0) {
				   btnClear->Visible = true;
			   }
			   else {
				   btnClear->Visible = false;
			   }
		   }
	public: System::Void Clear() {
		char** directories;
		char** tagItem;
		int count;
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;

		StaticClass::getDirectoriesFromRegistry(&directories, &count, &tagItem);

		for (int i = 0; i < count; i++) {
			String^ Value;
			Value = gcnew String(StaticClass::getValuesFromRegistry(directories[i]));
			StaticClass::DeleteDirectory(Value);
		}
		//Liberar memória alocada
		for (int i = 0; i < count; i++) {
			free(directories[i]);
			free(tagItem[i]);
		}
		free(directories);
		free(tagItem);

		btnClear->Visible = false;
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (rg.IsRunAsAdmin()) {
			Clear();

		}
		else {
			StaticClass::Show("Você precisa executar este programa como administrador!", "", "Ok", 5);
		}
	}
};
}

