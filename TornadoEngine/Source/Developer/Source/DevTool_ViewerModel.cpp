/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <string.h>

#include "DevTool_ViewerModel.h"
#include "Logger.h"
#include "HiTimer.h"
#include "ManagerStateMachine.h"
#include "IXML.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"
#include "MathTools.h"
#include "ListModule.h"

using namespace std;
using namespace nsMathTools;
using namespace nsEvent;
//using namespace nsKey;

#define LOG_TIME_LOAD_EDITOR_MODEL

#define DELTA_MOVE 0.2f //0.4f
#define DELTA_ROTATE 0.01f
#define ASPECT_MOUSE_X 0.002f
#define ASPECT_MOUSE_Y 0.002f

#define UP 1000000

TDevTool_ViewerModel::TDevTool_ViewerModel()
{
  flgDragCamera = false;
  mIndexCurObj = 0;
}
//------------------------------------------------------------------------------------
TDevTool_ViewerModel::~TDevTool_ViewerModel()
{

}
//------------------------------------------------------------------------------------
void TDevTool_ViewerModel::Event(nsEvent::TEvent* pEvent)
{
	switch(pEvent->type_object)
	{
		case MODULE_MMO_ENGINE_CLIENT:
			break;
		case MODULE_PHYSIC_ENGINE:
			break;
		case MODULE_TIMER:
			break;
		case MODULE_GRAPHIC_ENGINE:
		{
			int s = pEvent->pContainer->GetSize();
			//TBaseEvent* pData = (TBaseEvent*)pEvent->pContainer->GetPtr();
			//switch(pData->type)
			//{
			//	case eKeyBoard:
			//	{
			//		TKeyEvent* pKey = (TKeyEvent*)pData;
			//		KeyEvent(pKey);
			//		break;
			//	}
			//	case eMouse:
			//	{
			//		TMouseEvent* pMouse = (TMouseEvent*)pData;
			//		MouseEvent(pMouse);
			//		break;
			//	}
			//}
		}
	}
}
//------------------------------------------------------------------------------------
//void TDevTool_ViewerModel::MouseEvent(TMouseEvent* pEvent)
//{
//  switch(pEvent->state)
//  {
//    case nsEvent::eButtonUp:
//      flgDragCamera = false;
//      break;
//    case nsEvent::eButtonDown:
//      flgDragCamera = true;
//      mOldX = pEvent->x;
//      mOldY = pEvent->y;
//      break;
//    case nsEvent::eButtonDblClick:
//
//      break;
//    case nsEvent::eWheel:
//      //mComponent.mGraphicEngine->GetControlCamera()->AddDistObj(float(pEvent->delta_wheel)/100.0f);
//      break;
//    case nsEvent::eMove:
//      if(flgDragCamera)
//      {
//        float dRight = float(pEvent->x - mOldX)*ASPECT_MOUSE_X;
//        float dDown  = float(pEvent->y - mOldY)*ASPECT_MOUSE_Y;
//        //mComponent.mGraphicEngine->GetControlCamera()->RotateRight(dRight);
//        //mComponent.mGraphicEngine->GetControlCamera()->RotateDown(dDown);
//        
//        mOldX = pEvent->x;
//        mOldY = pEvent->y;
//      }
//			break;
//  }
//}
////------------------------------------------------------------------------------------
//void TDevTool_ViewerModel::KeyEvent(TKeyEvent* pEvent)
//{
//  unsigned int v;
//  bool res = mComponent.mMStateMachine.GetValue(mIDkey,pEvent->key,v);
//  v |= (pEvent->pressed?0:UP);
//  /*if(res)
//  switch(v)
//  {
//    // клавиатура
//    case e_W://W
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(DELTA_MOVE);
//      break;
//    case e_W|UP://W
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(0);
//      break;
//    case e_S://S
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(-DELTA_MOVE);
//      break;
//    case e_S|UP://S
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(0);
//      break;
//    case e_A://A
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(-DELTA_MOVE);
//      break;
//    case e_A|UP://A
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(0);
//      break;
//    case e_D://D
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(DELTA_MOVE);
//      break;
//    case e_D|UP://D
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(0);
//      break;
//    case e_Q://Q
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(DELTA_MOVE);
//      break;
//    case e_Q|UP://Q
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(0);
//      break;
//    case e_E://E
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(-DELTA_MOVE);
//      break;
//    case e_E|UP://E
//      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(0);
//      break;
//    // мышь
//    case e_Numpad4:// влево 4
//      mComponent.mGraphicEngine->GetControlCamera()->RotateRight(-DELTA_ROTATE);
//      break;
//    case e_Numpad6:// вправо 6
//      mComponent.mGraphicEngine->GetControlCamera()->RotateRight(DELTA_ROTATE);
//      break;
//    case e_Numpad8:// вверх 8
//      mComponent.mGraphicEngine->GetControlCamera()->RotateDown(-DELTA_ROTATE);
//      break;
//    case e_Numpad2:// вниз 2
//      mComponent.mGraphicEngine->GetControlCamera()->RotateDown(DELTA_ROTATE);
//      break;
//    case e_Numpad7:// вращаться влево 7
//      mComponent.mGraphicEngine->GetControlCamera()->Roll(DELTA_ROTATE);
//      break;
//    case e_Numpad9:// вращаться вправо 9
//      mComponent.mGraphicEngine->GetControlCamera()->Roll(-DELTA_ROTATE);
//      break;
//    case e_C:// сбросить ориентацию камеры C
//      mComponent.mGraphicEngine->GetControlCamera()->ClearRotate();
//      break;
//    case e_V:// сбросить ориентацию камеры V
//    {
//      TVector3 v;
//      v.x = 0.0f;
//      v.y = 0.0f;
//      v.z = 0.0f;
//      mComponent.mGraphicEngine->GetControlCamera()->SetPositionLookAt(&v);
//      break;
//    }
//    case e_B: // B 
//    {
//      IBaseObject* pBO = mComponent.mMOG->Get(mIndexCurObj);
//      mComponent.mGraphicEngine->GetControlCamera()->Link(pBO,PrototypeControlCamera::eCoord);
//      mIndexCurObj++;
//      mIndexCurObj %= mComponent.mMOG->GetCountObject();
//      break;
//    }
//    case e_N: 
//    {
//      mComponent.mGraphicEngine->GetControlCamera()->Unlink();
//      break;
//    }
//    case e_O: 
//    {
//      break;
//    }
//  }*/
//}
//--------------------------------------------------------------------
void TDevTool_ViewerModel::Init(vector<string>& arg )
{
  InitLog();
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
		bool resLoadMSM = mComponent.mMStateMachine.Load(sGameParam.data(), mIDkey);
		BL_ASSERT(resLoadMSM);
	}
	else
		BL_FIX_BUG();
}
//------------------------------------------------------------------------------------
void TDevTool_ViewerModel::CreateHangar()
{
  //TMatrix16 w;
  //SetMatrixIdentity(&w);
  //w.s._43 -= 1.0f;
  //IBaseObjectGeneral* pBOC = mComponent.mMOG->CreateObject(1);
  //pBOC->SetWorld(&w);
  //mComponent.mGraphicEngine->AddObject(pBOC);
}
//------------------------------------------------------------------------------------
void TDevTool_ViewerModel::CreateObjects(int cntK,int cntJ,int cntI)
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  float sizeK = 4,sizeJ = 12, sizeI = 5;

  w.s._43 = -((cntK+1)*sizeK)/2;
  for(int k = 0 ; k < cntK ; k ++)
  {
    w.s._42 = -((cntJ+1)*sizeJ)/2;
    w.s._43 += sizeK;
    for(int j = 0 ; j < cntJ ; j ++)
    {
      w.s._41  = -((cntI+1)*sizeI)/2;
      w.s._42 += sizeJ;
      for(int i = 0 ; i < cntI ; i ++)
      {
        //IBaseObjectGeneral* pBOC = mComponent.mMOG->CreateObject(0);

        //pBOC->SetVelocity(0.1f);
        w.s._41 += sizeI;
        //pBOC->SetWorld(&w);
        //if((i==cntI-1)&&(j==cntJ-1)&&(k==cntK-1))
          //pBOC->SetAlphaTransparency(0.5f);
        //mComponent.mGraphicEngine->AddObject(pBOC);
      }
    }
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_ViewerModel::Done()
{

}        
//---------------------------------------------------------------------------------------------
void TDevTool_ViewerModel::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("ViewerModel");
}
//---------------------------------------------------------------------------------------------
