#pragma once
#include <windows.h>
namespace SimpleCleaner {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para ShowMessage
	/// </summary>
	public ref class ShowMessage : public System::Windows::Forms::Form
	{
		int _contador = 5;
	public:
		ShowMessage(String^ text,String^pos,String^neg, int timer)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
			this->TopMost = true;
			this->Text = "";
			this->Name = "";
			lblTitle->Text = text;
			_contador = timer;
			btnDeleteDir->Visible = (String::IsNullOrEmpty(neg)) ? false : true;
			btnAction->Visible = (String::IsNullOrEmpty(pos)) ? false : true;

			btnDeleteDir->Text = neg;
			btnAction->Text = pos;
			MessageBeep(MB_ICONINFORMATION);
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~ShowMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^ btnAction;
	private: System::Windows::Forms::Button^ btnDeleteDir;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblCountDown;

	private: System::Windows::Forms::Timer^ count;
	private: System::ComponentModel::IContainer^ components;
	public:
	protected:


	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnAction = (gcnew System::Windows::Forms::Button());
			this->btnDeleteDir = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblCountDown = (gcnew System::Windows::Forms::Label());
			this->count = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// btnAction
			// 
			this->btnAction->BackColor = System::Drawing::Color::LightGreen;
			this->btnAction->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAction->FlatAppearance->BorderSize = 0;
			this->btnAction->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAction->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAction->ForeColor = System::Drawing::Color::Black;
			this->btnAction->Location = System::Drawing::Point(493, 236);
			this->btnAction->Name = L"btnAction";
			this->btnAction->Size = System::Drawing::Size(98, 31);
			this->btnAction->TabIndex = 6;
			this->btnAction->Text = L"Aplicar";
			this->btnAction->UseVisualStyleBackColor = false;
			this->btnAction->Click += gcnew System::EventHandler(this, &ShowMessage::btnAction_Click);
			// 
			// btnDeleteDir
			// 
			this->btnDeleteDir->BackColor = System::Drawing::Color::IndianRed;
			this->btnDeleteDir->Enabled = false;
			this->btnDeleteDir->FlatAppearance->BorderSize = 0;
			this->btnDeleteDir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteDir->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeleteDir->ForeColor = System::Drawing::Color::Black;
			this->btnDeleteDir->Location = System::Drawing::Point(12, 237);
			this->btnDeleteDir->Name = L"btnDeleteDir";
			this->btnDeleteDir->Size = System::Drawing::Size(98, 31);
			this->btnDeleteDir->TabIndex = 7;
			this->btnDeleteDir->Text = L"Apagar";
			this->btnDeleteDir->UseVisualStyleBackColor = false;
			this->btnDeleteDir->Click += gcnew System::EventHandler(this, &ShowMessage::btnDeleteDir_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(12, 9);
			this->lblTitle->MaximumSize = System::Drawing::Size(579, 224);
			this->lblTitle->MinimumSize = System::Drawing::Size(579, 224);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(579, 224);
			this->lblTitle->TabIndex = 8;
			this->lblTitle->Text = L"Não foi possivel gerar log";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblCountDown
			// 
			this->lblCountDown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblCountDown->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCountDown->Location = System::Drawing::Point(116, 236);
			this->lblCountDown->Name = L"lblCountDown";
			this->lblCountDown->Size = System::Drawing::Size(371, 32);
			this->lblCountDown->TabIndex = 9;
			this->lblCountDown->Text = L"fechando em 2s";
			this->lblCountDown->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// count
			// 
			this->count->Enabled = true;
			this->count->Interval = 500;
			this->count->Tick += gcnew System::EventHandler(this, &ShowMessage::count_Tick);
			// 
			// ShowMessage
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(603, 279);
			this->Controls->Add(this->lblCountDown);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->btnDeleteDir);
			this->Controls->Add(this->btnAction);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(603, 279);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(603, 279);
			this->Name = L"ShowMessage";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"ShowMessage";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAction_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
	private: System::Void btnDeleteDir_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

		   int identifi = 1000;
	private: System::Void count_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (identifi >= 0) {
			identifi -= 500;
			if (identifi <= 0) {
				identifi = 1000;
				_contador -= 1;
			}
		}

		lblCountDown->Text = "Fechando em " + _contador + "s";

		if (_contador <= 0) {
			delete this;
		}
	}
};
}
