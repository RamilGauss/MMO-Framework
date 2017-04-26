/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modify_TerrainH
#define Modify_TerrainH

#include "TypeDef.h"
#include "MathTools.h"

#include "Operation_Terrain.h"

#include <string>
#include <list>

class DllExport TModify_Terrain : public TOperation_Terrain
{
public:
	TModify_Terrain();

	struct TLayer
	{
		float worldSize;
		std::string textureNames_Color;
		std::string textureNames_Normal;
	};
	struct TDescTarget
	{// нужно дл€ имени
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
		// графические параметры, меньше 2 слоЄв быть не может, 
		// один слой - дл€ минимума высоты, последний - дл€ максимума высоты
		std::list<TLayer> listLayer;
		TDescTarget();
	};

	virtual void Setup(TDescTarget& descTarget) = 0;
private:
};

#endif
