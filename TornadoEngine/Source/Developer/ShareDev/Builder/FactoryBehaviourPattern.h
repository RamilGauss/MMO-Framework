/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryBehaviourPatternH
#define FactoryBehaviourPatternH

#include "TypeDef.h"
#include <string>

class IBehaviourPattern;

class DllExport TFactoryBehaviourPattern
{
public:
  TFactoryBehaviourPattern();
  virtual ~TFactoryBehaviourPattern();

  virtual int GetCount() = 0;
  virtual std::string GetPatternNameByIndex(int index) = 0;
  //virtual std::string GetPatternNameByIndex(int index) = 0;
  virtual IBehaviourPattern* MakePatternByName(std::string name) = 0;
};

#endif
