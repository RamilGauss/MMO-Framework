/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenarioLoginClient.h"
#include "HiTimer.h"
#include "SessionManager.h"
#include "Logger.h"
#include "Base.h"
#include "Events.h"
#include "EnumMMO.h"
#include "BL_Debug.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;
using namespace std;

TScenarioLoginClient::TScenarioLoginClient() :
    mClient(this), mSlave(this), mMaster(this), mSS(this)
{
    mCurBehavior = nullptr;

    AddCallBack(eSetClientKey, &mCBSetClientKey);
    AddCallBack(eContextByMasterSessionByClientKey, &mCBContextByMasterSessionByClientKey);
    AddCallBack(eNumInQueueByClientKey, &mCBNumInQueueByClientKey);
    AddCallBack(eContextByClientSessionByClientKey, &mCBContextByClientSessionByClientKey);
    AddCallBack(eContextByClientSessionAfterAuthorised, &mCBContextByClientSessionAfterAuthorised);
    AddCallBack(eContextByClientSessionLeaveQueue, &mCBContextByClientSessionLeaveQueue);
    AddCallBack(eContextByClientKey_SecondCallSlave, &mCBContextByClientKey_SecondCallSlave);
}
//--------------------------------------------------------------
TScenarioLoginClient::~TScenarioLoginClient()
{

}
//--------------------------------------------------------------
void TScenarioLoginClient::Work()
{
    if (mCurBehavior) {
        unsigned int time_ms = ht_GetMSCount();
        mCurBehavior->Work(time_ms);
    }
}
//--------------------------------------------------------------
void TScenarioLoginClient::TryLogin(TIP_Port& ip_port, const std::string& login, const std::string& password, unsigned char subNet)
{
    mClient.TryLogin(ip_port, login, password, subNet);
}
//--------------------------------------------------------------
void TScenarioLoginClient::Recv(TDescRecvSession* pDesc)
{
    mCurBehavior->Recv(pDesc);
}
//--------------------------------------------------------------
void TScenarioLoginClient::Reject(void* resForClient, int sizeResClient)
{
    mMaster.Reject(resForClient, sizeResClient);
}
//--------------------------------------------------------------
void TScenarioLoginClient::Accept(unsigned int key, void* resForClient, int sizeResClient,
    unsigned int id_session_slave, unsigned int id_superserver)
{
    mMaster.Accept(key, resForClient, sizeResClient, id_session_slave, id_superserver);
}
//--------------------------------------------------------------
void TScenarioLoginClient::Queue(int num, void* resForClient, int sizeResClient)
{
    mMaster.Queue(num, resForClient, sizeResClient);
}
//--------------------------------------------------------------
void TScenarioLoginClient::SetBehavior(eBehavior v)
{
    switch (v) {
    case eClient:
        mCurBehavior = &mClient;
        break;
    case eSlave:
        mCurBehavior = &mSlave;
        break;
    case eMaster:
        mCurBehavior = &mMaster;
        break;
    case eSuperServer:
        mCurBehavior = &mSS;
        break;
    }
}
//---------------------------------------------------------------------
void TScenarioLoginClient::LeaveQueue()
{
    mClient.LeaveQueue();
}
//---------------------------------------------------------------------
void TScenarioLoginClient::DisconnectFromClient()
{
    mClient.Disconnect();
}
//---------------------------------------------------------------------
void TScenarioLoginClient::DisconnectFromMaster()
{
    mMaster.Disconnect();
}
//---------------------------------------------------------------------
void TScenarioLoginClient::SetFakeClient(bool val)
{
    mSS.SetFakeClient(val);
}
//---------------------------------------------------------------------
