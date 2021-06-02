/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BuilderTool_ShapeBase_Bullet.h"

//-------------------------------------------------------------------------------
TBuilderTool_ShapeBase_Bullet::TBuilderTool_ShapeBase_Bullet()
{
  mShape    = NULL;
  mMaterial = NULL;
}
//-------------------------------------------------------------------------------
TBuilderTool_ShapeBase_Bullet::~TBuilderTool_ShapeBase_Bullet()
{

}
//-------------------------------------------------------------------------------
void TBuilderTool_ShapeBase_Bullet::SetShape(TShapeItem* pShape)
{
  mShape = pShape;
}
//-------------------------------------------------------------------------
void TBuilderTool_ShapeBase_Bullet::SetMaterial(TMaterialItem* pMaterial)
{
  mMaterial = pMaterial;
}
//-------------------------------------------------------------------------
