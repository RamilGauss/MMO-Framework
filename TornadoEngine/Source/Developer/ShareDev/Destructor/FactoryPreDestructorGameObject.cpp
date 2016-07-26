/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryPreDestructorGameObject.h"

#include <boost/foreach.hpp>

#include "PreDestructorGameObject_Animated.h"
#include "PreDestructorGameObject_Light.h"
#include "PreDestructorGameObject_Model.h"
#include "PreDestructorGameObject_Skybox.h"
#include "PreDestructorGameObject_Sound.h"
#include "PreDestructorGameObject_Terrain.h"
#include "PreDestructorGameObject_Zone.h"

#include "ManagerNameTypeObjectMap.h"

TFactoryPreDestructorGameObject::TFactoryPreDestructorGameObject()
{
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Animated(), new TPreDestructorGameObject_Animated) );
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Light(), new TPreDestructorGameObject_Light) );
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Model(), new TPreDestructorGameObject_Model) );
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Skybox(), new TPreDestructorGameObject_Skybox) );
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Sound(), new TPreDestructorGameObject_Sound) );
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Terrain(), new TPreDestructorGameObject_Terrain) );
  mMapStrType_PreDestructor.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Zone(), new TPreDestructorGameObject_Zone) );
}
//--------------------------------------------------------------------
TFactoryPreDestructorGameObject::~TFactoryPreDestructorGameObject()
{
  BOOST_FOREACH(TMapStrPtrVT& pVT, mMapStrType_PreDestructor)
    delete pVT.second;
  mMapStrType_PreDestructor.clear();
}
//--------------------------------------------------------------------
TPreDestructorGameObject* TFactoryPreDestructorGameObject::GetPreDestructorByType(std::string type)
{
  TMapStrPtrIt fit = mMapStrType_PreDestructor.find(type);
  if( fit==mMapStrType_PreDestructor.end() )
    return NULL;
  return fit->second;
}
//--------------------------------------------------------------------
