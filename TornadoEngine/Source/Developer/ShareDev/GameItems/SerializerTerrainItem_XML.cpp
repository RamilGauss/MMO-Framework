/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerTerrainItem_XML.h"
#include "TerrainItem.h"
#include "IXML.h"


namespace nsSerializerTerrainItem_XML
{
  const char* sTerrain            = "Terrain";
}

using namespace nsSerializerTerrainItem_XML;

TSerializerTerrainItem_XML::TSerializerTerrainItem_XML():
TBaseSerializerItem_XML(sTerrain)
{
  mTerrain = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerTerrainItem_XML::~TSerializerTerrainItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTerrainItem_XML::Load(TBaseItem* pItem)
{
  mTerrain = (TTerrainItem*)pItem;

  bool resEnter = EnterByType(mTerrain->mName);
  if(resEnter==false)
    return false;

  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTerrainItem_XML::Save(TBaseItem* pItem)
{
  mTerrain = (TTerrainItem*)pItem;
  RemoveSection(mTerrain->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = AddAndEnterByType(mTerrain->mName);
  if(resEnter==false)
    return false;

  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------

