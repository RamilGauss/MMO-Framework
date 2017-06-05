/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SaverGameItem_Terrain_BulletH
#define SaverGameItem_Terrain_BulletH

#include "TypeDef.h"
#include "SaverGameItem_Terrain.h"

class DllExport TSaverGameItem_Terrain_Bullet : public TSaverGameItem_Terrain
{
public:
	TSaverGameItem_Terrain_Bullet();
	virtual ~TSaverGameItem_Terrain_Bullet();

	virtual void Save();
private:
};

#endif
