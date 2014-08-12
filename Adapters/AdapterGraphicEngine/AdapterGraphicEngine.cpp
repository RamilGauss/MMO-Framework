/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterGraphicEngine.h"
#include "DstEvent.h"
#include "GraphicEngine.h"
#include "AdapterCamera.h"
#include "AdapterControlCamera.h"
#include "IBaseObjectGE.h"
#include "DescEvent.h"
#include "AdapterGUI_DX.h"
#include "AdapterGraphicEngineObject.h"
#include "ShareMisc.h"

#include <boost\foreach.hpp>

AdapterGraphicEngine::AdapterGraphicEngine()
{
  GetLogger()->Register(STR_NAME_GE);

  mGraphicEngine.reset(new TGraphicEngine);
  mCamera.reset(new AdapterCamera);
  mCCamera.reset(new AdapterControlCamera);
  mGUI_DX.reset(new AdapterGUI_DX);

  mGraphicEngine->SetDstObject(this);
  mGraphicEngine->SetSelfID(ID_GraphicEngine);
}
//-----------------------------------------------------------------------------------------
AdapterGraphicEngine::~AdapterGraphicEngine()
{

}
//-----------------------------------------------------------------------------------------
AdapterGraphicEngine::typeRender AdapterGraphicEngine::GetTypeRender()
{
  return PrototypeGraphicEngine::DX9;
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetGUI(PrototypeGraphicEngineGUI* pGUI)
{
  mGUI_DX->SetGUI_Realize(pGUI);
  mGraphicEngine->SetGUI(mGUI_DX.get());
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::ZeroGUI()
{
  mGUI_DX->SetGUI_Realize(NULL);
  mGraphicEngine->ZeroGUI();
}
//------------------------------------------------------------------------
PrototypeCamera* AdapterGraphicEngine::GetCamera()
{
  TCamera* pCamera = mGraphicEngine->GetCamera();
  mCamera->SetPtr(pCamera);
  return mCamera.get();
}
//-----------------------------------------------------------------------------------------
PrototypeControlCamera* AdapterGraphicEngine::GetControlCamera()
{
  TControlCamera* pCCamera = mGraphicEngine->GetControlCamera();
  mCCamera->SetPtr(pCCamera);
  return mCCamera.get();
}
//-----------------------------------------------------------------------------------------
bool AdapterGraphicEngine::IsFullScreen()
{
  return mGraphicEngine->IsFullScreen();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::ToggleFullScreen()
{
  mGraphicEngine->ToggleFullScreen();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetTitleWindow(const char* sTitle)
{
  mGraphicEngine->SetTitleWindow(sTitle);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::Init()
{
  mGraphicEngine->Init();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetTimeAnimate(unsigned int time_ms)
{
  mGraphicEngine->SetTimeAnimate(time_ms);
}
//-----------------------------------------------------------------------------------------
bool AdapterGraphicEngine::HandleInternalEvent()
{
  return mGraphicEngine->HandleInternalEvent();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::Done()
{
  mGraphicEngine->Done();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::GetResolutionFrame(int& h, int& w )
{
  mGraphicEngine->GetResolutionFrame( h, w);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetResolutionFrame(int  h, int  w )
{
  mGraphicEngine->SetResolutionFrame( h, w );
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::AddObject(IBaseObjectGE* pObject)
{
  TSmartPtrAdapterGEObject smartPtrObject(new AdapterGraphicEngineObject);
  mListObjectGE.push_back(smartPtrObject);
  AdapterGraphicEngineObject* pObjectGE = smartPtrObject.get();

  pObjectGE->SetGameObject(pObject);
  mGraphicEngine->AddObject(pObjectGE);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::Clear()
{
  mGraphicEngine->Clear();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetEffect(unsigned short id_effect/*уникальный эффект, см. таблицу эффектов*/,
  nsMathTools::TVector3* coord3,     // где
  nsMathTools::TVector3* orient3,    // ориентация эффекта
  unsigned int time_past/* прошло времени, мс*/)
{
  mGraphicEngine->SetEffect(id_effect, coord3, orient3, time_past);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetViewFPS(bool val)
{
  mGraphicEngine->SetViewFPS(val);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetLightEnable(int index, bool v)
{
  mGraphicEngine->SetLightEnable(index, v);
}
//-----------------------------------------------------------------------------------------
bool AdapterGraphicEngine::GetLightEnable(int index)
{
  return mGraphicEngine->GetLightEnable(index);
}
//-----------------------------------------------------------------------------------------
int AdapterGraphicEngine::GetCountAllLight()
{
  return mGraphicEngine->GetCountAllLight();
}
//-----------------------------------------------------------------------------------------
const nsMathTools::TVector3* AdapterGraphicEngine::GetLightPosition(int index)
{
  return mGraphicEngine->GetLightPosition(index);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetLightPosition(int index,nsMathTools::TVector3* m3)
{
  mGraphicEngine->SetLightPosition(index,m3);
}
//-----------------------------------------------------------------------------------------
const nsMathTools::TVector3* AdapterGraphicEngine::GetLightColor(int index)
{
  return mGraphicEngine->GetLightColor(index);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetLightColor(int index, nsMathTools::TVector3* color)
{
  mGraphicEngine->SetLightColor(index, color);
}
//-----------------------------------------------------------------------------------------
bool AdapterGraphicEngine::GetPostEffectMirror()
{
  return mGraphicEngine->GetPostEffectMirror();
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::SetPostEffectMirror(bool v)
{
  mGraphicEngine->SetPostEffectMirror(v);
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::Resize()
{
  mGraphicEngine->Resize();
}
//-----------------------------------------------------------------------------------------
int AdapterGraphicEngine::GetVersionAdapter()
{
  return 1;
}
//-----------------------------------------------------------------------------------------
PrototypeBaseModule* AdapterGraphicEngine::NewExample()
{
  return new AdapterGraphicEngine;
}
//-----------------------------------------------------------------------------------------
void AdapterGraphicEngine::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//-----------------------------------------------------------------------------------------
bool AdapterGraphicEngine::Work()
{
  //дать квант времени графике и транслировать события графического движка в игровой движок
  RET_FALSE(mGraphicEngine->HandleInternalEvent());
  bool res = mGraphicEngine->Work();

  nsEvent::TEvent* pEvent = GetEvent();
  while(pEvent)
  {
    // трансляция события
    AddEventCopy(pEvent->pContainer->GetPtr(), pEvent->pContainer->GetSize(), pEvent->time_ms);
    delete pEvent;
    pEvent = GetEvent();
  }

  return res;
}
//-----------------------------------------------------------------------------------------
