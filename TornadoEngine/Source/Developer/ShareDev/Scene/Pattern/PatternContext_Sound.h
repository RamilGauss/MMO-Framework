/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_SoundH
#define PatternContext_SoundH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

class DllExport TPatternContext_Sound : public TBehaviourPatternContext
{
public:
  TPatternContext_Sound(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Sound();
};

#endif
