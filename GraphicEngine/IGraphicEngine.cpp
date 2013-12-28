/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGraphicEngine.h"
#include "HiTimer.h"
#include "IGUI_Core.h"

using namespace std;

//------------------------------------------------------------------------
IGraphicEngine::IGraphicEngine(ICamera* pCamera)
{
  mICamera = pCamera;
  ZeroGUI();
  SetIsCreateWindow(false);
}
//------------------------------------------------------------------------
IGraphicEngine::~IGraphicEngine()
{

}
//------------------------------------------------------------------------
void IGraphicEngine::LostDeviceGUI()
{
  if(mGUI)
    mGUI->LostDevice();
}
//------------------------------------------------------------------------
void IGraphicEngine::ResizeGUI()
{
  if(mGUI)
    mGUI->Resize();
}
//------------------------------------------------------------------------
void IGraphicEngine::RenderGUI()
{
  if(mGUI)
    mGUI->Render();
}
//------------------------------------------------------------------------
void IGraphicEngine::SetGUI(IGUI_Core* pGUI)
{
  mGUI = pGUI;
  if(IsCreateWindow())// иначе вызовется в Init()
    InitGUI();
}
//------------------------------------------------------------------------
void IGraphicEngine::ZeroGUI()
{
  mGUI = NULL;
}
//------------------------------------------------------------------------
