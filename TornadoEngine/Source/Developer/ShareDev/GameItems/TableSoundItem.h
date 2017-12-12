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
#include <list>

#ifdef WIN32
#pragma pack(push, 1)
#endif

struct DllExport TTableSoundItem : public TBaseItem
{
  // внутреннее наполнение
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator               TMapStrStrIt;
  typedef TMapStrStr::value_type             TMapStrStrVT;

  typedef std::vector<TMapStrStr> TVectorMapStrStr;

  // для устранения warning C4503 - представлено в виде структур
  struct DllExport TVecAngleVecMap{  std::vector<TVectorMapStrStr> v;};// вектор индекса угла - вектор карты строка/строка
  struct DllExport TVecMaterial0Vec{ std::vector<TVecAngleVecMap>  v;};
  struct DllExport TVecMaterial1Vec{ std::vector<TVecMaterial0Vec> v;};
  struct DllExport TVecMass0Vec{     std::vector<TVecMaterial1Vec> v;};
  struct DllExport TVecMass1Vec{     std::vector<TVecMass0Vec>     v;};
  struct DllExport TVecVelocityVec{  std::vector<TVecMass1Vec>     v;};

  typedef std::map<float,int>      TMapFloatInt;
  typedef TMapFloatInt::iterator   TMapFloatIntIt;
  typedef TMapFloatInt::value_type TMapFloatIntVT;

  typedef std::map<std::string,int> TMapStrInt;
  typedef TMapStrInt::iterator      TMapStrIntIt;
  typedef TMapStrInt::value_type    TMapStrIntVT;

  TMapFloatInt mMapAngle, mMapMass, mMapVelocity;
  TMapStrInt mMapMaterial;

  // порядок поиска: velocity, mass, mass, material, material, angle
  TVecVelocityVec mVecParam;

public:
  TTableSoundItem(std::string& name);

  // использование 
  struct DllExport TIn
  {
    float velocity;// м/с
    float mass0;// кг
    float mass1;// кг
    std::string material0;// имя
    std::string material1;// имя
    float angle;// градусы
  };

  // наружу выдаст набор из вариантов описания звука - использующий класс сам решит какой вариант лучше
  bool Get(TIn& paramIn, TVectorMapStrStr& paramOut);

  struct DllExport TCombinationIndex
  {// набор индексов
    int velocity;
    int mass0;
    int mass1;
    int material0;
    int material1;
    int angle;
  };

  void Add(TCombinationIndex& combination, TVectorMapStrStr& vecMap);

  struct TCombiSound
  {
    TTableSoundItem::TMapStrInt       mapCombination;
    TTableSoundItem::TVectorMapStrStr vecSound;
  };
  typedef std::list<TCombiSound> TListCombiSound;
  struct TSetNameParam
  {
    std::string velocity;
    std::string mass0;
    std::string mass1;
    std::string material0;
    std::string material1;
    std::string angle;
  };
  void MakeList(TListCombiSound& listCombi, TSetNameParam& setNameParam);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
