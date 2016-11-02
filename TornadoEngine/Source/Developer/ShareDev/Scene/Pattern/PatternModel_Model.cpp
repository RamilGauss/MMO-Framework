/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Model.h"
#include <boost/foreach.hpp>
#include <OgreRoot.h>
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "FactoryGameItem.h"
#include "ModelItem.h"

#include "PatternContext_Model.h"

namespace nsPatternModel_Model
{
  const char* sNameGameItem = "NameGameItem";
  const char* sVariant      = "Variant";
  const char* sMobility     = "Mobility";
}

using namespace nsPatternModel_Model;

TPatternModel_Model::TPatternModel_Model()
{
  mDefaultParameterMap.insert(TMapItem::TMapStrStrVT(sNameGameItem,""));
  mDefaultParameterMap.insert(TMapItem::TMapStrStrVT(sVariant,""));
  mDefaultParameterMap.insert(TMapItem::TMapStrStrVT(sMobility,""));
}
//---------------------------------------------------------------------------
TPatternModel_Model::~TPatternModel_Model()
{

}
//---------------------------------------------------------------------------
TBehaviourPatternContext* TPatternModel_Model::MakeNewConext()
{ 
  return new TPatternContext_Model(this);
}
//---------------------------------------------------------------------------
void TPatternModel_Model::GetDefaultParameterMap(TMapItem::TMapStrStr& m)
{
  m = mDefaultParameterMap;
}
//---------------------------------------------------------------------------
bool TPatternModel_Model::SetParameterFromPattern(TContainer c)
{
  return true;
}
//---------------------------------------------------------------------------
TContainer TPatternModel_Model::GetParameterToPattern()
{
  TContainer c;
  return c;
}
//---------------------------------------------------------------------------
void TPatternModel_Model::SetPosition(nsMathTools::TVector3& v)
{
  // подготовить задание для физики
  nsMathTools::TVector3* pV = new nsMathTools::TVector3(v);
  mPipePositionLogic2Bullet.Add(pV);
}
//---------------------------------------------------------------------------
bool TPatternModel_Model::GetPosition(nsMathTools::TVector3& v)
{
  return GetFromPipe(v, &mPipePositionLogic2Bullet);
}
//---------------------------------------------------------------------------
void TPatternModel_Model::SetOrientation(nsMathTools::TVector3& v)
{
  // подготовить задание для физики
  nsMathTools::TVector3* pV = new nsMathTools::TVector3(v);
  mPipeOrientationLogic2Bullet.Add(pV);
}
//---------------------------------------------------------------------------
bool TPatternModel_Model::GetOrientation(nsMathTools::TVector3& v)
{
  return GetFromPipe(v, &mPipeOrientationLogic2Bullet);
}
//---------------------------------------------------------------------------
bool TPatternModel_Model::GetFromPipe(nsMathTools::TVector3& v, TDataExchange2Thread<nsMathTools::TVector3>* pPipe)
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
bool TPatternModel_Model::LoadFromParameterMap()
{
  return true;
}
//---------------------------------------------------------------------------
bool TPatternModel_Model::UpdateFromGameItem(TBaseItem* pBI)
{
  return true;
}
//---------------------------------------------------------------------------
bool TPatternModel_Model::Unload()
{
  return true;
}
//---------------------------------------------------------------------------
void TPatternModel_Model::LoadFromThread_Logic(TBehaviourPatternContext* pContext)
{
  TPatternContext_Model* pContextModel = (TPatternContext_Model*)pContext;
  // найти имя модели
  TMapItem::TMapStrStrConstIt itNameGameItem = pContext->GetParameterMap()->find(sNameGameItem);
  if( itNameGameItem==pContext->GetParameterMap()->end() )
    return;
  std::string nameGameItem = itNameGameItem->second;

  TMapItem::TMapStrStrConstIt itVariant = pContext->GetParameterMap()->find(sVariant);
  if( itVariant==pContext->GetParameterMap()->end() )
    return;
  std::string variantPattern = itVariant->second;

  TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();

  TModelItem* pModel = (TModelItem*)pFGI->Get(TFactoryGameItem::Model, nameGameItem);
  if( pModel==NULL )
    return;
  
  TPatternConfigItem* pPattern = (TPatternConfigItem*)pFGI->Get(TFactoryGameItem::PatternConfig, GetName());
  if( pPattern==NULL )
    return;

  TPatternConfigItem::TMapStrMapIt itMapVariant = pPattern->mMapVariant.find(variantPattern);
  if( itMapVariant!=pPattern->mMapVariant.end() )
    pContextModel->SetMapVariant(itMapVariant->second);// использовать в конце загрузки в каждом из потоков (графика,звук,физика)

  // задача: создать карту форм и моделей по имени. При синхронизации менять положение и ориентацию
  // форм и моделей



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
      if( variant.type=="model")
      {
        // модель, перейти по итерации дальше в разбор модели
        variant.name;
      }
      else// shape
      {
        // создать форму
      }
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
void TPatternModel_Model::LoadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast)
{
#if 0
  //mGO->GetGraphic();
  Ogre::Root* pRoot = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetRoot();

  // найти имя модели
  TMapItem::TMapStrStrIt itName = mParameterMap.find(sNameGameItem);
  if( itName==mParameterMap.end() )
    return;
  std::string nameGameItem = itName->second;

  TModelItem* pModel = (TModelItem*)mFGI->Get(TFactoryGameItem::Model, nameGameItem);
  if( pModel==NULL )
    return;
  
  // задача: создать карту форм и моделей по имени. При синхронизации менять положение и ориентацию
  // форм и моделей


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
      if( variant.type=="model")
      {
        // модель, перейти по итерации дальше в разбор модели
        variant.name;
      }
      else// shape
      {
        // создать форму
      }
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
#endif
}
//---------------------------------------------------------------------------
void TPatternModel_Model::LoadFromThread_Bullet( TBehaviourPatternContext* pContext, bool fast )
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::LoadFromThread_OpenAL( TBehaviourPatternContext* pContext, bool fast )
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::UnloadFromThread_Logic(TBehaviourPatternContext* pContext)
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::UnloadFromThread_Ogre( TBehaviourPatternContext* pContext, bool fast )
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::UnloadFromThread_Bullet( TBehaviourPatternContext* pContext, bool fast )
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::UnloadFromThread_OpenAL( TBehaviourPatternContext* pContext, bool fast )
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::SynchroFromThread_Logic(TBehaviourPatternContext* pContext)
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::SynchroFromThread_Ogre(TBehaviourPatternContext* pContext)
{

}
//---------------------------------------------------------------------------
void TPatternModel_Model::SynchroFromThread_Bullet(TBehaviourPatternContext* pContext)
{
  // проверка на изменение позиции и ориентации
}
//---------------------------------------------------------------------------
void TPatternModel_Model::SynchroFromThread_OpenAL(TBehaviourPatternContext* pContext)
{

}
//---------------------------------------------------------------------------
