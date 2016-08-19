/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPattern.h"
#include <boost/foreach.hpp>

namespace nsBehaviourPattern
{
  const char* sMobility     = "Mobility";
  const char* sNameGameItem = "NameGameItem";
  const char* sVariant      = "Variant";
};

using namespace nsBehaviourPattern;

TBehaviourPattern::TBehaviourPattern()
{
  mFGI = NULL;
  mGO  = NULL;
  mPhysicWorldID = -1;
}
//------------------------------------------------------------------------
TBehaviourPattern::~TBehaviourPattern()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SetPhysicWorld(int id_physic_world)
{
  mPhysicWorldID = id_physic_world;
}
//------------------------------------------------------------------------
std::string TBehaviourPattern::GetName()
{ 
  return mName;
}
//----------------------------------------------------------------
void TBehaviourPattern::SetName(std::string v)
{ 
  mName = v;
}
//----------------------------------------------------------------
void TBehaviourPattern::SetGameObject(TGameObject* p)
{
  mGO = p;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetFGI(TFactoryGameItem* pFGI)
{
  mFGI = pFGI;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetParameterMap(TMapItem::TMapStrStr& m)
{
  mParameterMap = m;
}
//------------------------------------------------------------------------
void TBehaviourPattern::GetDefualtParameterMap(TMapItem::TMapStrStr& m)
{
  m = mDefaultParameterMap;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetParameterFromPattern(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPattern::GetParameterToPattern()
{
  return TContainer();
}
//------------------------------------------------------------------------
bool TBehaviourPattern::GetNeedSynchro()
{
  return mStructParameterMap.flgMobility;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetPosition(nsMathTools::TVector3& v)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::GetPosition(nsMathTools::TVector3& v)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SetOrientation(nsMathTools::TVector3& v)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::GetOrientation(nsMathTools::TVector3& v)
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::LoadFromParameterMap()
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::UpdateFromGameItem(TBaseItem* pBI)
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::Unload()
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::LoadFromThread_Ogre(bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::LoadFromThread_Bullet(bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::LoadFromThread_OpenAL(bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::UnloadFromThread_Ogre(bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::UnloadFromThread_Bullet(bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::UnloadFromThread_OpenAL(bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroFromThread_Logic()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroFromThread_Ogre()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroFromThread_Bullet()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroFromThread_OpenAL()
{

}
//------------------------------------------------------------------------
int TBehaviourPattern::GetProgressLoad()
{
  return 0;
}
//------------------------------------------------------------------------
int TBehaviourPattern::GetProgressUnload()
{
  return 0;
}
//------------------------------------------------------------------------
void TBehaviourPattern::ParseParameterMap(TMapItem::TMapStrStr& m)
{
  BOOST_FOREACH(TMapItem::TMapStrStrVT& vt, m)
  {
    if(vt.first==sMobility)
    {
      if(vt.second=="true")
        mStructParameterMap.flgMobility = true;
      else
        mStructParameterMap.flgMobility = false;
    }
    else if(vt.first==sNameGameItem)
    {
      mStructParameterMap.nameGameItem = vt.second;
    }
    else if(vt.first==sVariant)
    {
      mStructParameterMap.nameVariant = vt.second;
    }
  }
}
//------------------------------------------------------------------------
