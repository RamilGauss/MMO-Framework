/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_LightH
#define PatternContext_LightH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

class DllExport TPatternContext_Light : public TBehaviourPatternContext
{
public:
  TPatternContext_Light(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Light();
};

#endif
