/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_SkydomeH
#define Pattern_SkydomeH

#include "TypeDef.h"
#include "BehaviourPattern.h"

class DllExport TPattern_Skydome : public TBehaviourPattern
{
public:
	TPattern_Skydome();
	virtual ~TPattern_Skydome();

	virtual TManagerNamePattern::eBaseType GetBaseType();
};

#endif
