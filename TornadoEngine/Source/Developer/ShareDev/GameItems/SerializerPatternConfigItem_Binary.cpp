/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerPatternConfigItem_Binary.h"
#include "FactoryGameItem.h"

TSerializerPatternConfigItem_Binary::TSerializerPatternConfigItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::PatternConfig)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerPatternConfigItem_Binary::~TSerializerPatternConfigItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternConfigItem_Binary::PackItem(TBaseItem* pItem, TContainer& cBinOut)
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerPatternConfigItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  return false;
}
//-------------------------------------------------------------------------------------------------------
