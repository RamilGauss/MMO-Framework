/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryBehaviourPattern_EoWMH
#define FactoryBehaviourPattern_EoWMH

#include "IFactoryBehaviourPattern.h"

class TFactoryBehaviourPattern_EoWM : public IFactoryBehaviourPattern
{
public:
  TFactoryBehaviourPattern_EoWM();
  virtual ~TFactoryBehaviourPattern_EoWM();

  virtual int GetCount();
  virtual std::string GetPatternNameByIndex(int index);
  virtual IBehaviourPattern* MakePatternByName(std::string name);
};

#endif
