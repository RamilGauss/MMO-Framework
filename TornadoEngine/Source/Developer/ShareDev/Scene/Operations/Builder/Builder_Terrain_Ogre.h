/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_Terrain_OgreH
#define Builder_Terrain_OgreH

#include "TypeDef.h"
#include "Builder_Terrain.h"
#include "BuilderTool_Terrain_Ogre.h"

class DllExport TBuilder_Terrain_Ogre : public TBuilder_Terrain
{
	TBuilderTool_Terrain_Ogre mBuilder;
public:
	TBuilder_Terrain_Ogre();
	virtual ~TBuilder_Terrain_Ogre();

	virtual void Begin();
	virtual void Load(int x, int y);
	virtual void End();
protected:
};

#endif
