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

	Push(pTerrainItem->mX.min);
	Push(pTerrainItem->mX.max);
	Push(pTerrainItem->mY.min);
	Push(pTerrainItem->mY.max);

	Push(pTerrainItem->mMapProperty.size());
	BOOST_FOREACH( TTerrainItem::TMapStrStrVT& vt, pTerrainItem->mMapProperty )
	{
		std::string value = vt.first;
		PushStr(value);
		value = vt.second;
		PushStr(value);
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

	RET_FALSE(Pop(pTerrainItem->mX.min))
	RET_FALSE(Pop(pTerrainItem->mX.max))
	RET_FALSE(Pop(pTerrainItem->mY.min))
	RET_FALSE(Pop(pTerrainItem->mY.max))

	TTerrainItem::TMapStrStr::size_type cntProperty;
	RET_FALSE( Pop(cntProperty) )
	for( int iPoint = 0 ; iPoint < int(cntProperty) ; iPoint++ )
	{
		std::string key;
		RET_FALSE( PopStr(key) )
		std::string value;
		RET_FALSE( PopStr(value) )
		pTerrainItem->mMapProperty.insert(TTerrainItem::TMapStrStrVT(key,value));
	}
	return true;
}
//-------------------------------------------------------------------------------------------------------
