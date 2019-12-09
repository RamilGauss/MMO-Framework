/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SerializerModelItem_Binary.h"
#include "FactoryGameItem.h"

TSerializerModelItem_Binary::TSerializerModelItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::Model)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerModelItem_Binary::~TSerializerModelItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerModelItem_Binary::PackItem(TBaseItem* pItem, TContainerRise& cBinOut)
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerModelItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  return false;
}
//-------------------------------------------------------------------------------------------------------
