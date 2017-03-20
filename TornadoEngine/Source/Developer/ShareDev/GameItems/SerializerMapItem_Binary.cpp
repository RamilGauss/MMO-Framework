/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMapItem_Binary.h"
#include "FactoryGameItem.h"
#include "MapItem.h"
#include "boost/foreach.hpp"
#include "ShareMisc.h"

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
	TMapItem* pMapItem = (TMapItem*)pItem;
	UnlinkCollect();

	PushType();
	PushStr(pMapItem->mName);

	PushStr(pMapItem->mNameTableSound);
	Push(pMapItem->mGravity.x);
	Push(pMapItem->mGravity.y);
	Push(pMapItem->mGravity.z);

	Push(pMapItem->mFog.mode);
	Push(pMapItem->mFog.colour.x);
	Push(pMapItem->mFog.colour.y);
	Push(pMapItem->mFog.colour.z);
	Push(pMapItem->mFog.expDensity);
	Push(pMapItem->mFog.linearStart);
	Push(pMapItem->mFog.linearEnd);

	Push(pMapItem->mBackgroundColour.x);
	Push(pMapItem->mBackgroundColour.y);
	Push(pMapItem->mBackgroundColour.z);

	Push(pMapItem->mAmbientLight.x);
	Push(pMapItem->mAmbientLight.y);
	Push(pMapItem->mAmbientLight.z);

	Push(pMapItem->mListObject.size());
	BOOST_FOREACH( TMapItem::TObject& object, pMapItem->mListObject )
	{
		PushStr(object.namePattern);
		Push(object.id);

		Push(object.position.x);
		Push(object.position.y);
		Push(object.position.z);

		Push(object.rotationQuaternion.x);
		Push(object.rotationQuaternion.y);
		Push(object.rotationQuaternion.z);
		Push(object.rotationQuaternion.w);

		Push(object.parameterMap.size());
		BOOST_FOREACH(TMapItem::TMapStrStrVT& vt ,object.parameterMap)
		{
			std::string key = vt.first;
			PushStr(key);
			std::string value = vt.second;
			PushStr(value);
		}
	}
	Collect(cBinOut);
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
	TMapItem* pMapItem = (TMapItem*)pItem;

	BeginUnpack((char*)pIn, sizeIn);

	RET_FALSE( PopType() )
	RET_FALSE( PopStr(pMapItem->mName) )

	RET_FALSE( PopStr(pMapItem->mNameTableSound) )
	RET_FALSE( Pop(pMapItem->mGravity.x) )
	RET_FALSE( Pop(pMapItem->mGravity.y) )
	RET_FALSE( Pop(pMapItem->mGravity.z) )

	RET_FALSE( Pop(pMapItem->mFog.mode) )
	RET_FALSE( Pop(pMapItem->mFog.colour.x) )
	RET_FALSE( Pop(pMapItem->mFog.colour.y) )
	RET_FALSE( Pop(pMapItem->mFog.colour.z) )
	RET_FALSE( Pop(pMapItem->mFog.expDensity) )
	RET_FALSE( Pop(pMapItem->mFog.linearStart) )
	RET_FALSE( Pop(pMapItem->mFog.linearEnd) )

	RET_FALSE( Pop(pMapItem->mBackgroundColour.x) )
	RET_FALSE( Pop(pMapItem->mBackgroundColour.y) )
	RET_FALSE( Pop(pMapItem->mBackgroundColour.z) )

	RET_FALSE( Pop(pMapItem->mAmbientLight.x) )
	RET_FALSE( Pop(pMapItem->mAmbientLight.y) )
	RET_FALSE( Pop(pMapItem->mAmbientLight.z) )

	TMapItem::TListObject::size_type cntObject;
	RET_FALSE( Pop(cntObject) )
	for( int iObject = 0 ; iObject < int(cntObject) ; iObject++ )
	{
		TMapItem::TObject object;
		RET_FALSE( PopStr(object.namePattern) )
		RET_FALSE( Pop(object.id) )

		RET_FALSE( Pop(object.position.x) )
		RET_FALSE( Pop(object.position.y) )
		RET_FALSE( Pop(object.position.z) )

		RET_FALSE( Pop(object.rotationQuaternion.x) )
		RET_FALSE( Pop(object.rotationQuaternion.y) )
		RET_FALSE( Pop(object.rotationQuaternion.z) )
		RET_FALSE( Pop(object.rotationQuaternion.w) )

		TMapItem::TMapStrStr::size_type cntParam;
		RET_FALSE( Pop(cntParam) )
		for( int iParam = 0 ; iParam < int(cntParam) ; iParam++ )
		{
			std::string key;
			RET_FALSE( PopStr(key) )
			std::string value;
			RET_FALSE( PopStr(value) )
			object.parameterMap.insert(TMapItem::TMapStrStrVT(key,value));
		}
		pMapItem->mListObject.push_back(object);
	}
	return true;
}
//-------------------------------------------------------------------------------------------------------
