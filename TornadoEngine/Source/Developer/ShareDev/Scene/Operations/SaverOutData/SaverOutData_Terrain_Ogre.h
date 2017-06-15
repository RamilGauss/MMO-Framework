/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SaverOutData_Terrain_OgreH
#define SaverOutData_Terrain_OgreH

#include "TypeDef.h"
#include "SaverOutData_Terrain.h"

class DllExport TSaverOutData_Terrain_Ogre : public TSaverOutData_Terrain
{
public:
	TSaverOutData_Terrain_Ogre();
	virtual ~TSaverOutData_Terrain_Ogre();

	virtual void Save();
private:
};

#endif
