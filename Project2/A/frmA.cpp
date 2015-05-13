#include "frmA.h"

using namespace System;
using namespace System ::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	A::frmA form;
	Application::Run(%form);
}

