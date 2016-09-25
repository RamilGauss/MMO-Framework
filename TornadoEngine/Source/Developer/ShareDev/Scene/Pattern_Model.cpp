/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Model.h"
#include <boost/foreach.hpp>
#include <OgreRoot.h>
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "FactoryGameItem.h"
#include "ModelItem.h"

namespace nsPatternModel
{
  const char* sNameGameItem = "NameGameItem";

}

using namespace nsPatternModel;

TPattern_Model::TPattern_Model()
{
  //mDefaultParameterMap.insert();
}
//---------------------------------------------------------------------------
TPattern_Model::~TPattern_Model()
{

}
//---------------------------------------------------------------------------
bool TPattern_Model::SetParameterFromPattern(TContainer c)
{
  return true;
}
//---------------------------------------------------------------------------
TContainer TPattern_Model::GetParameterToPattern()
{
  TContainer c;
  return c;
}
//---------------------------------------------------------------------------
void TPattern_Model::SetPosition(nsMathTools::TVector3& v)
{
  // подготовить задание для физики
  nsMathTools::TVector3* pV = new nsMathTools::TVector3(v);
  mPipePositionLogic2Bullet.Add(pV);
}
//---------------------------------------------------------------------------
bool TPattern_Model::GetPosition(nsMathTools::TVector3& v)
{
  return GetFromPipe(v, &mPipePositionLogic2Bullet);
}
//---------------------------------------------------------------------------
void TPattern_Model::SetOrientation(nsMathTools::TVector3& v)
{
  // подготовить задание для физики
  nsMathTools::TVector3* pV = new nsMathTools::TVector3(v);
  mPipeOrientationLogic2Bullet.Add(pV);
}
//---------------------------------------------------------------------------
bool TPattern_Model::GetOrientation(nsMathTools::TVector3& v)
{
  return GetFromPipe(v, &mPipeOrientationLogic2Bullet);
}
//---------------------------------------------------------------------------
bool TPattern_Model::GetFromPipe(nsMathTools::TVector3& v, TDataExchange2Thread<nsMathTools::TVector3>* pPipe)
{
  nsMathTools::TVector3** ppV = pPipe->GetFirst();
  if( ppV==NULL )
    return false;
  while(1)
  {
    v = *(*ppV);
    pPipe->RemoveFirst();
    ppV = pPipe->GetFirst();
    if( ppV==NULL )
      return true;
  }
  return false;
}
//---------------------------------------------------------------------------
bool TPattern_Model::LoadFromParameterMap()
{
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::UpdateFromGameItem(TBaseItem* pBI)
{
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::Unload()
{
  return true;
}
//---------------------------------------------------------------------------
void TPattern_Model::LoadFromThread_Ogre( bool fast )
{//mGO->GetGraphic();
  Ogre::Root* pRoot = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetRoot();

  // найти имя модели
  TMapItem::TMapStrStrIt itName = mParameterMap.find(sNameGameItem);
  if( itName==mParameterMap.end() )
    return;
  std::string nameGameItem = itName->second;

  TModelItem* pModel = (TModelItem*)mFGI->Get(TFactoryGameItem::Model, nameGameItem);
  if( pModel==NULL )
    return;

  // раскрыть ветку всех форм.
  // моделей быть не должно, они должны замениться на формы,
  // входящие в состав моделей

  // по описанию форм нужно в Ogre создать графическое представление

  // нужно анализировать констрейнты для нужного порядка соединения и применять
  // к ним параметры по-умолчанию


  // встретили форму - превратили в OgreObject
  // встретили модель - разлагаем на составляющие -> итерация для модели (если есть)


  // имея список форм и моделей -> можем соединить констрейнтами
  // параметры констрейнта берем


  BOOST_FOREACH( TModelItem::TMapStrPartVT& vtPart, pModel->mMapNamePart )
  {
    std::string namePart = vtPart.first;
    BOOST_FOREACH( TModelItem::TVariant& variant, vtPart.second.vecVariant )
    {
      variant.type.data();
      variant.name.data();

      variant.redefinitionMaterial.data();
      BOOST_FOREACH( TModelItem::TMapExternalInternalVT& vtExtInt, variant.mapExternalInternal )
      {
        vtExtInt.first.data();
        TModelItem::TJoint joint = vtExtInt.second;
        joint.nameJoint.data();
        joint.namePart.data();
      }
      variant.scale;
    }
  }
}
//---------------------------------------------------------------------------
void TPattern_Model::LoadFromThread_Bullet( bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::LoadFromThread_OpenAL( bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadFromThread_Ogre( bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadFromThread_Bullet( bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadFromThread_OpenAL( bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_Logic()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_Ogre()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_Bullet()
{
  // проверка на изменение позиции и ориентации
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_OpenAL()
{

}
//---------------------------------------------------------------------------
