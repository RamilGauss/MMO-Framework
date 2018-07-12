/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "IScenarioContext.h"
#include "BreakPacket.h"

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContextScSynchroSlave : public IScenarioContext
  {
    unsigned char mLoadProcent;
  public:
    TContextScSynchroSlave();
    virtual ~TContextScSynchroSlave();

    void SetLoadProcent(unsigned char v);
    unsigned char GetLoadProcent();
  private:
  };
}  
