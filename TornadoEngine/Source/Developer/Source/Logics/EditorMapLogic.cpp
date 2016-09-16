/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorMapLogic.h"
#include "ListModules.h"
#include "Logger.h"

#include "ModuleTimer.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"
#include "ModuleSoundEngine.h"

#include "EditorMap.h"

#include <boost/locale/util.hpp>
#include <boost/cstdint.hpp>

TEditorMapLogic::TEditorMapLogic()
{
  mAggregationScenario_Client.reset(new TGP_AggregationScenario_Client);
}
//-------------------------------------------------------------------
TEditorMapLogic::~TEditorMapLogic()
{

}
//-------------------------------------------------------------------
void TEditorMapLogic::StartEvent()
{
  if(mAggregationScenario_Client.get())
  {
    mAggregationScenario_Client->GetCB_Progress()->Register( &TEditorMapLogic::ProgressScenario, this);
    mAggregationScenario_Client->GetCB_End()->Register( &TEditorMapLogic::EndScenario, this);
  }

  CallBackModule(nsListModules::Timer, &TEditorMapLogic::StartTimer);
  CallBackModule(nsListModules::GraphicEngine, &TEditorMapLogic::InitForms);

  mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorMapLogic::FreeGraphicResource,this);
  mComp.pGraphicEngine->GetCBEndWork()->Register( &TEditorMapLogic::GraphicEndWork ,this);
  mComp.pPhysicEngine->GetCBEndWork()->Register( &TEditorMapLogic::PhysicEndWork ,this);
  mComp.pSoundEngine->GetCBEndWork()->Register( &TEditorMapLogic::SoundEndWork ,this);
}
//-------------------------------------------------------------------
void TEditorMapLogic::StopEvent()
{
  mAggregationScenario_Client.reset(NULL);
}
//-------------------------------------------------------------------
void TEditorMapLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("EditorMap");
}
//-------------------------------------------------------------------
bool TEditorMapLogic::WorkClient()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_Logic();
  return true;
}
//-------------------------------------------------------------------
void TEditorMapLogic::Input(int id_sender, void* p, int size)
{
  switch(id_sender)
  {
    case nsListModules::GraphicEngine:
      break;
    case nsListModules::PhysicEngine:
      break;
    case nsListModules::Timer:
      break;
    case nsListModules::FromSomeToLogic:// EditorMap
    {
      //### пока через строку, потом должен быть протокол
      char* pLMP = (char*)p;
      char s[300];
      strncpy(s, pLMP, size);
      s[size] = '\0';
      std::string sNameMap;
      sNameMap = s;
      LoadGameMap(sNameMap);
      //### пока через строку, потом должен быть протокол
    }
      break;
    default:BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------
void TEditorMapLogic::StartTimer()
{
  // вызовется из потока таймера
  unsigned int mID_Timer = mComp.pTimer->New(10);
}
//----------------------------------------------------------
void TEditorMapLogic::InitForms()
{ //mComp.pGraphicEngine->GetGE()->GetWindow()->setFullscreen(true, 1280, 1024);
  mEditorMap = new TEditorMap;
  mEditorMap->Show();

//  char* sMsgUtf8 = "Редактор карт";
//#ifdef WIN32
//  size_t lenMsgUtf8 = strlen(sMsgUtf8);
//  TContainer cUnicode;
//  cUnicode.SetData(NULL, 3*lenMsgUtf8+2);
//  std::auto_ptr<boost::locale::util::base_converter> mConvFrom = 
//    boost::locale::util::create_utf8_converter();
//
//  wchar_t* pUnicode = (wchar_t*)cUnicode.GetPtr();
//  const char* pCurFrom = (const char*)(sMsgUtf8);
//  char* pEndFrom = sMsgUtf8 + lenMsgUtf8;
//  int cntUnicode = 0;
//  while(true)
//  {
//    boost::uint32_t u = mConvFrom->to_unicode(pCurFrom, pEndFrom);
//    pUnicode[cntUnicode] = u;
//    cntUnicode++;
//    int len = pEndFrom - pCurFrom;
//    if( len <= 0 )
//      break;
//  }
//#else
//    wchar_t* pUnicode = (wchar_t*)sMsgUtf8;
//#endif
//  pUnicode[cntUnicode] = L'\0';
//  std::wstring caption = pUnicode;//"Редактор карт";
  mComp.pGraphicEngine->GetGE()->SetWindowCaptionA("Редактор карт");
}
//----------------------------------------------------------
void TEditorMapLogic::PhysicEndWork()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_Bullet();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::GraphicEndWork()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_Ogre();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::SoundEndWork()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_OpenAL();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::FreeGraphicResource()
{
  delete mEditorMap;
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::LoadGameMap(std::string& nameMap)
{
  if(mAggregationScenario_Client.get())
    if(mAggregationScenario_Client->Activate(nsGameProcess::eBuilder))
  {
    mAggregationScenario_Client->Setup( &mUsePattern, &mFBP_EoWM );
    mAggregationScenario_Client->LoadMap(nameMap);
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::ProgressScenario(nsGameProcess::GP_TypeScenario type, int progress)
{
  switch(type)
  {
    case nsGameProcess::eBuilder:
    case nsGameProcess::eDestructor:
      // отрисовка прогресса загрузки или выгрузки
      break;
    case nsGameProcess::eSynchroClient:
      // не должны сюда попасть
      BL_FIX_BUG();
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::EndScenario(nsGameProcess::GP_TypeScenario type)
{
  switch(type)
  {
    case nsGameProcess::eBuilder:
    case nsGameProcess::eDestructor:
      if( mAggregationScenario_Client->Activate(nsGameProcess::eSynchroClient)==false )
      {
        BL_FIX_BUG();
      }
      // ??? вызов из физического потока?
      if(type==nsGameProcess::eBuilder)
        mComp.pPhysicEngine->GetPE()->Setup( mAggregationScenario_Client->GetPhysicWorldID(), 
                                             TPhysicEngine_Bullet::eStatePause );
      // ???
      break;
    case nsGameProcess::eSynchroClient:
      break;
  }
}
//---------------------------------------------------------------------------------------------

