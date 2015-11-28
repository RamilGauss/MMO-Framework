/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerShapeItem_XML.h"
#include "ShapeItem.h"
#include "IXML.h"

namespace nsShapeItem
{
  const char* sShape          = "Shape";
  const char* sGeometry       = "Geometry";
  const char* sName           = "Name";

  const char* sNameForm_Cone  = "Cone";
  const char* sRadius         = "Radius";
  const char* sHeight         = "Height";
  const char* sCut            = "Cut";

  const char* sVolume         = "Volume";
  const char* sNameMaterial   = "name";
  const char* sMaterial       = "Material";
  const char* sPaint          = "Paint"; 
  const char* sUseNatureColor = "use_nature_color";
  const char* sLayer          = "Layer";
  const char* sColor          = "Color";
  const char* sNormal         = "Normal";
}

using namespace nsShapeItem;

TSerializerShapeItem_XML::TSerializerShapeItem_XML():
TBaseSerializerItem_XML(sShape)
{
  mShape = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerShapeItem_XML::~TSerializerShapeItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerShapeItem_XML::Load(TBaseItem* pItem)
{
  mShape = (TShapeItem*)pItem;

  bool resEnter = EnterByType(mShape->mName);
  if(resEnter==false)
    return false;
  LoadGeometry();
  LoadPaint();
  LoadMaterial();
  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerShapeItem_XML::Save(TBaseItem* pItem)
{
  mShape = (TShapeItem*)pItem;

  RemoveSection(mShape->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = EnterByType(mShape->mName);
  if(resEnter==false)
    return false;
  SaveGeometry();
  SavePaint();
  SaveMaterial();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerShapeItem_XML::LoadGeometry()
{
  if(mXML->EnterSection(sGeometry,0))
  {
    std::string key, value;
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      LoadProperty(iProperty, key, value);
      if(key==sName)
        mNameShape = value;
      else
        mMapNameValue.insert(TMapStrFloatVT(key, atof(value.data())));
    }
    mXML->LeaveSection();
  }

  MakeGeometry();
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::LoadPaint()
{
  std::string flag = mXML->ReadSectionAttr(sPaint, 0, sUseNatureColor);
  mShape->flgUseNatureColor = bool(flag=="true");

  if(mXML->EnterSection(sPaint,0))
  {
    int cntLayer = mXML->GetCountSection(sLayer);
    for( int iLayer = 0 ; iLayer < cntLayer ; iLayer++ )
    {
      if(mXML->EnterSection(sLayer, iLayer))
      {
        TShapeItem::TLayer layer;
        std::string key, value;
        int cntProperty = GetCountProperty();
        for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
        {
          LoadProperty(iProperty, key, value);
          if(key==sColor)
            layer.color  = value;
          if(key==sNormal)
            layer.normal = value;
        }
        mShape->mVecPaint.push_back(layer);
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::LoadMaterial()
{
  mShape->mNameMaterial = mXML->ReadSectionAttr(sMaterial, 0, sNameMaterial);
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SaveGeometry()
{

}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SavePaint()
{
  if(mXML->AddSectionAndEnter(sPaint))
  {
    std::string flag = mShape->flgUseNatureColor ? "true" : "false";
    mXML->WriteSectionAttr(sPaint, 0, sUseNatureColor, flag);

    int cntLayer = mShape->mVecPaint.size();
    for( int iLayer = 0 ; iLayer < cntLayer ; iLayer++ )
    {
      if(mXML->AddSectionAndEnter(sLayer))
      {
        TShapeItem::TLayer layer;
        std::string key, value;
        int cntProperty = GetCountProperty();
        for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
        {
          LoadProperty(iProperty, key, value);
          if(key==sColor)
            layer.color  = value;
          if(key==sNormal)
            layer.normal = value;
        }
        mShape->mVecPaint.push_back(layer);
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SaveMaterial()
{

}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::MakeGeometry()
{
  mShape->mPtrGeometry.reset(new nsParamBuilderShape::TCone);
}
//--------------------------------------------------------------------------------  
