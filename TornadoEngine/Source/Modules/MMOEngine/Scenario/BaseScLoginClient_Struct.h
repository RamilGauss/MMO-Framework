/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "IScenario.h"
#include "DescRecvSession.h"
#include "ScenarioBaseHeader.h"

namespace nsMMOEngine
{
  namespace nsLoginClientStruct
  {
    enum
    {
      // начало, множество ветвлений
      eTryLoginC2M,
      eRequestM2SS,
      eCheckRequestSS2M,
      eResultLoginM2C,
      eLeaveQueueC2M,
      //-------------------------------
      // прямолинейный обмен пакетами
      eInfoClientM2S,
      eCheckInfoClientS2M,
      eInfoSlaveM2C,
      eCheckInfoSlaveC2M,
      eConnectToSlaveC2S,
      eClientConnectS2M,
      eCheckClientConnectM2S,
      eCheckConnectToSlaveS2C,

      eDisconnectClientM2S,
    };
    enum
    {
      eClient,
      eSlave,
      eMaster,
      eSuperServer,
    };
    //-------------------------------------------------
#ifdef WIN32
#pragma pack(push, 1)
#endif
    struct THeader : public TScenarioBaseHeader
    {
      THeader();
      unsigned char from;
      unsigned int  clientKey;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderC : public THeader
    {
      THeaderC()
      {
        from = eClient;
      }
    }_PACKED;
    struct THeaderM : public THeader
    {
      THeaderM()
      {
        from = eMaster;
      }
    }_PACKED;
    struct THeaderS : public THeader
    {
      THeaderS()
      {
        from = eSlave;
      }
    }_PACKED;
    struct THeaderSS : public THeader
    {
      THeaderSS()
      {
        from = eSuperServer;
      }
    }_PACKED;
    //-------------------------------------------------
    struct THeaderTryLoginC2M : THeaderC
    {
      THeaderTryLoginC2M();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderRequestM2SS : THeaderM
    {
      THeaderRequestM2SS();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckRequestSS2M : THeaderSS
    {
      THeaderCheckRequestSS2M();
      char isExistInSystem;// данный клиент присутствует в составе
    }_PACKED;
    //-------------------------------------------------
    struct THeaderResultLoginM2C : THeaderM
    {
      enum{ eAccept, eReject, eQueue };
      THeaderResultLoginM2C();
      char result;
      int numInQueue;
      int sizeResClient;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderLeaveQueueC2M : public THeaderC
    {
      THeaderLeaveQueueC2M();
    }_PACKED;
    //------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------
    struct THeaderInfoClientM2S : public THeaderM
    {
      THeaderInfoClientM2S();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckInfoClientS2M : public THeaderS
    {
      THeaderCheckInfoClientS2M();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderInfoSlaveM2C : public THeaderM
    {
      THeaderInfoSlaveM2C();
      TIP_Port ip_port_slave;
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckInfoSlaveC2M : public THeaderC
    {
      THeaderCheckInfoSlaveC2M();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderConnectToSlaveC2S : public THeaderC
    {
      THeaderConnectToSlaveC2S();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderClientConnectS2M : public THeaderS
    {
      THeaderClientConnectS2M();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckClientConnectM2S : public THeaderM
    {
      THeaderCheckClientConnectM2S();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderCheckConnectToSlaveS2C : public THeaderS
    {
      THeaderCheckConnectToSlaveS2C();
    }_PACKED;
    //-------------------------------------------------
    struct THeaderDisconnectClientM2S : public THeaderM
    {
      THeaderDisconnectClientM2S();
    }_PACKED;
    //-------------------------------------------------
#ifdef WIN32
#pragma pack(pop)
#endif
  }
}
