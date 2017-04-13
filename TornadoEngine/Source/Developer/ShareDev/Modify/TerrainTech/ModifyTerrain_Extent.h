/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModifyTerrain_ExtentH
#define ModifyTerrain_ExtentH

#include "TypeDef.h"
#include <string>
#include "MathTools.h"

#include "OgreTerrainGroup.h"
#include "OgreTerrain.h"

class DllExport TModifyTerrain_Extent
{
	Ogre::TerrainGroup*         mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainOptions;
public:
	TModifyTerrain_Extent();

	struct TLayer
	{
		float worldSize;
		std::string textureNames_Color;
		std::string textureNames_Normal;
	};

	struct TDescTarget
	{
		// нужно дл€ имени
		std::string nameMap;
		short iX;// [-32000..32000]
		short iY;// [-32000..32000]

		// геометрические параметры
		nsMathTools::TVector3 position;// by center
		// квадратна€ плоскость
		float worldSize;// 0..10000 у.е. (в разумных пределах)
		int   size;// must be 2^n + 1, [2,3,5,9,17,33,65,129,257,513,1025,2049,..]
		// высота 
		float heightFlat;

		// графические параметры
		// меньше 2 слоЄв быть не может, один слой - минимум, 2 - максимум на границе высот
		std::list<TLayer> listLayer;
		TDescTarget();
	};

	void Setup(TDescTarget& descTarget, 
		Ogre::TerrainGroup* pTG, Ogre::TerrainGlobalOptions* pTGO);
private:
	void setupContent();
};

#endif
