/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_AnimatedH
#define Pattern_AnimatedH

#include "TypeDef.h"
#include "BehaviourPattern.h"

class DllExport TPattern_Animated : public TBehaviourPattern
{
public:
  TPattern_Animated();
  virtual ~TPattern_Animated();

	virtual TManagerNamePattern::eBaseType GetBaseType();
};

#endif
