/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterGraphicEngineGUI_DX9.h"
#include "PrototypeGUI_DescWindowDX9.h"
#include "MapXML_Field.h"
#include "StorePathResources.h"
#include "BL_Debug.h"

AdapterGraphicEngineGUI_DX9::AdapterGraphicEngineGUI_DX9()
{

}
//------------------------------------------------------------------------
AdapterGraphicEngineGUI_DX9::~AdapterGraphicEngineGUI_DX9()
{
  Destroy();
}
//------------------------------------------------------------------------
bool AdapterGraphicEngineGUI_DX9::AddWindow(TGUIDescWindow* descWindow)
{
  bool res =
  mMyGUI.addWindow(descWindow->hwnd,
                   descWindow->pD3D,
                   descWindow->pD3DDevice,
                   descWindow->pD3DPP,
                   descWindow->windowed);

  //bool res = false;
  TMapXML_Field* pMap = GetStorePathResources();
  int cntGUI = pMap->GetCount("GUI");
  for(int i = 0 ; i < cntGUI ; i++ )
  {
    AddResourceLocation(pMap->GetSecond("GUI",i));
  }
  int cntSkin = pMap->GetCount("GUI_skin");
  for(int i = 0 ; i < cntSkin ; i++ )
  {
    res = 
      MyGUI::ResourceManager::getInstance().load(pMap->GetSecond("GUI_skin",i));// загрузка скина
    BL_ASSERT(res);
  }
  return res;
}
//------------------------------------------------------------------------
void AdapterGraphicEngineGUI_DX9::Render()
{
  mMyGUI.render();
}
//------------------------------------------------------------------------
void AdapterGraphicEngineGUI_DX9::Resize()
{
  mMyGUI._windowResizedPartly();
}
//------------------------------------------------------------------------
void AdapterGraphicEngineGUI_DX9::Destroy()
{
  mMyGUI.destroyPartly();
}
//------------------------------------------------------------------------
void AdapterGraphicEngineGUI_DX9::LostDevice()
{
  mMyGUI.lostDevice();
}
//------------------------------------------------------------------------
void AdapterGraphicEngineGUI_DX9::AddResourceLocation(const std::string& _name, bool _recursive)
{
  mMyGUI.addResourceLocation(mMyGUI.getRootMedia() + _name,_recursive);
}
//------------------------------------------------------------------------
