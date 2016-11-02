/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_ZoneH
#define PatternContext_ZoneH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

class DllExport TPatternContext_Zone : public TBehaviourPatternContext
{
public:
  TPatternContext_Zone(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Zone();
};

#endif
