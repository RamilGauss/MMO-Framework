/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <time.h>

#include "DescRecvSession.h"
#include "ScenarioBaseHeader.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

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
    }_PACKED;
    //-------------------------------------------------
    struct THeaderC  : public THeader{ THeaderC (){from=eClient;}}_PACKED;
    struct THeaderM  : public THeader{ THeaderM (){from=eMaster;}}_PACKED;
    struct THeaderSD : public THeader{ THeaderSD (){from=eSlaveDonor;}}_PACKED;
    struct THeaderSR : public THeader{ THeaderSR (){from=eSlaveRecipient;}}_PACKED;
    //-------------------------------------------------
    struct THeaderBeginDonor : THeaderM
    {
      THeaderBeginDonor();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderBeginClient : THeaderSD
    {
      THeaderBeginClient();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckBeginClient : THeaderC
    {
      THeaderCheckBeginClient();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckBeginDonor : THeaderSD
    {
      THeaderCheckBeginDonor();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderBeginRecipient : THeaderM
    {
      THeaderBeginRecipient();
      unsigned int random_num;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckBeginRecipient : THeaderSR
    {
      THeaderCheckBeginRecipient();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderInfoRecipientToDonor : THeaderM
    {
      THeaderInfoRecipientToDonor();
      TIP_Port ip_port_recipient;
      unsigned int random_num;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderInfoRecipientToClient : THeaderSD
    {
      THeaderInfoRecipientToClient();
      TIP_Port ip_port_recipient;
      unsigned int random_num;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckInfoRecipient : THeaderC
    {
      THeaderCheckInfoRecipient();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderRequestConnect : THeaderC
    {
      THeaderRequestConnect();
      unsigned int random_num;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckRequestConnect : THeaderSR
    {
      THeaderCheckRequestConnect();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderClientConnect : THeaderSR
    {
      THeaderClientConnect();
    }_PACKED;
    //-------------------------------------------------
    //-------------------------------------------------
    struct THeaderDisconnectClient : THeaderM
    {
      THeaderDisconnectClient();
    }_PACKED;
    //-------------------------------------------------
  }
}

#ifdef WIN32
#pragma pack(pop)
#endif
