/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPatternModel.h"

#include "PatternModel_Animated.h"
#include "PatternModel_Light.h"
#include "PatternModel_Model.h"
#include "PatternModel_Skybox.h"
#include "PatternModel_Sound.h"
#include "PatternModel_Terrain.h"
#include "PatternModel_Zone.h"

#include "ManagerNamePattern.h"
#include <boost/foreach.hpp>

TFactoryBehaviourPatternModel::TFactoryBehaviourPatternModel()
{
  mCB_Animated.Register(&TFactoryBehaviourPatternModel::MakeAnimated, this);
  mCB_Light.   Register(&TFactoryBehaviourPatternModel::MakeLight,    this);
  mCB_Model.   Register(&TFactoryBehaviourPatternModel::MakeModel,    this);
  mCB_Skybox.  Register(&TFactoryBehaviourPatternModel::MakeSkybox,   this);
  mCB_Sound.   Register(&TFactoryBehaviourPatternModel::MakeSound,    this);
  mCB_Terrain. Register(&TFactoryBehaviourPatternModel::MakeTerrain,  this);
  mCB_Zone.    Register(&TFactoryBehaviourPatternModel::MakeZone,     this);

  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Animated(), &mCB_Animated));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Light(),    &mCB_Light));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Model(),    &mCB_Model));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Skybox(),   &mCB_Skybox));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Sound(),    &mCB_Sound));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Terrain(),  &mCB_Terrain));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Zone(),     &mCB_Zone));
}
//----------------------------------------------------------------------------
TFactoryBehaviourPatternModel::~TFactoryBehaviourPatternModel()
{
  Done();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::Done()
{
  BOOST_FOREACH( TMapStrPtrModelVT& vt, mMapNamePtrModel )
    delete vt.second;
  mMapNamePtrModel.clear();
}
//----------------------------------------------------------------------------
TBehaviourPatternModel* TFactoryBehaviourPatternModel::GetPatternByName(std::string name)
{
  TBehaviourPatternModel* pBPM = NULL;
  TMapStrPtrModelIt fit = mMapNamePtrModel.find(name);
  if( fit==mMapNamePtrModel.end() )
  {
    pBPM = MakePatternByName(name);
    if( pBPM==NULL )
    {
      BL_FIX_BUG();
      return NULL;
    }
    pBPM->SetName(name);
    mMapNamePtrModel.insert(TMapStrPtrModelVT(name,pBPM));
  }
  else
    pBPM = fit->second;
  return pBPM;
}
//----------------------------------------------------------------------------
TBehaviourPatternModel* TFactoryBehaviourPatternModel::MakePatternByName(std::string name)
{
  TMapStrCBIt fit = mMapNameMakerPattern.find(name);
  if(fit==mMapNameMakerPattern.end())
    return NULL;
  TBehaviourPatternModel* p = NULL;
  fit->second->Notify(p);
  return p;
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::AddPattern(TMapStrCBVT& vt_cb)
{
  mMapNameMakerPattern.insert(vt_cb);
}
//----------------------------------------------------------------------------
int TFactoryBehaviourPatternModel::GetCount()
{
  return mMapNamePtrModel.size();
}
//----------------------------------------------------------------------------
std::string TFactoryBehaviourPatternModel::GetNameByIndex(int index)
{
  std::string name = "";
  if( index >= GetCount() || index < 0 )
    return name;

  TMapStrPtrModelIt bit = mMapNamePtrModel.begin();
  for( int i = 0 ; i <= index ; i++)
    bit++;
  name = bit->first;
  return name;
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeAnimated(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Animated();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeLight(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Light();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeModel(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Model();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeSkybox(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Skybox();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeSound(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Sound();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeTerrain(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Terrain();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel::MakeZone(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Zone();
}
//----------------------------------------------------------------------------
