/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_LOGIN_CLIENT_H
#define CONTEXT_SC_LOGIN_CLIENT_H

#include "IContextScenario.h"

#include <map>

#include "BreakPacket.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
  // сценарии, содержащиес€ в контейнере взаимно блокируютс€
  class TContextScLoginClient : public IContextScenario
	{
  public:
    typedef enum
    {
      eUndef,
      eReject,
      eAccept,
    }tStateResult;
  private:
    
    bool flgNeedLeaveQueue;

    tStateResult mState;

    int mNumInQueue;

    unsigned int mTimeWaitAnswer;
    unsigned int mTimeLastNeedNumInQueue;

    unsigned int mDeltaTimeWait_ms;

    typedef std::map<std::string, unsigned int> TMapStrUint;
    typedef TMapStrUint::iterator TMapStrUintIt;
    TMapStrUint mMapStrID_Session;

    TContainer mAcceptData;
    TContainer mQueueData;

    unsigned int mClientKey;

    TIP_Port mIP_Port_slave;

    bool flgFakeClient;

    bool flgTimeWaitElapsed;

		unsigned char mSubNet;

		// используетс€ на стороне Slave дл€ определени€ стартовал ли контекст
		bool flgWasBegin;
	public:
		TContextScLoginClient();
    virtual ~TContextScLoginClient();

		bool WasBegin();
		void SetWasBegin();

    unsigned int GetClientKey();
    void SetClientKey(unsigned int id);

    void SetTimeWait(unsigned int v);
    unsigned int GetTimeWait();

    unsigned int GetDeltaTimeWaitMS();
    void SetDeltaTimeWaitMS(unsigned int delta);

    bool IsTimeWaitElapsed();
    void SetTimeWaitElapsed();

    void SetTimeLastNeedNumInQueue(unsigned int v);
    unsigned int GetTimeLastNeedNumInQueue();

    void Accept();
    void Reject();
    
    bool IsReject();
    bool IsAccept();

    unsigned int GetID_SessionClientMaster();
    void SetID_SessionClientMaster(unsigned int id);
    unsigned int GetID_SessionClientSlave();
    void SetID_SessionClientSlave(unsigned int id);
    unsigned int GetID_SessionMasterSlave();
    void SetID_SessionMasterSlave(unsigned int id);
    unsigned int GetID_SessionMasterSS();
    void SetID_SessionMasterSS(unsigned int id);

    void SetNumInQueue(int val);
    int  GetNumInQueue();

    void SaveAcceptData(void* resForClient, int sizeResClient);
    void* GetSaveAcceptDataPtr();
    int   GetSaveAcceptDataSize();

		void SaveQueueData(void* resForClient, int sizeResClient);
		void* GetSaveQueueDataPtr();
		int   GetSaveQueueDataSize();

    void SetNeedLeaveQueue(bool val);
    bool NeedLeaveQueue();

    TIP_Port GetSlaveIP_Port(); 
    void SetSlaveIP_Port(TIP_Port& ip_port);
    
    // только дл€ SuperServer
    bool GetFakeClient();
    void SetFakeClient(bool val);

		void SetSubNet(unsigned char v);
		unsigned char GetSubNet();
  private:
    void SetID_Session(std::string& name, unsigned int id);
    unsigned int GetID_Session(std::string& name);
	};
}  
#endif