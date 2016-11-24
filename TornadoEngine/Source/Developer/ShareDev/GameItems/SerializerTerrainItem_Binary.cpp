/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerTerrainItem_Binary.h"
#include "FactoryGameItem.h"

TSerializerTerrainItem_Binary::TSerializerTerrainItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::Terrain)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerTerrainItem_Binary::~TSerializerTerrainItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_Binary::PackItem(TBaseItem* pItem, TContainer& cBinOut)
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTerrainItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  return false;
}
//-------------------------------------------------------------------------------------------------------
