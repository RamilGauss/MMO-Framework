/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef OtherClassH
#define OtherClassH

#include "GeneratedClass.h"

class OtherClass : public GeneratedClass
{
public:
	bool operator < ( const OtherClass& right ) const
	{
		if( mID < right.mID )
			return true;
		return false;
	}
};

#endif
