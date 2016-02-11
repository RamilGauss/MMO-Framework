/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TableSoundItem.h"

TTableSoundItem::TTableSoundItem(std::string& name):
TBaseItem(name)
{

}
//--------------------------------------------------------------------------------
bool TTableSoundItem::Get(TIn& paramIn, TVectorMapStrStr& paramOut)
{
  // ищем по значению - индекс в векторе
  TMapFloatIntIt VelocityIt = mMapAngle.lower_bound(paramIn.velocity);
  if(VelocityIt==mMapAngle.end())
    return false;

  TMapFloatIntIt Mass0It = mMapMass.lower_bound(paramIn.mass0);
  if(Mass0It==mMapMass.end())
    return false;

  TMapFloatIntIt Mass1It = mMapMass.lower_bound(paramIn.mass1);
  if(Mass1It==mMapMass.end())
    return false;

  TMapStrIntIt Material0It = mMapMaterial.find(paramIn.material0);
  if(Material0It==mMapMaterial.end())
    return false;

  TMapStrIntIt Material1It = mMapMaterial.find(paramIn.material1);
  if(Material1It==mMapMaterial.end())
    return false;

  TMapFloatIntIt AngleIt = mMapAngle.lower_bound(paramIn.angle);
  if(AngleIt==mMapAngle.end())
    return false;

  // ищем по индексам комбинацию
  // скорость
  std::map<int, TMapMass1Map>::iterator ParamMass1It = mMapParamMap.m.find(VelocityIt->second);
  if(ParamMass1It==mMapParamMap.m.end())
    return false;
  // масса 1
  std::map<int, TMapMass0Map>::iterator ParamMass0It = ParamMass1It->second.m.find(Mass1It->second);
  if(ParamMass0It==ParamMass1It->second.m.end())
    return false;
  // масса 0
  std::map<int, TMapMaterial1Map>::iterator ParamMaterial1It = ParamMass0It->second.m.find(Mass0It->second);
  if(ParamMaterial1It==ParamMass0It->second.m.end())
    return false;
  // материал 1
  std::map<int, TMapMaterial0Map>::iterator ParamMaterial0It = ParamMaterial1It->second.m.find(Material1It->second);
  if(ParamMaterial0It==ParamMaterial1It->second.m.end())
    return false;
  // материал 0
  std::map<int, TMapAngleMap>::iterator ParamAngleIt = ParamMaterial0It->second.m.find(Material0It->second);
  if(ParamAngleIt==ParamMaterial0It->second.m.end())
    return false;
  // угол
  std::map<int, TVectorMapStrStr>::iterator ParamMapStrStrIt = ParamAngleIt->second.m.find(AngleIt->second);
  if(ParamMapStrStrIt==ParamAngleIt->second.m.end())
    return false;

  paramOut = ParamMapStrStrIt->second;
  return true;
}
//--------------------------------------------------------------------------------
void TTableSoundItem::Add(TCombination& combination, TVectorMapStrStr& vecMap)
{
  TMapAngleMap     angleMap;
  TMapMaterial0Map material0Map;
  TMapMaterial1Map material1Map;
  TMapMass0Map     mass0Map; 
  TMapMass1Map     mass1Map;

  angleMap.m.    insert(std::map<int, TVectorMapStrStr>::value_type(combination.angle,     vecMap));
  material0Map.m.insert(std::map<int, TMapAngleMap    >::value_type(combination.material0, angleMap));
  material1Map.m.insert(std::map<int, TMapMaterial0Map>::value_type(combination.material1, material0Map));
  mass0Map.m.    insert(std::map<int, TMapMaterial1Map>::value_type(combination.mass0,     material1Map));
  mass1Map.m.    insert(std::map<int, TMapMass0Map    >::value_type(combination.mass1,     mass0Map));
  mMapParamMap.m.insert(std::map<int, TMapMass1Map    >::value_type(combination.velocity,  mass1Map));
}
//--------------------------------------------------------------------------------
