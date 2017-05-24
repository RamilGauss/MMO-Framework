/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseOperation_PatternH
#define BaseOperation_PatternH

#include "TypeDef.h"

class TBehaviourPattern;

class DllExport TBaseOperation_Pattern
{
public:
	virtual void SetPattern(TBehaviourPattern* pPattern) = 0;
};

#endif
