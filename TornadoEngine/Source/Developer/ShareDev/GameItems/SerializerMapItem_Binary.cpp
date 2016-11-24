/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMapItem_Binary.h"
#include "FactoryGameItem.h"

TSerializerMapItem_Binary::TSerializerMapItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::Map)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerMapItem_Binary::~TSerializerMapItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_Binary::PackItem(TBaseItem* pItem, TContainer& cBinOut)
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  return false;
}
//-------------------------------------------------------------------------------------------------------
