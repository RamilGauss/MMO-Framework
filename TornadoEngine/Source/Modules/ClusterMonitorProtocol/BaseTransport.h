/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "DstEvent.h"
#include "Base.h"
#include "MakerNetTransport.h"

namespace nsClusterMonitorProtocol
{
  class DllExport TBaseTransport : public TDstEvent, public TSrcEvent
  {
    TMakerNetTransport mMakerNetTransport;
    nsMMOEngine::TBase* mBase = nullptr;
  protected:
    unsigned char mSubNet;
  public:
    TBaseTransport( nsMMOEngine::TBase* pBase );
    virtual ~TBaseTransport();

    void Open( unsigned short port, unsigned char subNet );

    void Work();
  };
}