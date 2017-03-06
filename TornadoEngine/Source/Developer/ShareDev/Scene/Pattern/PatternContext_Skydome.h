/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_SkydomeH
#define PatternContext_SkydomeH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"

class DllExport TPatternContext_Skydome : public TBehaviourPatternContext
{
public:
	TPatternContext_Skydome(TBehaviourPatternModel* pModel);
	virtual ~TPatternContext_Skydome();
};

#endif
