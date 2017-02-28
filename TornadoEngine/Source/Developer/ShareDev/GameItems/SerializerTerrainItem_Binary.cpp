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

	Push(pTerrainItem->mLength);
	Push(pTerrainItem->mWidth);

	PushStr(pTerrainItem->mGraphic.color);
	PushStr(pTerrainItem->mGraphic.normal);

	Push(pTerrainItem->mHeightMap.size());
	BOOST_FOREACH( TTerrainItem::TPoint& point, pTerrainItem->mHeightMap )
	{
		Push(point.x);
		Push(point.y);
		Push(point.h);
		Push(point.u);
		Push(point.v);
	}
	Collect(cBinOut);
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTerrainItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
	TTerrainItem* pTerrainItem = (TTerrainItem*)pItem;

	BeginUnpack((char*)pIn, sizeIn);

	RET_FALSE( PopType() )
	RET_FALSE( PopStr(pTerrainItem->mName) )

	RET_FALSE(Pop(pTerrainItem->mLength))
	RET_FALSE(Pop(pTerrainItem->mWidth))

	RET_FALSE(PopStr(pTerrainItem->mGraphic.color))
	RET_FALSE(PopStr(pTerrainItem->mGraphic.normal))

	TTerrainItem::TVecPoint::size_type cntPoint;
	RET_FALSE( Pop(cntPoint) )
	for( int iPoint = 0 ; iPoint < int(cntPoint) ; iPoint++ )
	{
		TTerrainItem::TPoint point;
		RET_FALSE( Pop(point.x) )
		RET_FALSE( Pop(point.y) )
		RET_FALSE( Pop(point.x) )
		RET_FALSE( Pop(point.y) )
		RET_FALSE( Pop(point.y) )
		pTerrainItem->mHeightMap.push_back(point);
	}
	return true;
}
//-------------------------------------------------------------------------------------------------------
