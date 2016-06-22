/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBehaviourPatternH
#define IBehaviourPatternH

#include "TypeDef.h"
#include "ContainerTypes.h"

class DllExport IBehaviourPattern
{
public:
  IBehaviourPattern();
  virtual ~IBehaviourPattern();

  // Сериализация
  virtual bool SetInternalState(TContainer c) = 0;
  virtual TContainer GetInternalState() = 0;

  // Визуализация

  // Применить 
};

#endif
