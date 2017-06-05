/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef UpdaterGameItem_Terrain_BulletH
#define UpdaterGameItem_Terrain_BulletH

#include "TypeDef.h"
#include "UpdaterGameItem_Terrain.h"

class DllExport TUpdaterGameItem_Terrain_Bullet : public TUpdaterGameItem_Terrain
{
public:
	TUpdaterGameItem_Terrain_Bullet();
	virtual ~TUpdaterGameItem_Terrain_Bullet();

	virtual bool Update();
protected:
};

#endif
