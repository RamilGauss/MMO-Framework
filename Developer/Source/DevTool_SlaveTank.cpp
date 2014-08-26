/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "DevTool_SlaveTank.h"

#include "NetSystem.h"
#include "GlobalParam.h"
#include "IQtLib.h"
#include "SlaveForm.h"
#include "DevProtocol.h"

using namespace std;

TDevTool_SlaveTank::TDevTool_SlaveTank()
{
  mSlaveForm = NULL;
}
//---------------------------------------------------------------------------------
TDevTool_SlaveTank::~TDevTool_SlaveTank()
{

}
//---------------------------------------------------------------------------------
void TDevTool_SlaveTank::Init(vector<string>& arg)
{
  InitLog();
  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  bool resOpen = mComponent.mSlave->Get()->Open(&nsMMOEngine::TDescOpen(input.port));
  BL_ASSERT(resOpen);
  mComponent.mSlave->Get()->ConnectUp( input.ip, MASTER_PORT);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::InitQtForm,this);

  mComponent.mTimer->New(0);
}
//---------------------------------------------------------------------------------
void TDevTool_SlaveTank::Done()
{

}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->type_object)
  {
    case MODULE_MMO_ENGINE_SLAVE:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case MODULE_PHYSIC_ENGINE:
      break;
    case MODULE_ALONE_GUI:
      HandleFromQt(pEvent);
      break;
		case MODULE_TIMER:
			mTestControlTank.Send();
			break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown((nsMMOEngine::TEventConnectDown*)pBE);
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((nsMMOEngine::TEventDisconnectDown*)pBE);
      break;
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      ConnectUp((nsMMOEngine::TEventConnectUp*)pBE);
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp((nsMMOEngine::TEventDisconnectUp*)pBE);
      break;
    case nsMMOEngine::eError:
    {
      char sError[300];
      nsMMOEngine::TEventError* pEr = (nsMMOEngine::TEventError*)pBE;
      sprintf(sError, "Error code=%u", pEr->code);
      sEvent = sError;
    }
      break;
    case nsMMOEngine::eRecvFromDown:
      sEvent = "RecvFromDown";
      break;
    case nsMMOEngine::eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case nsMMOEngine::eSaveContext:
      sEvent = "SaveContext";
      // типа Сохранить данные нашего Клиента и отдать другому Slave
      SaveContextClient((nsMMOEngine::TEventSaveContext*)pBE);
      break;
    case nsMMOEngine::eRestoreContext:
      sEvent = "RestoreContext";
      RestoreContextClient((nsMMOEngine::TEventRestoreContext*)pBE);
      break;
    case nsMMOEngine::eTryLogin:
      sEvent = "TryLogin";
      break;
    case nsMMOEngine::eResultLogin:
      sEvent = "ResultLogin";
      break;
    case nsMMOEngine::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("SlaveTank");
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::InitQtForm()
{
  mSlaveForm = new TSlaveForm;
  mSlaveForm->show();

	mSlaveForm->SetControlTank(&mTestControlTank);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::HandleFromQt(nsEvent::TEvent* pEvent)
{
  nsDevProtocol::TBase* pH = (nsDevProtocol::TBase*)pEvent->pContainer->GetPtr();
  switch(pH->type)
  {
    case nsDevProtocol::Exit:
      mSlaveForm = NULL;
      Exit();
      break;
    default:;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = SLAVE_PORT;

  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::ConnectUpQt,this);
  // ###
  //char s = 'm';
  //TBreakPacket bp;
  //bp.PushBack(&s, sizeof(s));
  //mComponent.mNet.Slave->SendUp(bp);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::DisconnectUpQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::ConnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::DisconnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::AddClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::DeleteClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::AddClientQt()
{
  unsigned int** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    TSlaveForm::TDesc desc;
    desc.id_session = ID;
    bool resInfoSession = mComponent.mSlave->Get()->GetInfoSession(ID, desc.ip_port);
    BL_ASSERT(resInfoSession);
    if(mSlaveForm)
      mSlaveForm->Add(desc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::DeleteClientQt()
{
  unsigned int** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    if(mSlaveForm)
      mSlaveForm->Delete(ID);
    // следующий ID
    mListID_SessionDelete.Remove(ppFirst);
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::SaveContextClient(nsMMOEngine::TEventSaveContext* pEvent)
{
  mComponent.mSlave->Get()->SaveContext(pEvent->id_session, NULL, 0);

  // удалить из списка этого Клиента
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::DeleteClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::RestoreContextClient(nsMMOEngine::TEventRestoreContext* pEvent)
{
  // добавить Клиента
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::AddClientQt,this);
}
//---------------------------------------------------------------------------------------------