/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameRoomPrepare.h"

#include "Precompiled.h"
#include <atlconv.h>

#include "../GameLib/IClientDeveloperTool.h"
#include "Base.h"
#include "DevProtocol.h"

TGameRoomPrepare::TGameRoomPrepare()
{

}
//------------------------------------------------------
TGameRoomPrepare::~TGameRoomPrepare()
{

}
//-------------------------------------------------------------------------------------
void TGameRoomPrepare::Activate()
{
  assignWidget(bFight,"bFight");
  assignWidget(bExit, "bExit");

  bFight->eventMouseButtonClick += MyGUI::newDelegate(this, &TGameRoomPrepare::sl_Fight);
  bExit ->eventMouseButtonClick += MyGUI::newDelegate(this, &TGameRoomPrepare::sl_Exit);
}
//-------------------------------------------------------------------------------------
void TGameRoomPrepare::sl_Fight(MyGUI::Widget* _sender)
{

}
//-------------------------------------------------------------------------------------
void TGameRoomPrepare::sl_Exit(MyGUI::Widget* _sender)
{
	IClientDeveloperTool::Singleton()->GetComponent()->mNetClient->DisconnectUp();

  nsDevProtocol::TDisconnectUp_Client h;
  IClientDeveloperTool::Singleton()->GetComponent()->mDev.AddEventCopy(&h, sizeof(h));
}
//-------------------------------------------------------------------------------------
const char* TGameRoomPrepare::GetNameLayout()
{
  return "GameRoomPrepare.layout";
}
//-------------------------------------------------------------------------------------
void* TGameRoomPrepare::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TGameRoomPrepare::SetupTabChild()
{
  //mVectorChild_Tab.push_back(ebIP);
  //mVectorChild_Tab.push_back(ebLogin);
  //mVectorChild_Tab.push_back(ebPort);
}
//-------------------------------------------------------------------------------------
void TGameRoomPrepare::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
    case MyGUI::KeyCode::Return:
      //sl_Enter(_sender);
      break;
    default:;
  }
}
//-------------------------------------------------------------------------------------
