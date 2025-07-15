/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/ContainerTypes.h"
#include "Base/Common/ShareMisc.h"

#include "MMOEngine/SubSystem/IScenarioContext.h"

namespace nsMMOEngine
{
    class TContextScRecommutationClient : public IScenarioContext
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

        std::string mLogin;
        std::string mPassword;
    public:
        TContextScRecommutationClient();
        virtual ~TContextScRecommutationClient();

        // сессии для Slave, в остальных случаях для Мастера и Клиента использовать G(S)etID_Session
        unsigned int GetID_SessionClientSlave();
        void SetID_SessionClientSlave(unsigned int sessionID);

        unsigned int GetID_SessionMasterSlave();
        void SetID_SessionMasterSlave(unsigned int sessionID);

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

        void SetLogin(const std::string& login);
        std::string GetLogin();

        void SetPassword(const std::string& password);
        std::string GetPassword();
    private:
    };
}