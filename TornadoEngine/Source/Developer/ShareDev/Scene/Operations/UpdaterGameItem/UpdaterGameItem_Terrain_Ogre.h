/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef UpdaterGameItem_Terrain_OgreH
#define UpdaterGameItem_Terrain_OgreH

#include "TypeDef.h"
#include "UpdaterGameItem_Terrain.h"

class DllExport TUpdaterGameItem_Terrain_Ogre : public TUpdaterGameItem_Terrain
{
public:
	TUpdaterGameItem_Terrain_Ogre();
	virtual ~TUpdaterGameItem_Terrain_Ogre();

	virtual bool Update();
protected:
};

#endif
