/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modify_Terrain_OgreH
#define Modify_Terrain_OgreH

#include "TypeDef.h"

#include "Modify_Terrain.h"

class DllExport TModify_Terrain_Ogre : public TModify_Terrain
{
public:
	TModify_Terrain_Ogre();

	virtual void Setup(TDescTarget& descTarget);
protected:
	void setupContent();

};

#endif
