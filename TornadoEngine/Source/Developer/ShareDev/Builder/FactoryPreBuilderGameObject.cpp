/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryPreBuilderGameObject.h"

#include "PreBuilderGameObject_Animated.h"
#include "PreBuilderGameObject_Light.h"
#include "PreBuilderGameObject_Model.h"
#include "PreBuilderGameObject_Skybox.h"
#include "PreBuilderGameObject_Sound.h"
#include "PreBuilderGameObject_Terrain.h"
#include "PreBuilderGameObject_Zone.h"

#include <boost/foreach.hpp>
#include "ManagerNameTypeObjectMap.h"

TFactoryPreBuilderGameObject::TFactoryPreBuilderGameObject()
{
  mMapStrType_PreBuilder.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Animated(), new TPreBuilderGameObject_Animated));
  mMapStrType_PreBuilder.insert(TMapStrPtrVT(
    TManagerNameTypeObjectMap::Light(), new TPreBuilderGameObject_Light()));
  mMapStrType_PreBuilder.insert(TMapStrPtrVT(
    TManagerNameTypeObjectMap::Model(), new TPreBuilderGameObject_Model()));
  mMapStrType_PreBuilder.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Skybox(), new TPreBuilderGameObject_Skybox()));
  mMapStrType_PreBuilder.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Sound(), new TPreBuilderGameObject_Sound()));
  mMapStrType_PreBuilder.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Terrain(), new TPreBuilderGameObject_Terrain()));
  mMapStrType_PreBuilder.insert(TMapStrPtrVT( 
    TManagerNameTypeObjectMap::Zone(), new TPreBuilderGameObject_Zone()));
}             
//--------------------------------------------------------------------
TFactoryPreBuilderGameObject::~TFactoryPreBuilderGameObject()
{
  BOOST_FOREACH(TMapStrPtrVT& vt, mMapStrType_PreBuilder)
    delete vt.second;
}
//--------------------------------------------------------------------
TPreBuilderGameObject* TFactoryPreBuilderGameObject::GetPreBuilderByType(std::string type)
{
  TMapStrPtrIt fit = mMapStrType_PreBuilder.find(type);
  if( fit==mMapStrType_PreBuilder.end() )
    return NULL;
  return fit->second;
}
//--------------------------------------------------------------------
