/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GUI_Class.h"

#include "GUI_DescWindow.h"


TGUI_Class::TGUI_Class()
{

}
//------------------------------------------------------------------------
TGUI_Class::~TGUI_Class()
{
  Destroy();
}
//------------------------------------------------------------------------
bool TGUI_Class::AddWindow(TGUIDescWindow* descWindow)
{
  bool res =
#ifdef WIN32
  mMyGUI.addWindow(descWindow->hwnd,
                   descWindow->pD3D,
                   descWindow->pD3DDevice,
                   descWindow->pD3DPP,
                   descWindow->windowed);
#else // MacOS
#endif
  return res;
}
//------------------------------------------------------------------------
void TGUI_Class::Render()
{
  mMyGUI.render();
}
//------------------------------------------------------------------------
void TGUI_Class::Resize()
{
  mMyGUI._windowResizedPartly();
}
//------------------------------------------------------------------------
void TGUI_Class::Destroy()
{
  mMyGUI.destroyPartly();
}
//------------------------------------------------------------------------
void TGUI_Class::LostDevice()
{
  mMyGUI.lostDevice();
}
//------------------------------------------------------------------------
void TGUI_Class::AddResourceLocation(const std::string& _name, bool _recursive)
{
  mMyGUI.addResourceLocation(mMyGUI.getRootMedia() + _name,_recursive);
}
//------------------------------------------------------------------------
