/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ServerDeveloperTool_SlaveTank.h"

#include <boost/asio/ip/impl/address_v4.ipp>

#include "MakerObjectGeneral.h"
#include "Slave.h"
#include "NetSystem.h"
#include "GlobalParam.h"
#include "../GameLib/NameSrcEventID.h"
#include "../QtLib/IQtLib.h"
#include "SlaveForm.h"
#include "../../GameLib/ITimer.h"

#include "DevProtocol.h"

using namespace std;
using namespace nsMMOEngine;

TServerDeveloperTool_SlaveTank::TServerDeveloperTool_SlaveTank()
{
	mMakerObjectGeneral = new TMakerObjectGeneral;
  mSlaveForm = NULL;
}
//---------------------------------------------------------------------------------
TServerDeveloperTool_SlaveTank::~TServerDeveloperTool_SlaveTank()
{
  delete mMakerObjectGeneral;
}
//---------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::Init(TComponentServer* pComponent, vector<string>& arg)
{
  InitLog();
  mComponent = *pComponent;

  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  bool resOpen = mComponent.mNet.Slave->Open(&TDescOpen(input.port));
  BL_ASSERT(resOpen);
  mComponent.mNet.Slave->ConnectUp( input.ip, MASTER_PORT);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::InitQtForm,this);

  mComponent.mTimerFirstEvent->New(0);
}
//---------------------------------------------------------------------------------
int TServerDeveloperTool_SlaveTank::GetTimeRefreshMS()
{
	return 100;
}
//---------------------------------------------------------------------------------
IMakerObjectGeneral* TServerDeveloperTool_SlaveTank::GetMakerObjectGeneral()
{
	return mMakerObjectGeneral;
}
//------------------------------------------------------------------------------------
string TServerDeveloperTool_SlaveTank::GetPathXMLFile()
{
	return "resources.xml";
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::Done()
{

}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->from)
  {
    case ID_SRC_EVENT_NETWORK_ENGINE:
      HandleFromMMOEngine((TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case ID_SRC_EVENT_PHYSIC_ENGINE:
      break;
    case ID_SRC_EVENT_MANAGER_OBJECT_GENERAL:
      break;
    case ID_SRC_EVENT_QT_LIB:
      HandleFromQt(pEvent);
      break;
		case ID_SRC_EVENT_TIMER_FIRST_EVENT:
			mTestControlTank.Send();
			break;
  }
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::HandleFromMMOEngine(TBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case TBase::eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown((TEventConnectDown*)pBE);
      break;
    case TBase::eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((TEventDisconnectDown*)pBE);
      break;
    case TBase::eConnectUp:
      sEvent = "ConnectUp";
      ConnectUp((TEventConnectUp*)pBE);
      break;
    case TBase::eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp((TEventDisconnectUp*)pBE);
      break;
    case TBase::eError:
    {
      char sError[300];
      TEventError* pEr = (TEventError*)pBE;
      sprintf(sError, "Error code=%u", pEr->code);
      sEvent = sError;
    }
      break;
    case TBase::eRecvFromDown:
      sEvent = "RecvFromDown";
      break;
    case TBase::eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case TBase::eSaveContext:
      sEvent = "SaveContext";
      // типа Сохранить данные нашего Клиента и отдать другому Slave
      SaveContextClient((TEventSaveContext*)pBE);
      break;
    case TBase::eRestoreContext:
      sEvent = "RestoreContext";
      RestoreContextClient((TEventRestoreContext*)pBE);
      break;
    case TBase::eTryLogin:
      sEvent = "TryLogin";
      break;
    case TBase::eResultLogin:
      sEvent = "ResultLogin";
      break;
    case TBase::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("SlaveTank");
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::InitQtForm()
{
  mSlaveForm = new SlaveForm;
  mSlaveForm->show();

	mSlaveForm->SetControlTank(&mTestControlTank);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::HandleFromQt(nsEvent::TEvent* pEvent)
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
void TServerDeveloperTool_SlaveTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = SLAVE_PORT;

  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::ConnectUp(TEventConnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::ConnectUpQt,this);
  // ###
  //char s = 'm';
  //TBreakPacket bp;
  //bp.PushBack(&s, sizeof(s));
  //mComponent.mNet.Slave->SendUp(bp);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::DisconnectUp(TEventDisconnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::DisconnectUpQt,this);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::ConnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::DisconnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::ConnectDown(TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::AddClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::DisconnectDown(TEventDisconnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::DeleteClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::AddClientQt()
{
  unsigned int** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    SlaveForm::TDesc desc;
    desc.id_session = ID;
    bool resInfoSession = mComponent.mNet.Slave->GetInfoSession(ID, desc.ip_port);
    BL_ASSERT(resInfoSession);
    if(mSlaveForm)
      mSlaveForm->Add(desc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::DeleteClientQt()
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
void TServerDeveloperTool_SlaveTank::SaveContextClient(TEventSaveContext* pEvent)
{
  mComponent.mNet.Slave->SaveContext(pEvent->id_session, NULL, 0);

  // удалить из списка этого Клиента
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::DeleteClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SlaveTank::RestoreContextClient(TEventRestoreContext* pEvent)
{
  // добавить Клиента
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SlaveTank::AddClientQt,this);
}
//---------------------------------------------------------------------------------------------