/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <string.h>

#include "ClientDeveloperTool_ViewerModel.h"
#include "MakerObjectCommon.h"
#include "../GameLib/IClientDeveloperTool.h"
#include "../GameLib/IManagerObjectCommon.h"
#include "../GraphicEngine/IGraphicEngine.h"
#include "../GameLib/IBaseObjectCommon.h"
#include "../GUI/IGUI.h"
#include "Logger.h"
#include "HiTimer.h"
#include "../GameLib/NameSrcEventID.h"
#include "../GameLib/IManagerStateMachine.h"
#include "IControlCamera.h"
#include "IXML.h"
#include "Client.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"

using namespace std;
using namespace nsStruct3D;
using namespace nsEvent;
using namespace nsMMOEngine;
using namespace nsKey;

#define LOG_TIME_LOAD_EDITOR_MODEL

#define DELTA_MOVE 0.2f //0.4f
#define DELTA_ROTATE 0.01f
#define ASPECT_MOUSE_X 0.002f
#define ASPECT_MOUSE_Y 0.002f

#define UP 1000000

TClientDeveloperTool_ViewerModel::TClientDeveloperTool_ViewerModel()
{
  flgDragCamera = false;

  mMakerObjectCommon = new TMakerObjectCommon;
  
  mIndexCurObj = 0;
}
//------------------------------------------------------------------------------------
TClientDeveloperTool_ViewerModel::~TClientDeveloperTool_ViewerModel()
{
  delete mMakerObjectCommon;
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::Event(nsEvent::TEvent* pEvent)
{
	switch(pEvent->from)
	{
		case ID_SRC_EVENT_NETWORK_ENGINE:
			break;
		case ID_SRC_EVENT_PHYSIC_ENGINE:
			break;
		case ID_SRC_EVENT_MANAGER_OBJECT_COMMON:
			break;
		case ID_SRC_EVENT_TIMER_FIRST_EVENT:
			break;
		case ID_SRC_EVENT_TIMER_LAST_EVENT:
			break;
		case ID_SRC_EVENT_GRAPHIC_ENGINE:
		{
			int s = pEvent->pContainer->GetSize();
			TBaseEvent* pData = (TBaseEvent*)pEvent->pContainer->GetPtr();
			switch(pData->type)
			{
				case eKeyBoard:
				{
					TKeyEvent* pKey = (TKeyEvent*)pData;
					KeyEvent(pKey);
					break;
				}
				case eMouse:
				{
					TMouseEvent* pMouse = (TMouseEvent*)pData;
					MouseEvent(pMouse);
					break;
				}
			}
		}
	}
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::MouseEvent(TMouseEvent* pEvent)
{
  switch(pEvent->state)
  {
    case nsEvent::eButtonUp:
      flgDragCamera = false;
      break;
    case nsEvent::eButtonDown:
      flgDragCamera = true;
      mOldX = pEvent->x;
      mOldY = pEvent->y;
      break;
    case nsEvent::eButtonDblClick:

      break;
    case nsEvent::eWheel:
      mComponent.mControlCamera->AddDistObj(float(pEvent->delta_wheel)/100.0f);
      break;
    case nsEvent::eMove:
      if(flgDragCamera)
      {
        float dRight = float(pEvent->x - mOldX)*ASPECT_MOUSE_X;
        float dDown  = float(pEvent->y - mOldY)*ASPECT_MOUSE_Y;
        mComponent.mControlCamera->RotateRight(dRight);
        mComponent.mControlCamera->RotateDown(dDown);
        
        mOldX = pEvent->x;
        mOldY = pEvent->y;
      }
			break;
  }
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::KeyEvent(TKeyEvent* pEvent)
{
  unsigned int v;
  bool res = mComponent.mMStateMachine->GetValue(mIDkey,pEvent->key,v);
  v |= (pEvent->pressed?0:UP);
  if(res)
  switch(v)
  {
    // клавиатура
    case e_W://W
      mComponent.mControlCamera->SetSpeedForward(DELTA_MOVE);
      break;
    case e_W|UP://W
      mComponent.mControlCamera->SetSpeedForward(0);
      break;
    case e_S://S
      mComponent.mControlCamera->SetSpeedForward(-DELTA_MOVE);
      break;
    case e_S|UP://S
      mComponent.mControlCamera->SetSpeedForward(0);
      break;
    case e_A://A
      mComponent.mControlCamera->SetSpeedRight(-DELTA_MOVE);
      break;
    case e_A|UP://A
      mComponent.mControlCamera->SetSpeedRight(0);
      break;
    case e_D://D
      mComponent.mControlCamera->SetSpeedRight(DELTA_MOVE);
      break;
    case e_D|UP://D
      mComponent.mControlCamera->SetSpeedRight(0);
      break;
    case e_Q://Q
      mComponent.mControlCamera->SetSpeedUp(DELTA_MOVE);
      break;
    case e_Q|UP://Q
      mComponent.mControlCamera->SetSpeedUp(0);
      break;
    case e_E://E
      mComponent.mControlCamera->SetSpeedUp(-DELTA_MOVE);
      break;
    case e_E|UP://E
      mComponent.mControlCamera->SetSpeedUp(0);
      break;
    // мышь
    case e_Numpad4:// влево 4
      mComponent.mControlCamera->RotateRight(-DELTA_ROTATE);
      break;
    case e_Numpad6:// вправо 6
      mComponent.mControlCamera->RotateRight(DELTA_ROTATE);
      break;
    case e_Numpad8:// вверх 8
      mComponent.mControlCamera->RotateDown(-DELTA_ROTATE);
      break;
    case e_Numpad2:// вниз 2
      mComponent.mControlCamera->RotateDown(DELTA_ROTATE);
      break;
    case e_Numpad7:// вращаться влево 7
      mComponent.mControlCamera->Roll(DELTA_ROTATE);
      break;
    case e_Numpad9:// вращаться вправо 9
      mComponent.mControlCamera->Roll(-DELTA_ROTATE);
      break;
    case e_C:// сбросить ориентацию камеры C
      mComponent.mControlCamera->ClearRotate();
      break;
    case e_V:// сбросить ориентацию камеры V
    {
      TVector3 v;
      v.x = 0.0f;
      v.y = 0.0f;
      v.z = 0.0f;
      mComponent.mControlCamera->SetPositionLookAt(&v);
      break;
    }
    case e_B: // B 
    {
      IBaseObject* pBO = mComponent.mMOC->Get(mIndexCurObj);
      mComponent.mControlCamera->Link(pBO,IControlCamera::eCoord);
      mIndexCurObj++;
      mIndexCurObj %= mComponent.mMOC->GetCountObject();
      break;
    }
    case e_N: 
    {
      mComponent.mControlCamera->Unlink();
      break;
    }
    case e_O: 
    {
      break;
    }
  }
}
//--------------------------------------------------------------------
IMakerObjectCommon* TClientDeveloperTool_ViewerModel::GetMakerObjectCommon()
{
  return mMakerObjectCommon;
}
//------------------------------------------------------------------------------------
string TClientDeveloperTool_ViewerModel::GetTitleWindow()
{
  return "Просмоторщик моделей";
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::Init(TComponentClient* pComponent, vector<string>& arg )
{
  InitLog();
  mComponent = *pComponent; 

  int cnt[3] = {1,1,1};
#ifdef LOG_TIME_LOAD_EDITOR_MODEL
  unsigned int start = ht_GetMSCount();
#endif 
  CreateHangar();
  CreateObjects(cnt[0],cnt[1],cnt[2]);
#ifdef LOG_TIME_LOAD_EDITOR_MODEL
  start = ht_GetMSCount() - start;
  float v = start/float(cnt[0]*cnt[1]*cnt[2]);
  GetLogger("Inner")->WriteF_time("ViewerModel: Время загрузки объектов t=%u мс,v=%f мс/об.\n",start,v);
#endif
  // HotKey
	if(GetStorePathResources()->GetCount("game_param")>0)
	{
		string sGameParam = GetStorePathResources()->GetSecond("game_param");
		bool resLoadMSM = mComponent.mMStateMachine->Load(sGameParam.data(), mIDkey);
		BL_ASSERT(resLoadMSM);
	}
	else
		BL_FIX_BUG();
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::CreateHangar()
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  w._43 -= 1.0f;
  IBaseObjectCommon* pBOC = mComponent.mMOC->CreateObject(1);
  pBOC->SetWorld(&w);
  mComponent.mGraphicEngine->AddObject(pBOC);
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::CreateObjects(int cntK,int cntJ,int cntI)
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  float sizeK = 4,sizeJ = 12, sizeI = 5;

  w._43 = -((cntK+1)*sizeK)/2;
  for(int k = 0 ; k < cntK ; k ++)
  {
    w._42 = -((cntJ+1)*sizeJ)/2;
    w._43 += sizeK;
    for(int j = 0 ; j < cntJ ; j ++)
    {
      w._41  = -((cntI+1)*sizeI)/2;
      w._42 += sizeJ;
      for(int i = 0 ; i < cntI ; i ++)
      {
        IBaseObjectCommon* pBOC = mComponent.mMOC->CreateObject(0);

        //pBOC->SetVelocity(0.1f);
        w._41 += sizeI;
        pBOC->SetWorld(&w);
        //if((i==cntI-1)&&(j==cntJ-1)&&(k==cntK-1))
          //pBOC->SetAlphaTransparency(0.5f);
        mComponent.mGraphicEngine->AddObject(pBOC);
      }
    }
  }
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::Done()
{

}        
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ViewerModel::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("ViewerModel");
}
//---------------------------------------------------------------------------------------------
string TClientDeveloperTool_ViewerModel::GetPathXMLFile()
{
  return "resources.xml";
}
//---------------------------------------------------------------------------------------------
