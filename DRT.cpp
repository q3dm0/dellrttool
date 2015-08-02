//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DRT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
RegisterHotKey(Form1->Handle,12,2,VK_F1);
Form1->Hide();
ShowWindow(Handle,SW_HIDE);
ShowWindow(Application->Handle,SW_HIDE);
}

//---------------------------------------------------------------------------

bool ctrl;
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key == VK_F1){
ctrl=true;
}
if (Key == 'F1' && ctrl)
{
DEVMODE dm;
ZeroMemory(&dm, sizeof(dm));
dm.dmSize = sizeof(dm);
if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
{
DWORD dwTemp = dm.dmPelsHeight;
dm.dmPelsHeight= dm.dmPelsWidth;
dm.dmPelsWidth = dwTemp;
switch (dm.dmDisplayOrientation)
{
case DMDO_DEFAULT:
dm.dmDisplayOrientation = DMDO_270;
break;
case DMDO_270:
dm.dmDisplayOrientation = DMDO_180;
break;
case DMDO_180:
dm.dmDisplayOrientation = DMDO_90;
break;
case DMDO_90:
dm.dmDisplayOrientation = DMDO_DEFAULT;
break;
default:
break;
}
long lRet = ChangeDisplaySettings(&dm, 0);
if (DISP_CHANGE_SUCCESSFUL != lRet)
{
}
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key == VK_F1){
ctrl=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrayIcon1DblClick(TObject *Sender)
{
Form1->Visible = true;
Application->Restore();
Form1->FormStyle = fsStayOnTop;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
TrayIcon1->Visible = true;
ShowWindow(Form1->Handle, SW_HIDE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Message(tagMSG &Msg, bool &Handled)
{
if (Msg.message == WM_HOTKEY)
{
if (Msg.wParam == 12)
{
DEVMODE dm;
ZeroMemory(&dm, sizeof(dm));
dm.dmSize = sizeof(dm);
if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
{
DWORD dwTemp = dm.dmPelsHeight;
dm.dmPelsHeight= dm.dmPelsWidth;
dm.dmPelsWidth = dwTemp;
switch (dm.dmDisplayOrientation)
{
case DMDO_DEFAULT:
dm.dmDisplayOrientation = DMDO_270;
break;
case DMDO_270:
dm.dmDisplayOrientation = DMDO_180;
break;
case DMDO_180:
dm.dmDisplayOrientation = DMDO_90;
break;
case DMDO_90:
dm.dmDisplayOrientation = DMDO_DEFAULT;
break;
default:
break;
}
long lRet = ChangeDisplaySettings(&dm, 0);
if (DISP_CHANGE_SUCCESSFUL != lRet)
{
}
}
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Minimize(TObject *Sender)
{
Application->Minimize();
Form1->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
TrayIcon1->Visible = true;
ShowWindow(Form1->Handle, SW_SHOW);
}
//---------------------------------------------------------------------------

