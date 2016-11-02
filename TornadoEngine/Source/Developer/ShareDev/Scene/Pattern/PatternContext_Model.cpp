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
void TPatternContext_Model::AddShapeItem(std::string name, TShapeItem* pShapeItem)
{
  mMapNameShape.insert(TMapStrPtrShapeItemVT(name, pShapeItem));
}
//--------------------------------------------------------------------------
