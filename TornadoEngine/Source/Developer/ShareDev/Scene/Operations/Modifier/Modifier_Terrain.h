/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modifier_TerrainH
#define Modifier_TerrainH

#include "TypeDef.h"
#include "MathTools.h"

#include "Operation_Terrain.h"
#include "TerrainItem.h"

#include <string>
#include <list>

class DllExport TModifier_Terrain : public TOperation_Terrain
{
public:
  TModifier_Terrain();

  struct DllExport TLayer
  {
    float worldSize;
    std::string textureNames_Color;
    std::string textureNames_Normal;
  };
  struct DllExport TDescTarget
  {
    TTerrainItem::TConvention diapX_Part;
    TTerrainItem::TConvention diapY_Part;
    // квадратная плоскость
    float worldSizePart;// 0..10000 у.е. (в разумных пределах)
    int   sizePart;// must be 2^n + 1, [2,3,5,9,17,33,65,129,257,513,1025,2049,..]
    // графические параметры, меньше 2 слоёв быть не может, 
    // один слой - для минимума высоты, последний - для максимума высоты

    float height;

    float inputScale;
    float inputBias;

    std::list<TLayer> listLayer;
    TDescTarget();
  };

  virtual void SetFormat(TDescTarget& descTarget) = 0;
private:
};

#endif
