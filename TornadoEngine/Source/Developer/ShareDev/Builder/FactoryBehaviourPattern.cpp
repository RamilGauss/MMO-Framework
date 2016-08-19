/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPattern.h"
#include "Pattern_Animated.h"
#include "Pattern_Light.h"
#include "Pattern_Model.h"
#include "Pattern_Skybox.h"
#include "Pattern_Sound.h"
#include "Pattern_Terrain.h"
#include "Pattern_Zone.h"
#include "ManagerNamePattern.h"

TFactoryBehaviourPattern::TFactoryBehaviourPattern()
{
  mCB_Animated.Register(&TFactoryBehaviourPattern::MakeAnimated, this);
  mCB_Light.   Register(&TFactoryBehaviourPattern::MakeLight,    this);
  mCB_Model.   Register(&TFactoryBehaviourPattern::MakeModel,    this);
  mCB_Skybox.  Register(&TFactoryBehaviourPattern::MakeSkybox,   this);
  mCB_Sound.   Register(&TFactoryBehaviourPattern::MakeSound,    this);
  mCB_Terrain. Register(&TFactoryBehaviourPattern::MakeTerrain,  this);
  mCB_Zone.    Register(&TFactoryBehaviourPattern::MakeZone,     this);

  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Animated(), &mCB_Animated));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Light(),    &mCB_Light));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Model(),    &mCB_Model));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Skybox(),   &mCB_Skybox));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Sound(),    &mCB_Sound));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Terrain(),  &mCB_Terrain));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Zone(),     &mCB_Zone));
}
//----------------------------------------------------------------------------
TFactoryBehaviourPattern::~TFactoryBehaviourPattern()
{

}
//----------------------------------------------------------------------------
TBehaviourPattern* TFactoryBehaviourPattern::MakePatternByName(std::string name)
{
  TMapStrCBIt fit = mMapNameMakerPattern.find(name);
  if(fit==mMapNameMakerPattern.end())
    return NULL;
  TBehaviourPattern* p = NULL;
  fit->second->Notify(p);
  return p;
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::AddPattern(TMapStrCBVT& vt_cb)
{
  mMapNameMakerPattern.insert(vt_cb);
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeAnimated(TBehaviourPattern*& p)
{
  p = new TPattern_Animated();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeLight(TBehaviourPattern*& p)
{
  p = new TPattern_Light();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeModel(TBehaviourPattern*& p)
{
  p = new TPattern_Model();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeSkybox(TBehaviourPattern*& p)
{
  p = new TPattern_Skybox();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeSound(TBehaviourPattern*& p)
{
  p = new TPattern_Sound();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeTerrain(TBehaviourPattern*& p)
{
  p = new TPattern_Terrain();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeZone(TBehaviourPattern*& p)
{
  p = new TPattern_Zone();
}
//----------------------------------------------------------------------------
