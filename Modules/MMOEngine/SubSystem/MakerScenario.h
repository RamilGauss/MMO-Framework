/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MAKER_SCENARIO_H
#define MAKER_SCENARIO_H

#include <set>

namespace nsMMOEngine
{
  class IScenario;
  class TMakerScenario
  {
    typedef std::set<IScenario*> TSetPtr;
    TSetPtr mSetMakeSc;
  public:
    enum
    {
      eDisconnectClient,
      eFlow,
      eLoginClient,
      eLoginMaster,
      eLoginSlave,
      eRecommutationClient,
      eSendToClient,
      eSynchroSlave,
    };

    TMakerScenario();
    ~TMakerScenario();
    IScenario* New(unsigned int ID_Implementation);
    void Delete(IScenario* p);
  };
}
#endif