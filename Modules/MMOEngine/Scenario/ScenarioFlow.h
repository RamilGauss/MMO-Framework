/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SCENARIO_FLOW_H
#define SCENARIO_FLOW_H

#include "IScenario.h"
#include "ContextScFlow.h"
#include "MakerScenario.h"
#include "SrcEvent_ex.h"

#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  class TScenarioFlow : public IScenario
  {
    enum{eUp,eDown};
    struct THeaderFlow : public IScenario::TBaseHeader
    {
      THeaderFlow(){type = TMakerScenario::eFlow;}
    };
    //-------------------------------------------------
    struct THeaderSendUp : public THeaderFlow
    {
      THeaderSendUp(){subType = eUp;}
    };
    //-------------------------------------------------
    struct THeaderSendDown : public THeaderFlow
    {
      THeaderSendDown(){subType = eDown;}
    };
    //-------------------------------------------------
  public:
    TScenarioFlow();
    virtual ~TScenarioFlow();

    void SendUp(TBreakPacket bp, bool check);
    void SendDown(TBreakPacket bp, bool check);

    virtual void Recv(TDescRecvSession* pDesc);
  protected:
    virtual void DelayBegin();
  private:
    TContextScFlow* Context(){return (TContextScFlow*)mCurContext;}
    // для Send
    void HandlePacket(TBreakPacket& bp, bool check);
    // для Recv
    template <class TypeSrc>
    void Recv(TDescRecvSession* pDesc)
    {
      // защита от хака, могут прислать пакет меньшего размера, сервер выйдет за границы памяти и упадет
      if(pDesc->sizeData < sizeof(THeaderFlow))
        return;
      // создать событие
      TypeSrc* pEvent = new TypeSrc;
      // отцепиться от памяти, в которой содержится пакет
      pDesc->c.Unlink();
      // отдать память под контроль события
      pEvent->c.Entrust(pDesc->data, pDesc->sizeData);
			pEvent->data     = pDesc->data     + sizeof(THeaderFlow);
			pEvent->sizeData = pDesc->sizeData - sizeof(THeaderFlow);
      // откуда пришел пакет - сессия
      pEvent->id_session = pDesc->id_session;
      // добавить событие без копирования и указать истинное время создания события в транспорте
      //Context()->GetSE()->AddEventWithoutCopy(pEvent, sizeof(TypeSrc), pDesc->time_ms);

      Context()->GetSE()->AddEventWithoutCopy<TypeSrc>(pEvent, pDesc->time_ms);
    }
  };
  //-------------------------------------------------------------------
}

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif

#endif