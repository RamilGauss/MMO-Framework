/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TerrainItemH
#define TerrainItemH

#include "BaseItem.h"
#include <vector>

struct DllExport TTerrainItem : public TBaseItem
{
  struct TLOD
  {
    float distance;// максимальная дистанция
    std::string color;
    std::string normal;
  };
  typedef std::vector<TLOD> TVecLOD;

  struct TPoint
  {
    float x;
    float y;
    float h;
    float u;
    float v;
  };

  typedef std::vector<TPoint> TVecPoint;


  float mWidth;
  float mLength;

  TVecLOD   mGraphic;
  TVecPoint mHeightMap;

  TTerrainItem(std::string& name);
};

#endif
