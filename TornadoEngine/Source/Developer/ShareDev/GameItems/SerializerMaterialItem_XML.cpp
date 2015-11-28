/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMaterialItem_XML.h"
#include "MaterialItem.h"
#include "IXML.h"

namespace nsSerializerMaterialItem_XML
{
  const char* sMaterial           = "Material";
  const char* sMaterialGraphic    = "Graphic";
  const char* sMaterialVariant    = "Variant";
  const char* sMaterialLOD        = "LOD";
  const char* sMaterialDistance   = "distance";
  const char* sMaterialPhysic     = "Physic";
  const char* sMaterialDensity    = "Density";
  const char* sMaterialElasticity = "Elasticity";
  const char* sMaterialFriction   = "Friction";
  const char* sMaterialType       = "Type";
  const char* sMaterialRigid      = "Rigid";
  const char* sMaterialSoft       = "Soft";
}

using namespace nsSerializerMaterialItem_XML;

TSerializerMaterialItem_XML::TSerializerMaterialItem_XML():
TBaseSerializerItem_XML(sMaterial)
{
  mMaterial = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerMaterialItem_XML::~TSerializerMaterialItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMaterialItem_XML::Load(TBaseItem* pItem)
{
  mMaterial = (TMaterialItem*)pItem;
  
  bool resEnter = EnterByType(mMaterial->mName);
  if(resEnter==false)
    return false;

  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMaterialItem_XML::Save(TBaseItem* pItem)
{
  mMaterial = (TMaterialItem*)pItem;
  RemoveSection(mMaterial->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = EnterByType(mMaterial->mName);
  if(resEnter==false)
    return false;

  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------