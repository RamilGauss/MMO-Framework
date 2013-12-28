/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_RECOMMUTATION_CLIENT_H
#define CONTEXT_SC_RECOMMUTATION_CLIENT_H

#include "IContextScenario.h"
#include "Container.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
  class TContextScRecommutationClient : public IContextScenario
	{
    unsigned int mID_SessionMasterSlave;

    unsigned int mClientKey;
    unsigned int mSessionDonor;
    unsigned int mSessionRecipient;

    TContainer mContextData;

		// для самоопределения на Slave
		typedef enum
		{
			eUndef,
			eDonor,
			eRecipient,
		}TypeSlave;
		TypeSlave mTypeSlave;

    unsigned int mTimeWaitAnswer;

    TIP_Port mIP_PortRecipient;

    unsigned int mRandomNum;
	public:
		TContextScRecommutationClient();
    virtual ~TContextScRecommutationClient();

    // сессии для Slave, в остальных случаях для Мастера и Клиента использовать G(S)etID_Session
    unsigned int GetID_SessionClientSlave();
    void SetID_SessionClientSlave(unsigned int id_session);

    unsigned int GetID_SessionMasterSlave();
    void SetID_SessionMasterSlave(unsigned int id_session);

    void SetClientKey(unsigned int v);
    unsigned int GetClientKey();

    void SetSessionDonor(unsigned int v);
    unsigned int GetSessionDonor();
    
    void SetSessionRecipient(unsigned int v);
    unsigned int GetSessionRecipient();

    void  SaveContextData(char* p, int size);
    char* GetContextDataPtr();
    int   GetContextDataSize();
    void  CleanContextData();

		// необходимо для определения поведения при Дисконнекте Клиента
		void SetRoleAsDonor();
		bool IsDonor();
		void SetRoleAsRecipient();
		bool IsRecipient();

    void SetTimeWait(unsigned int v);
    unsigned int GetTimeWait();

    void SetIP_PortRecipient(TIP_Port& ip_port);
    void GetIP_PortRecipient(TIP_Port& ip_port);

    void SetRandomNum(unsigned int random_num);
    unsigned int GetRandomNum();
  private:
	};
}  
#endif