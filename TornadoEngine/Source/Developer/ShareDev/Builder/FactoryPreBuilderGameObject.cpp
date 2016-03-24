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

TFactoryPreBuilderGameObject::TFactoryPreBuilderGameObject()
{
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Animated);
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Light   );
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Model   );
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Skybox  );
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Sound   );
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Terrain );
  mVecPreBuilder.push_back( new TPreBuilderGameObject_Zone    );

  BOOST_FOREACH(TPreBuilderGameObject*& pPreBuilder, mVecPreBuilder)
    mMapStrType_PreBuilder.insert(TMapStrPtrVT(pPreBuilder->GetStrDesc(), pPreBuilder));
}             
//--------------------------------------------------------------------
TFactoryPreBuilderGameObject::~TFactoryPreBuilderGameObject()
{
  BOOST_FOREACH(TPreBuilderGameObject*& pPreBuilder, mVecPreBuilder)
    delete pPreBuilder;
  mVecPreBuilder.clear();
}
//--------------------------------------------------------------------
int TFactoryPreBuilderGameObject::GetCountType()
{
  return mVecPreBuilder.size();
}
//--------------------------------------------------------------------
TPreBuilderGameObject* TFactoryPreBuilderGameObject::GetPreBuilderByIndex(int index)
{
  if(index >= GetCountType() ||
     index <= 0 )
    return NULL;
  
  return mVecPreBuilder[index];
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
