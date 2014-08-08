/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_SlaveTank.h"

#include <boost/asio/ip/impl/address_v4.ipp>

#include "MakerObjectGeneral.h"
#include "PrototypeMMOSlave.h"
#include "NetSystem.h"
#include "GlobalParam.h"
#include "IQtLib.h"
#include "SlaveForm.h"
#include "PrototypeTimer.h"
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

  bool resOpen = mComponent.mNet.Slave->Open(&PrototypeMMODescOpen(input.port));
  BL_ASSERT(resOpen);
  mComponent.mNet.Slave->ConnectUp( input.ip, MASTER_PORT);

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
    case PROTOTYPE_TYPE_MMO_ENGINE_SLAVE:
      HandleFromMMOEngine((PrototypeMMOBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case PROTOTYPE_TYPE_PHYSIC_ENGINE:
      break;
    case PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL:
      break;
    case PROTOTYPE_TYPE_ALONE_GUI:
      HandleFromQt(pEvent);
      break;
		case PROTOTYPE_TYPE_TIMER:
			mTestControlTank.Send();
			break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown((PrototypeMMOEventConnectDown*)pBE);
      break;
    case eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((PrototypeMMOEventDisconnectDown*)pBE);
      break;
    case eConnectUp:
      sEvent = "ConnectUp";
      ConnectUp((PrototypeMMOEventConnectUp*)pBE);
      break;
    case eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp((PrototypeMMOEventDisconnectUp*)pBE);
      break;
    case eError:
    {
      char sError[300];
      PrototypeMMOEventError* pEr = (PrototypeMMOEventError*)pBE;
      sprintf(sError, "Error code=%u", pEr->code);
      sEvent = sError;
    }
      break;
    case eRecvFromDown:
      sEvent = "RecvFromDown";
      break;
    case eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case eSaveContext:
      sEvent = "SaveContext";
      // типа Сохранить данные нашего Клиента и отдать другому Slave
      SaveContextClient((PrototypeMMOEventSaveContext*)pBE);
      break;
    case eRestoreContext:
      sEvent = "RestoreContext";
      RestoreContextClient((PrototypeMMOEventRestoreContext*)pBE);
      break;
    case eTryLogin:
      sEvent = "TryLogin";
      break;
    case eResultLogin:
      sEvent = "ResultLogin";
      break;
    case eDestroyGroup:
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
  mSlaveForm = new SlaveForm;
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
void TDevTool_SlaveTank::ConnectUp(PrototypeMMOEventConnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::ConnectUpQt,this);
  // ###
  //char s = 'm';
  //TBreakPacket bp;
  //bp.PushBack(&s, sizeof(s));
  //mComponent.mNet.Slave->SendUp(bp);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::DisconnectUp(PrototypeMMOEventDisconnectUp* pBE)
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
void TDevTool_SlaveTank::ConnectDown(PrototypeMMOEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::AddClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::DisconnectDown(PrototypeMMOEventDisconnectDown* pEvent)
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
void TDevTool_SlaveTank::SaveContextClient(PrototypeMMOEventSaveContext* pEvent)
{
  mComponent.mNet.Slave->SaveContext(pEvent->id_session, NULL, 0);

  // удалить из списка этого Клиента
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::DeleteClientQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SlaveTank::RestoreContextClient(PrototypeMMOEventRestoreContext* pEvent)
{
  // добавить Клиента
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SlaveTank::AddClientQt,this);
}
//---------------------------------------------------------------------------------------------