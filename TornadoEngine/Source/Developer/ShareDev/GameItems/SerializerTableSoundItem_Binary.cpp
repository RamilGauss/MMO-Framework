/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SerializerTableSoundItem_Binary.h"
#include "FactoryGameItem.h"

TSerializerTableSoundItem_Binary::TSerializerTableSoundItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::TableSound)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerTableSoundItem_Binary::~TSerializerTableSoundItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_Binary::PackItem(TBaseItem* pItem, TContainerRise& cBinOut)
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTableSoundItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  return false;
}
//-------------------------------------------------------------------------------------------------------
