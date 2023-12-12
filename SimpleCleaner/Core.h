#pragma once
#include "Registro.h"
#include "AddKey.h"
#include "Home.h"
#include "Config.h"
#include "About.h"
#include "FileManager.h"
#include <Windows.h>

namespace SimpleCleaner {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Sumário para Core
	/// </summary>
	/// 
	/// 

	public ref class Core : public System::Windows::Forms::Form
	{
		Registro reg;

		AddKey^ FrmAddScreen = nullptr;
		Config^ Frmconfig = nullptr;
		About^ FrmAboutSe = nullptr;
		Home^ FrmHomeScreen = nullptr;

		bool dragging;
		System::Drawing::Point offset;

	private: System::Windows::Forms::Panel^ pnlBorder;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnMinimize;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Button^ btnDefine;
	private: System::Windows::Forms::NotifyIcon^ Notifi_icon;
	private: System::Windows::Forms::ContextMenuStrip^ cmsMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmSair;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmShow;
	private: System::Windows::Forms::Label^ lblCountElements;
	private: System::Windows::Forms::ImageList^ Assets;
	private: System::Windows::Forms::Timer^ tmCountElement;
		   

	public:
		Core(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
			lblTitle->Text = this->Text;

			if(!reg.Get_First_Use_status())
			{
				reg.addDirectoryToRegistry("C:\\Windows\\Temp", true);
				reg.addDirectoryToRegistry("C:\\Users\\luyfe\\AppData\\Local\\Temp", true);
				reg.addDirectoryToRegistry("c:\\Windows\\Prefetch", true);
				reg.addDirectoryToRegistry("%WINDIR%\\SoftwareDistribution\\Download", true);
				reg.addDirectoryToRegistry("%WINDIR%\\Fonts\\cache", true);
				reg.addDirectoryToRegistry("%LOCALAPPDATA%\\Microsoft\\Windows\\Explorer", true);
				reg.addDirectoryToRegistry("%LOCALAPPDATA%\\Microsoft\\Windows\\INetCache", true);
				
				reg.Set_First_Use(true);
				StaticClass::Logger::LogInfo("Diretorio padrão aplicado");
			}

		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~Core()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Conteiner;
	private: System::Windows::Forms::Button^ btnHome;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::IContainer^ components;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Core::typeid));
			this->Conteiner = (gcnew System::Windows::Forms::Panel());
			this->btnHome = (gcnew System::Windows::Forms::Button());
			this->Assets = (gcnew System::Windows::Forms::ImageList(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pnlBorder = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnMinimize = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnDefine = (gcnew System::Windows::Forms::Button());
			this->Notifi_icon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->cmsMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmShow = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmSair = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblCountElements = (gcnew System::Windows::Forms::Label());
			this->tmCountElement = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlBorder->SuspendLayout();
			this->cmsMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// Conteiner
			// 
			this->Conteiner->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Conteiner->Location = System::Drawing::Point(250, 65);
			this->Conteiner->Margin = System::Windows::Forms::Padding(4);
			this->Conteiner->Name = L"Conteiner";
			this->Conteiner->Size = System::Drawing::Size(457, 497);
			this->Conteiner->TabIndex = 0;
			// 
			// btnHome
			// 
			this->btnHome->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnHome->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHome->FlatAppearance->BorderSize = 0;
			this->btnHome->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHome->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHome->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnHome->ImageIndex = 2;
			this->btnHome->ImageList = this->Assets;
			this->btnHome->Location = System::Drawing::Point(13, 65);
			this->btnHome->Margin = System::Windows::Forms::Padding(4);
			this->btnHome->Name = L"btnHome";
			this->btnHome->Size = System::Drawing::Size(229, 52);
			this->btnHome->TabIndex = 1;
			this->btnHome->Text = L"Inicio";
			this->btnHome->UseVisualStyleBackColor = false;
			this->btnHome->Click += gcnew System::EventHandler(this, &Core::btnHome_Click);
			// 
			// Assets
			// 
			this->Assets->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"Assets.ImageStream")));
			this->Assets->TransparentColor = System::Drawing::Color::Transparent;
			this->Assets->Images->SetKeyName(0, L"settings.png");
			this->Assets->Images->SetKeyName(1, L"folder.png");
			this->Assets->Images->SetKeyName(2, L"home.png");
			this->Assets->Images->SetKeyName(3, L"information.png");
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->ImageIndex = 1;
			this->button1->ImageList = this->Assets;
			this->button1->Location = System::Drawing::Point(13, 125);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(229, 52);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Adicionar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Core::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->ImageIndex = 3;
			this->button2->ImageList = this->Assets;
			this->button2->Location = System::Drawing::Point(13, 185);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(229, 52);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Sobre";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Core::button2_Click);
			// 
			// pnlBorder
			// 
			this->pnlBorder->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->pnlBorder->Controls->Add(this->lblTitle);
			this->pnlBorder->Controls->Add(this->btnMinimize);
			this->pnlBorder->Controls->Add(this->btnClose);
			this->pnlBorder->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pnlBorder->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlBorder->Location = System::Drawing::Point(0, 0);
			this->pnlBorder->Name = L"pnlBorder";
			this->pnlBorder->Size = System::Drawing::Size(720, 42);
			this->pnlBorder->TabIndex = 4;
			this->pnlBorder->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Core::pnlBorder_MouseDown);
			this->pnlBorder->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Core::pnlBorder_MouseMove);
			this->pnlBorder->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Core::pnlBorder_MouseUp);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(13, 9);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(142, 22);
			this->lblTitle->TabIndex = 7;
			this->lblTitle->Text = L"012345678910";
			this->lblTitle->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Core::pnlBorder_MouseDown);
			this->lblTitle->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Core::pnlBorder_MouseMove);
			this->lblTitle->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Core::pnlBorder_MouseUp);
			// 
			// btnMinimize
			// 
			this->btnMinimize->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnMinimize->FlatAppearance->BorderSize = 0;
			this->btnMinimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMinimize->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMinimize->Location = System::Drawing::Point(595, 4);
			this->btnMinimize->Margin = System::Windows::Forms::Padding(4);
			this->btnMinimize->Name = L"btnMinimize";
			this->btnMinimize->Size = System::Drawing::Size(52, 34);
			this->btnMinimize->TabIndex = 6;
			this->btnMinimize->Text = L"-";
			this->btnMinimize->UseVisualStyleBackColor = false;
			this->btnMinimize->Click += gcnew System::EventHandler(this, &Core::btnMinimize_Click);
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClose->Location = System::Drawing::Point(655, 4);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(52, 34);
			this->btnClose->TabIndex = 5;
			this->btnClose->Text = L"X";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Core::btnClose_Click);
			// 
			// btnDefine
			// 
			this->btnDefine->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnDefine->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDefine->FlatAppearance->BorderSize = 0;
			this->btnDefine->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDefine->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDefine->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDefine->ImageIndex = 0;
			this->btnDefine->ImageList = this->Assets;
			this->btnDefine->Location = System::Drawing::Point(13, 510);
			this->btnDefine->Margin = System::Windows::Forms::Padding(4);
			this->btnDefine->Name = L"btnDefine";
			this->btnDefine->Size = System::Drawing::Size(229, 52);
			this->btnDefine->TabIndex = 5;
			this->btnDefine->Text = L"Configurações";
			this->btnDefine->UseVisualStyleBackColor = false;
			this->btnDefine->Click += gcnew System::EventHandler(this, &Core::btnDefine_Click);
			// 
			// Notifi_icon
			// 
			this->Notifi_icon->ContextMenuStrip = this->cmsMenu;
			this->Notifi_icon->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"Notifi_icon.Icon")));
			this->Notifi_icon->Text = L"Simple Cleaner";
			this->Notifi_icon->Visible = true;
			// 
			// cmsMenu
			// 
			this->cmsMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tsmShow, this->tsmSair });
			this->cmsMenu->Name = L"cmsMenu";
			this->cmsMenu->Size = System::Drawing::Size(104, 48);
			// 
			// tsmShow
			// 
			this->tsmShow->Name = L"tsmShow";
			this->tsmShow->Size = System::Drawing::Size(103, 22);
			this->tsmShow->Text = L"Exibir";
			this->tsmShow->Click += gcnew System::EventHandler(this, &Core::tsmShow_Click);
			// 
			// tsmSair
			// 
			this->tsmSair->Name = L"tsmSair";
			this->tsmSair->Size = System::Drawing::Size(103, 22);
			this->tsmSair->Text = L"Sair";
			this->tsmSair->ToolTipText = L"Encerrar o Simple Cleaner";
			this->tsmSair->Click += gcnew System::EventHandler(this, &Core::tsmSair_Click);
			// 
			// lblCountElements
			// 
			this->lblCountElements->AutoSize = true;
			this->lblCountElements->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblCountElements->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCountElements->LiveSetting = System::Windows::Forms::Automation::AutomationLiveSetting::Polite;
			this->lblCountElements->Location = System::Drawing::Point(685, 520);
			this->lblCountElements->Name = L"lblCountElements";
			this->lblCountElements->Size = System::Drawing::Size(52, 75);
			this->lblCountElements->TabIndex = 6;
			this->lblCountElements->Text = L".";
			// 
			// tmCountElement
			// 
			this->tmCountElement->Enabled = true;
			this->tmCountElement->Tick += gcnew System::EventHandler(this, &Core::tmCountElement_Tick);
			// 
			// Core
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(720, 587);
			this->Controls->Add(this->Conteiner);
			this->Controls->Add(this->lblCountElements);
			this->Controls->Add(this->btnDefine);
			this->Controls->Add(this->pnlBorder);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnHome);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(720, 587);
			this->MinimumSize = System::Drawing::Size(720, 587);
			this->Name = L"Core";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Simple Cleaner";
			this->Load += gcnew System::EventHandler(this, &Core::Core_Load);
			this->pnlBorder->ResumeLayout(false);
			this->pnlBorder->PerformLayout();
			this->cmsMenu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void Core_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{
			Stream^ meuStream = gcnew FileStream("define.bin", FileMode::Open);
			StaticClass::ReadData(meuStream);
			meuStream->Close();

			this->TopMost = ManagerSettings::_topMost;
			
			if (ManagerSettings::_startUpWindows) {
				StaticClass::AdicionarAoInicioDoWindows();
				StaticClass::Logger::LogInfo("Iniciar com o windows ativado");
			}
			else {
				StaticClass::RemoverDoInicioDoWindows();
				StaticClass::Logger::LogInfo("Iniciar com o windows desativado");
			}
				
		}
		catch (Exception^ ex)
		{
			StaticClass::Logger::LogError(ex->Message);
		}
		btnHome_Click(sender, e);
	}
		  //Add
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//Conteiner->Controls->Remove(HomeScreen);
		if (FrmHomeScreen != nullptr) {
			FrmHomeScreen->Visible = false;
		}
		if (Frmconfig != nullptr) {
			Frmconfig->Visible = false;
		}
		if (FrmAboutSe != nullptr) {
			FrmAboutSe->Visible = false;
		}
		//delete HomeScreen;

		if (FrmAddScreen == nullptr) {
			FrmAddScreen = gcnew AddKey();
			FrmAddScreen->Dock = DockStyle::Fill;
			Conteiner->Controls->Add(FrmAddScreen);
		}
		else {
			FrmAddScreen->Visible = true;
		}

		lblTitle->Text = this->Text + " - Gerenciar diretório";
		Conteiner->Refresh();

	}


	private: System::Void btnHome_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//Conteiner->Controls->Remove(AddScreen);
		if (FrmAddScreen != nullptr) {
			FrmAddScreen->Visible = false;
		}
		if (Frmconfig != nullptr) {
			Frmconfig->Visible = false;
		}
		if (FrmAboutSe != nullptr) {
			FrmAboutSe->Visible = false;
		}
		//delete AddScreen;

		if (FrmHomeScreen == nullptr) {
			FrmHomeScreen = gcnew Home();
			FrmHomeScreen->Dock = DockStyle::Fill;

			Conteiner->Controls->Add(FrmHomeScreen);
		}
		else {
			FrmHomeScreen->Visible = true;
		}
		lblTitle->Text = this->Text + " - Inicio";
		Conteiner->Refresh();

	}
		   //about
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (FrmAddScreen != nullptr) {
			FrmAddScreen->Visible = false;
		}
		if (Frmconfig != nullptr) {
			Frmconfig->Visible = false;
		}
		if (FrmHomeScreen != nullptr) {
			FrmHomeScreen->Visible = false;
		}
		if (FrmAboutSe == nullptr) {
			FrmAboutSe = gcnew About(StaticClass::aboutThis);
			FrmAboutSe->Dock = DockStyle::Fill;

			Conteiner->Controls->Add(FrmAboutSe);
		}
		else {
			FrmAboutSe->Visible = true;
		}
		lblTitle->Text = this->Text + " - Sobre";
		Conteiner->Refresh();

	}
	private: System::Void pnlBorder_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}	
	private: System::Void pnlBorder_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		if (dragging)
		{
			System::Drawing::Point s = System::Drawing::Point(e->X, e->Y);
			System::Drawing::Point CurrentScreenPosition = PointToScreen(s);

			// Criar um novo objeto Point com as coordenadas ajustadas
			System::Drawing::Point newLocation(CurrentScreenPosition.X - offset.X, CurrentScreenPosition.Y - offset.Y);

			// Atribuir o novo objeto Point à propriedade Location
			this->Location = newLocation;
		}
	}
	private: System::Void pnlBorder_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		dragging = false;
	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (!ManagerSettings::_minimizeClose) {
			exit(0);
		}
		else {
			OnMinimize();
		}
	}
	private: System::Void btnDefine_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (FrmAddScreen != nullptr) {
			FrmAddScreen->Visible = false;
		}
		if (FrmHomeScreen != nullptr) {
			FrmHomeScreen->Visible = false;
		}
		if (FrmAboutSe != nullptr) {
			FrmAboutSe->Visible = false;
		}

		if (Frmconfig == nullptr) {
			Frmconfig = gcnew Config();
			Frmconfig-> Dock = DockStyle::Fill;

			Conteiner->Controls->Add(Frmconfig);
		}
		else {
			Frmconfig->Visible = true;
		}
		
		lblTitle->Text = this->Text + " - Configurações";
		Conteiner->Refresh();
	}
	private: System::Void tsmSair_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		exit(0);
	}
	private: System::Void tsmShow_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HANDLE hThread = GetCurrentThread();
		int newPriority = THREAD_PRIORITY_NORMAL;
		
		if (!SetThreadPriority(hThread, newPriority)) {
			// Lidere com o erro, se necessário
			// Por exemplo, exiba uma mensagem de erro ou registre o problema
			StaticClass::Logger::LogInfo("Prioridade normal");
		}
		this->WindowState == FormWindowState::Normal;
		this->ShowIcon = true;
		this->ShowInTaskbar = true;
		this->Focus();
	}
		   int vll = 1000;
	private: System::Void tmCountElement_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		
		if (this->Focused) {
			vll -= 100;
			if (vll <= 0) {
				vll = 1000;
				lblCountElements->ForeColor = Color::Red;
			}
			else {
				lblCountElements->ForeColor = Color::Green;
			}
		}
		else {
			lblCountElements->ForeColor = Color::Yellow;
		}
		
		//lblCountElements->Text = Conteiner->Controls->Count.ToString();
	}
	public: System::Void OnMinimize() {

		this->ShowIcon = false;
		this->ShowInTaskbar = false;
		this->WindowState = FormWindowState::Minimized;
		Notifi_icon->ShowBalloonTip(2, "SimpleCleaner", "Ainda estou executando em segundo plano", ToolTipIcon::Info);

		HANDLE hThread = GetCurrentThread();
		int newPriority = THREAD_PRIORITY_LOWEST;

		if (!SetThreadPriority(hThread, newPriority)) {
			// Lidere com o erro, se necessário
			// Por exemplo, exiba uma mensagem de erro ou registre o problema
			StaticClass::Logger::LogInfo("Prioridade LOWEST");
		}
	}
	private: System::Void btnMinimize_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		OnMinimize();
	}
};
}
