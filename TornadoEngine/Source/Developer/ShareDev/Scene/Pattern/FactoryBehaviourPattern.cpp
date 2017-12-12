/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPattern.h"

#include "Pattern_MapParameter.h"
#include "Pattern_Animated.h"
#include "Pattern_Light.h"
#include "Pattern_Model.h"
#include "Pattern_Skybox.h"
#include "Pattern_Skydome.h"
#include "Pattern_Skyplane.h"
#include "Pattern_Sound.h"
#include "Pattern_Terrain.h"
#include "Pattern_Volume.h"

#include "ManagerNamePattern.h"
#include <boost/foreach.hpp>

TFactoryBehaviourPattern::TFactoryBehaviourPattern()
{
  mCB_MapParameter.Register(&TFactoryBehaviourPattern::MakeMapParameter, this);
  mCB_Animated.     Register(&TFactoryBehaviourPattern::MakeAnimated,      this);
  mCB_Light.        Register(&TFactoryBehaviourPattern::MakeLight,         this);
  mCB_Model.        Register(&TFactoryBehaviourPattern::MakeModel,         this);
  mCB_Skybox.       Register(&TFactoryBehaviourPattern::MakeSkybox,        this);
  mCB_Skydome.      Register(&TFactoryBehaviourPattern::MakeSkydome,       this);
  mCB_Skyplane.     Register(&TFactoryBehaviourPattern::MakeSkyplane,      this);
  mCB_Sound.        Register(&TFactoryBehaviourPattern::MakeSound,         this);
  mCB_Terrain.      Register(&TFactoryBehaviourPattern::MakeTerrain,       this);
  mCB_Volume.       Register(&TFactoryBehaviourPattern::MakeVolume,          this);

  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::MapParameter(), &mCB_MapParameter));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Animated(),      &mCB_Animated));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Light(),         &mCB_Light));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Model(),         &mCB_Model));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Skybox(),        &mCB_Skybox));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Skydome(),       &mCB_Skydome));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Skyplane(),      &mCB_Skyplane));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Sound(),         &mCB_Sound));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Terrain(),       &mCB_Terrain));
  mMapNameMakerPattern.insert(TMapStrCBVT(TManagerNamePattern::Volume(),          &mCB_Volume));
}
//----------------------------------------------------------------------------
TFactoryBehaviourPattern::~TFactoryBehaviourPattern()
{
  Done();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::Done()
{

}
//----------------------------------------------------------------------------
TBehaviourPattern* TFactoryBehaviourPattern::GetPatternByName(std::string name)
{
  TBehaviourPattern* pBPM = MakePatternByName(name);
  if( pBPM==NULL )
  {
    BL_FIX_BUG();
    return NULL;
  }
  pBPM->SetName(name);
  return pBPM;
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
int TFactoryBehaviourPattern::GetCount()
{
  return mMapNameMakerPattern.size();
}
//----------------------------------------------------------------------------
std::string TFactoryBehaviourPattern::GetNameByIndex(int index)
{
  std::string name = "";
  if( index >= GetCount() || index < 0 )
    return name;

  TMapStrCBIt bit = mMapNameMakerPattern.begin();
  for( int i = 0 ; i <= index ; i++)
    bit++;
  name = bit->first;
  return name;
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeMapParameter(TBehaviourPattern*& p)
{
  p = new TPattern_MapParameter();
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
void TFactoryBehaviourPattern::MakeSkydome(TBehaviourPattern*& p)
{
  p = new TPattern_Skydome();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern::MakeSkyplane(TBehaviourPattern*& p)
{
  p = new TPattern_Skyplane();
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
void TFactoryBehaviourPattern::MakeVolume(TBehaviourPattern*& p)
{
  p = new TPattern_Volume();
}
//----------------------------------------------------------------------------
