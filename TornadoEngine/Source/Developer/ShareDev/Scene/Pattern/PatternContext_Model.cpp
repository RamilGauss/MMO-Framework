/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternContext_Model.h"
#include "ManagerNamePattern.h"

TPatternContext_Model::TPatternContext_Model(TBehaviourPatternModel* pModel):
TBehaviourPatternContext(pModel)
{
  flgMobility = false;
}
//--------------------------------------------------------------------------
TPatternContext_Model::~TPatternContext_Model()
{

}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetMapVariant(TPatternConfigItem::TMapStrStr& mapVariant)
{
  mMapVariant = mapVariant;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::AddShape(TShape* pShape)
{
  TMapStrMapStrPtrShapeIt fitPart = mMapNamePart_MapNameVariantShape.find(pShape->namePart); 
  if( fitPart==mMapNamePart_MapNameVariantShape.end() )
  {
    mMapNamePart_MapNameVariantShape.insert(TMapStrMapStrPtrShapeVT(pShape->namePart, TMapStrPtrShape()));
    fitPart = mMapNamePart_MapNameVariantShape.find(pShape->namePart);
  }
  fitPart->second.insert(TMapStrPtrShapeVT(pShape->nameVariant, pShape));
}
//--------------------------------------------------------------------------
TPatternContext_Model::TShape* TPatternContext_Model::GetShape(std::string namePart, std::string nameVariant)
{
  TMapStrMapStrPtrShapeIt fitPart = mMapNamePart_MapNameVariantShape.find(namePart); 
  if( fitPart==mMapNamePart_MapNameVariantShape.end() )
    return NULL;
  TMapStrPtrShapeIt fitVariant = fitPart->second.find(nameVariant);
  if( fitVariant==fitPart->second.end() )
    return NULL;
  return fitVariant->second;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::AddContextModel(std::string name, TPatternContext_Model* pContextModel)
{
  mMapNameContextModel.insert(TMMapStrPtrContextModelVT(name, pContextModel));
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetNameGameItem(std::string& name)
{
  mNameGameItem = name;
}
//--------------------------------------------------------------------------
std::string TPatternContext_Model::GetNameGameItem()
{
  return mNameGameItem;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetNameVariantPatternConfig(std::string& name)
{
  mNameVariantPatternConfig = name;
}
//--------------------------------------------------------------------------
std::string TPatternContext_Model::GetNameVariantPatternConfig()
{
  return mNameVariantPatternConfig;
}
//--------------------------------------------------------------------------
void TPatternContext_Model::SetMobility(bool v)
{
  flgMobility = v;
}
//--------------------------------------------------------------------------
bool TPatternContext_Model::GetMobility()
{
  return flgMobility;
}
//--------------------------------------------------------------------------
