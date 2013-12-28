/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SphericalDecart.h"
#include <math.h>

using namespace nsStruct3D;

void TSphericalDecart::Shperic2Decart(TSpheric& s, TVector3&  d)
{
	d.x = s.r*sin(s.theta)*cos(s.fi);
	d.y = s.r*sin(s.theta)*sin(s.fi);
	d.z = s.r*cos(s.theta);
}
//-----------------------------------------------------------------------
void TSphericalDecart::Decart2Shperic(TVector3&  d, TSpheric& s)
{
	s.r = sqrt(d.x*d.x+d.y*d.y+d.z*d.z);
	s.theta = atan2(sqrt(d.x*d.x+d.y*d.y),d.z);
	s.fi = atan2(d.y,d.x);
}
//-----------------------------------------------------------------------
