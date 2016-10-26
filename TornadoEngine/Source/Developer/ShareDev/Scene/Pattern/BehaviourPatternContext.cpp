/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPatternContext.h"
#include <boost/foreach.hpp>

namespace nsBehaviourPatternContext
{
  const char* sMobility     = "Mobility";
  const char* sNameGameItem = "NameGameItem";
  const char* sVariant      = "Variant";
};

using namespace nsBehaviourPatternContext;

TBehaviourPatternContext::TBehaviourPatternContext(std::string nameModel)
{
  mNameModel = nameModel;

  mGO  = NULL;
  mPhysicWorldID = -1;
}
//------------------------------------------------------------------------
TBehaviourPatternContext::~TBehaviourPatternContext()
{

}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetPhysicWorld(int id_physic_world)
{
  mPhysicWorldID = id_physic_world;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetGameObject(TGameObject* p)
{
  mGO = p;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetParameterMap(TMapItem::TMapStrStr& m)
{
  mParameterMap = m;
}
//------------------------------------------------------------------------
bool TBehaviourPatternContext::SetParameterFromPattern(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPatternContext::GetParameterToPattern()
{
  return TContainer();
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetPosition(nsMathTools::TVector3& v)
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternContext::GetPosition(nsMathTools::TVector3& v)
{
  return false;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetOrientation(nsMathTools::TVector3& v)
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternContext::GetOrientation(nsMathTools::TVector3& v)
{
  return false;
}
//------------------------------------------------------------------------
bool TBehaviourPatternContext::UpdateFromGameItem(TBaseItem* pBI)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::ParseParameterMap(TMapItem::TMapStrStr& m)
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
const TMapItem::TMapStrStr* TBehaviourPatternContext::GetParameterMap()
{
  return &mParameterMap;
}
//------------------------------------------------------------------------
