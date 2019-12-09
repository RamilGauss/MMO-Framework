/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenarioContext.h"
#include "BreakPacket.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
  class TContextScDisconnectClient : public IScenarioContext
  {
    unsigned int mIDClient;
  public:
    TContextScDisconnectClient();
    virtual ~TContextScDisconnectClient();

    unsigned int GetIDClient();
    void SetIDClient( unsigned int val );
  private:
  };
}