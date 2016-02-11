/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TableSoundItemH
#define TableSoundItemH

#include "BaseItem.h"
#include <map>
#include <string>
#include <vector>

struct DllExport TTableSoundItem : public TBaseItem
{
  // внутреннее наполнение
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator   						TMapStrStrIt;
  typedef TMapStrStr::value_type 						TMapStrStrVT;

  typedef std::vector<TMapStrStr> TVectorMapStrStr;

  // для устранения warning C4503 - представлено в виде структур
  struct DllExport TMapAngleMap{     std::map<int, TVectorMapStrStr> m;};
  struct DllExport TMapMaterial0Map{ std::map<int, TMapAngleMap>     m;};
  struct DllExport TMapMaterial1Map{ std::map<int, TMapMaterial0Map> m;};
  struct DllExport TMapMass0Map{     std::map<int, TMapMaterial1Map> m;};
  struct DllExport TMapMass1Map{     std::map<int, TMapMass0Map>     m;};
  struct DllExport TMapVelocityMap{  std::map<int, TMapMass1Map>     m;};

  typedef std::map<float,int>      TMapFloatInt;
  typedef TMapFloatInt::iterator   TMapFloatIntIt;
  typedef TMapFloatInt::value_type TMapFloatIntVT;

  typedef std::map<std::string,int> TMapStrInt;
  typedef TMapStrInt::iterator      TMapStrIntIt;
  typedef TMapStrInt::value_type    TMapStrIntVT;

  TMapFloatInt mMapAngle, mMapMass, mMapVelocity;
  TMapStrInt mMapMaterial;

  // порядок поиска: velocity, mass, mass, material, material, angle
  TMapVelocityMap mMapParamMap;

public:
	TTableSoundItem(std::string& name);

  // использование 
  struct DllExport TIn
  {
    float velocity;
    float mass0;
    float mass1;
    std::string material0;
    std::string material1;
    float angle;
  };

  // наружу выдаст набор из вариантов описания звука - использующий класс сам решит какой вариант лучше
  bool Get(TIn& paramIn, TVectorMapStrStr& paramOut);


  struct DllExport TCombination
  {
    int velocity;
    int mass0;
    int mass1;
    int material0;
    int material1;
    int angle;
  };

  void Add(TCombination& combination, TVectorMapStrStr& vecMap);
};

#endif
