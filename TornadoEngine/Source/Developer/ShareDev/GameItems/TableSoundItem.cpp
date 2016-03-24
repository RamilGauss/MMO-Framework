/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TableSoundItem.h"
#include <boost/foreach.hpp>

TTableSoundItem::TTableSoundItem(std::string& name):
TBaseItem(name, TFactoryGameItem::TableSound)
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
  if((int)mVecParam.v.size() <= VelocityIt->second)
    return false;
  TVecMass1Vec& ParamMass1 = mVecParam.v[VelocityIt->second];
  // масса 1
  if((int)ParamMass1.v.size() <= Mass1It->second)
    return false;
  TVecMass0Vec& ParamMass0 = ParamMass1.v[Mass1It->second];
  // масса 0
  if((int)ParamMass0.v.size() <= Mass0It->second)
    return false;
  TVecMaterial1Vec& ParamMaterial1 = ParamMass0.v[Mass0It->second];
  // материал 1
  if((int)ParamMaterial1.v.size() <= Material1It->second)
    return false;
  TVecMaterial0Vec& ParamMaterial0 = ParamMaterial1.v[Material1It->second];
  // материал 0
  if((int)ParamMaterial0.v.size() <= Material0It->second)
    return false;
  TVecAngleVecMap& ParamAngle = ParamMaterial0.v[Material0It->second];
  // угол
  if((int)ParamAngle.v.size() <= AngleIt->second)
    return false;
  paramOut = ParamAngle.v[AngleIt->second];
  return true;
}
//--------------------------------------------------------------------------------
void TTableSoundItem::Add(TCombinationIndex& combination, TVectorMapStrStr& vecMap)
{ 
  // проверка наличия индекса
  int dVelocity = combination.velocity - mVecParam.v.size() + 1;
  for( int i = 0 ; i < dVelocity ; i++ )
    mVecParam.v.push_back(TVecMass1Vec());
  TVecMass1Vec& vecMass1 = mVecParam.v[combination.velocity];
  //
  int dMass1 = combination.mass1 - vecMass1.v.size() + 1;
  for( int i = 0 ; i < dMass1 ; i++ )
    vecMass1.v.push_back(TVecMass0Vec());
  TVecMass0Vec& vecMass0 = vecMass1.v[combination.mass1];
  //
  int dMass0 = combination.mass0 - vecMass0.v.size() + 1;
  for( int i = 0 ; i < dMass0 ; i++ )
    vecMass0.v.push_back(TVecMaterial1Vec());
  TVecMaterial1Vec& vecMaterial1 = vecMass0.v[combination.mass0];
  //
  int dMaterial1 = combination.material1 - vecMaterial1.v.size() + 1;
  for( int i = 0 ; i < dMaterial1 ; i++ )
    vecMaterial1.v.push_back(TVecMaterial0Vec());
  TVecMaterial0Vec& vecMaterial0 = vecMaterial1.v[combination.material1];
  //
  int dMaterial0 = combination.material0 - vecMaterial0.v.size() + 1;
  for( int i = 0 ; i < dMaterial0 ; i++ )
    vecMaterial0.v.push_back(TVecAngleVecMap());
  TVecAngleVecMap& vecAngle = vecMaterial0.v[combination.material0];
  //
  int dAngle = combination.angle - vecAngle.v.size() + 1;
  for( int i = 0 ; i < dAngle ; i++ )
    vecAngle.v.push_back(TVectorMapStrStr());
  TVectorMapStrStr& vecMapStrStr = vecAngle.v[combination.angle];
  vecMapStrStr = vecMap;
}
//--------------------------------------------------------------------------------
void TTableSoundItem::MakeList(std::list<TCombiSound>& listCombi, TSetNameParam& setNameParam)
{
  int iMass1 = 0;
  BOOST_FOREACH(TVecMass1Vec& vecMass1, mVecParam.v)// velocity
  {
    int iMass0 = 0;
    BOOST_FOREACH(TVecMass0Vec& vecMass0, vecMass1.v)// mass1
    {
      int iMaterial1 = 0;
      BOOST_FOREACH(TVecMaterial1Vec& vecMaterial1, vecMass0.v)// mass0
      {
        int iMaterial0 = 0;
        BOOST_FOREACH(TVecMaterial0Vec& vecMaterial0, vecMaterial1.v)// material1
        {
          int iAngle = 0;
          BOOST_FOREACH(TVecAngleVecMap& vecAngle, vecMaterial0.v)// material0
          {
            int iVec = 0;
            BOOST_FOREACH(TVectorMapStrStr& vecMapStrStr, vecAngle.v)// angle
            {
              if(vecMapStrStr.size() > 0)
              {
                TCombiSound combiSound;
                combiSound.mapCombination.insert(TMapStrIntVT(setNameParam.velocity,  iMass1));
                combiSound.mapCombination.insert(TMapStrIntVT(setNameParam.mass1,     iMass0));
                combiSound.mapCombination.insert(TMapStrIntVT(setNameParam.mass0,     iMaterial1));
                combiSound.mapCombination.insert(TMapStrIntVT(setNameParam.material1, iMaterial0));
                combiSound.mapCombination.insert(TMapStrIntVT(setNameParam.material0, iAngle));
                combiSound.mapCombination.insert(TMapStrIntVT(setNameParam.angle,     iVec));
                combiSound.vecSound = vecMapStrStr;
                listCombi.push_back(combiSound);
              }
              iVec++;
            }
            iAngle++;
          }
          iMaterial0++;
        }
        iMaterial1++;
      }
      iMass0++;
    }
    iMass1++;
  }
}
//-------------------------------------------------------------------------------------------------------
