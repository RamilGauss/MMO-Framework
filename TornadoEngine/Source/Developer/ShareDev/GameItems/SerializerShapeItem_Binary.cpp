/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerShapeItem_Binary.h"
#include "FactoryGameItem.h"

TSerializerShapeItem_Binary::TSerializerShapeItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::Shape)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerShapeItem_Binary::~TSerializerShapeItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerShapeItem_Binary::PackItem(TBaseItem* pItem, TContainerRise& cBinOut)
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerShapeItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  return false;
}
//-------------------------------------------------------------------------------------------------------
