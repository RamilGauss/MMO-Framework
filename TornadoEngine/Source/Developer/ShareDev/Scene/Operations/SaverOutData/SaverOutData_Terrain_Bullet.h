/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SaverOutData_Terrain_BulletH
#define SaverOutData_Terrain_BulletH

#include "TypeDef.h"
#include "SaverOutData_Terrain.h"

class DllExport TSaverOutData_Terrain_Bullet : public TSaverOutData_Terrain
{
public:
	TSaverOutData_Terrain_Bullet();
	virtual ~TSaverOutData_Terrain_Bullet();

	virtual void Save();
private:
};

#endif
