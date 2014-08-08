/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterGUI_DX.h"
#include "PrototypeGraphicEngineGUI.h"

AdapterGUI_DX::AdapterGUI_DX()
{
  mGUI_Realize = NULL;
}
//------------------------------------------------------------------------------------
AdapterGUI_DX::~AdapterGUI_DX()
{

}
//------------------------------------------------------------------------------------
void AdapterGUI_DX::AddResourceLocation(const std::string& _name, bool _recursive )
{
  mGUI_Realize->AddResourceLocation(_name, _recursive );
}
//------------------------------------------------------------------------------------
bool AdapterGUI_DX::AddWindow(TGUIDescWindow* descWindow)
{
  return mGUI_Realize->AddWindow(descWindow);
}
//------------------------------------------------------------------------------------
void AdapterGUI_DX::Render()
{
  mGUI_Realize->Render();
}
//------------------------------------------------------------------------------------
void AdapterGUI_DX::Resize()
{
  mGUI_Realize->Resize();
}
//------------------------------------------------------------------------------------
void AdapterGUI_DX::Destroy()
{
  mGUI_Realize->Destroy();
}
//------------------------------------------------------------------------------------
void AdapterGUI_DX::LostDevice()
{
  mGUI_Realize->LostDevice();
}
//------------------------------------------------------------------------------------
void AdapterGUI_DX::SetGUI_Realize(PrototypeGraphicEngineGUI* p)
{
  mGUI_Realize = p;
}
//------------------------------------------------------------------------------------
