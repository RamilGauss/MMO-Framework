/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CreaterTerrainH
#define CreaterTerrainH

#include "TypeDef.h"
#include <string>
#include "MathTools.h"

#include "OgreTerrainGroup.h"
#include "OgreTerrain.h"

class DllExport TCreaterTerrain
{
	Ogre::TerrainGroup*         mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainOptions;
public:
	TCreaterTerrain();

	struct TDescTarget
	{
		// нужно для имени
		std::string nameMap;
		int iX;
		int iY;

		nsMathTools::TVector3 position;// by center
		// квадратная плоскость
		float worldSize;
		int   size;// must be 2^n + 1, [2,3,5,9,17,33,65,129,257,513,1025,2049,..]
		// высота 
		float heightFlat;
	};

	void Create(TDescTarget& descTarget, 
		Ogre::TerrainGroup* pTG, Ogre::TerrainGlobalOptions* pTGO);
private:
	void setupContent();
};

#endif
