/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SaverGameItem_Terrain_OgreH
#define SaverGameItem_Terrain_OgreH

#include "TypeDef.h"
#include "SaverGameItem_Terrain.h"

class DllExport TSaverGameItem_Terrain_Ogre : public TSaverGameItem_Terrain
{
public:
	TSaverGameItem_Terrain_Ogre();
	virtual ~TSaverGameItem_Terrain_Ogre();

	virtual void Save();
private:
};

#endif
