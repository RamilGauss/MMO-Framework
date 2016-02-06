/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerTableSoundItem_XML.h"
#include "IXML.h"
#include "TableSoundItem.h"


namespace nsSerializerTableSoundItem_XML
{
	const char* sTableSound = "TableSound";
}

using namespace nsSerializerTableSoundItem_XML;

TSerializerTableSoundItem_XML::TSerializerTableSoundItem_XML():
TBaseSerializerItem_XML(sTableSound)
{
	mTableSound = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerTableSoundItem_XML::~TSerializerTableSoundItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTableSoundItem_XML::Load(TBaseItem* pItem)
{
	mTableSound = (TTableSoundItem*)pItem;

	bool resEnter = EnterByType(mTableSound->mName);
	if(resEnter==false)
		return false;

	return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTableSoundItem_XML::Save(TBaseItem* pItem)
{
	mTableSound = (TTableSoundItem*)pItem;
	RemoveSection(mTableSound->mName);// грохнуть всю запись, связанную с данным item

	bool resEnter = AddAndEnterByType(mTableSound->mName);
	if(resEnter==false)
		return false;

	return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------

