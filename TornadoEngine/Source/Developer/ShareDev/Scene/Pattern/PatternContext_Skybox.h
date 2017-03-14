/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_SkyboxH
#define PatternContext_SkyboxH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

class DllExport TPatternContext_Skybox : public TBehaviourPatternContext
{
public:
  TPatternContext_Skybox(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Skybox();

};

#endif
