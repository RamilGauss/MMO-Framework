/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SphericalDecartH
#define SphericalDecartH

#include "TypeDef.h"
#include "Struct3D.h"

class SHARE_EI TSphericalDecart
{
public:
	struct TSpheric
	{
		float fi;// относительно x
		float theta;// относительно z
		float r;
	};
	void Shperic2Decart(TSpheric& s,  nsStruct3D::TVector3&  d);
	void Decart2Shperic(nsStruct3D::TVector3&  d, TSpheric& s);
};

#endif
