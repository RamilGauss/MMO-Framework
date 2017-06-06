/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerTerrainItem_Binary.h"
#include "FactoryGameItem.h"
#include "TerrainItem.h"
#include <boost/foreach.hpp>
#include "ShareMisc.h"

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
	TTerrainItem* pTerrainItem = (TTerrainItem*)pItem;
	UnlinkCollect();

	PushType();
	PushStr(pTerrainItem->mName);

	PushStr(pTerrainItem->mNameHeightData);

	Push(pTerrainItem->mX.min);
	Push(pTerrainItem->mX.max);
	Push(pTerrainItem->mY.min);
	Push(pTerrainItem->mY.max);

	Push(pTerrainItem->mGraphic.maxPixelError);
	Push(pTerrainItem->mGraphic.compositeMapDistance);

	Collect(cBinOut);
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTerrainItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
	TTerrainItem* pTerrainItem = (TTerrainItem*)pItem;

	BeginUnpack((char*)pIn, sizeIn);

	RET_FALSE( PopType() )
	RET_FALSE( PopStr(pTerrainItem->mName) )

	RET_FALSE( PopStr(pTerrainItem->mNameHeightData) )

	RET_FALSE(Pop(pTerrainItem->mX.min))
	RET_FALSE(Pop(pTerrainItem->mX.max))
	RET_FALSE(Pop(pTerrainItem->mY.min))
	RET_FALSE(Pop(pTerrainItem->mY.max))

	RET_FALSE( Pop(pTerrainItem->mGraphic.maxPixelError) )
	RET_FALSE( Pop(pTerrainItem->mGraphic.compositeMapDistance) )

	return true;
}
//-------------------------------------------------------------------------------------------------------
