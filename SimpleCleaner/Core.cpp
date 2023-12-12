#include "Core.h"

using namespace System::Windows::Forms;
using namespace System;

[STAThreadAttribute]
void main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SimpleCleaner::Core form;
	Application::Run(% form);
}