/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <time.h>

#include "DescRecvSession.h"
#include "ScenarioBaseHeader.h"

#pragma pack(push, 1)

namespace nsMMOEngine
{
    namespace nsRecommutationClientStruct
    {
        enum
        {
            eBeginDonor,
            eBeginClient,
            eCheckBeginClient,
            eCheckBeginDonor,
            eBeginRecipient,
            eCheckBeginRecipient,
            eInfoRecipientToDonor,
            eInfoRecipientToClient,
            eCheckInfoRecipient,
            eRequestConnect,
            eCheckRequestConnect,
            eClientConnect,
            //-------------------------
            eDisconnectClient,
        };
        enum
        {
            eClient,
            eSlaveDonor,
            eSlaveRecipient,
            eMaster,
        };
        //-------------------------------------------------
        struct THeader : public TScenarioBaseHeader
        {
            THeader();
            unsigned char from;
            unsigned int  clientKey;
        };
        //-------------------------------------------------
        struct THeaderC : public THeader { THeaderC() { from = eClient; } };
        struct THeaderM : public THeader { THeaderM() { from = eMaster; } };
        struct THeaderSD : public THeader { THeaderSD() { from = eSlaveDonor; } };
        struct THeaderSR : public THeader { THeaderSR() { from = eSlaveRecipient; } };
        //-------------------------------------------------
        struct THeaderBeginDonor : THeaderM
        {
            THeaderBeginDonor();
        };
        //-------------------------------------------------
        struct THeaderBeginClient : THeaderSD
        {
            THeaderBeginClient();
        };
        //-------------------------------------------------
        struct THeaderCheckBeginClient : THeaderC
        {
            THeaderCheckBeginClient();
        };
        //-------------------------------------------------
        struct THeaderCheckBeginDonor : THeaderSD
        {
            THeaderCheckBeginDonor();
        };
        //-------------------------------------------------
        struct THeaderBeginRecipient : THeaderM
        {
            THeaderBeginRecipient();
            unsigned int random_num;
        };
        //-------------------------------------------------
        struct THeaderCheckBeginRecipient : THeaderSR
        {
            THeaderCheckBeginRecipient();
        };
        //-------------------------------------------------
        struct THeaderInfoRecipientToDonor : THeaderM
        {
            THeaderInfoRecipientToDonor();
            TIP_Port ip_port_recipient;
            unsigned int random_num;
        };
        //-------------------------------------------------
        struct THeaderInfoRecipientToClient : THeaderSD
        {
            THeaderInfoRecipientToClient();
            TIP_Port ip_port_recipient;
            unsigned int random_num;
        };
        //-------------------------------------------------
        struct THeaderCheckInfoRecipient : THeaderC
        {
            THeaderCheckInfoRecipient();
        };
        //-------------------------------------------------
        struct THeaderRequestConnect : THeaderC
        {
            THeaderRequestConnect();
            unsigned int random_num;
        };
        //-------------------------------------------------
        struct THeaderCheckRequestConnect : THeaderSR
        {
            THeaderCheckRequestConnect();
        };
        //-------------------------------------------------
        struct THeaderClientConnect : THeaderSR
        {
            THeaderClientConnect();
        };
        //-------------------------------------------------
        //-------------------------------------------------
        struct THeaderDisconnectClient : THeaderM
        {
            THeaderDisconnectClient();
        };
        //-------------------------------------------------
    }
}

#pragma pack(pop)
