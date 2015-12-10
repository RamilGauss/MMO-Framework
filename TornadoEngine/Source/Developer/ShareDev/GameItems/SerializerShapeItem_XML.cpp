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

  const char* sNameMaterial   = "name";
  const char* sMaterial       = "Material";
  const char* sPaint          = "Paint"; 
  const char* sUseNatureColor = "use_nature_color";
  const char* sLayer          = "Layer";
  const char* sLOD            = "LOD";
  const char* sDistance       = "distance";
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

  bool resEnter = AddAndEnterByType(mShape->mName);
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
  mMapNameValue_Geometry.clear();

  if(mXML->EnterSection(sGeometry,0))
  {
    std::string key, value;
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      LoadProperty(iProperty, key, value);
      mMapNameValue_Geometry.insert(TMapStrStrVT(key, value));
    }
    mXML->LeaveSection();
  }

  MakeGeometryByMap();
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::LoadPaint()
{
  std::string flag = mXML->ReadSectionAttr(sPaint, 0, sUseNatureColor);
  mShape->flgUseNatureColor = bool(flag=="true");

  if(mXML->EnterSection(sPaint,0))// краска
  {
    int cntLayer = mXML->GetCountSection(sLayer);
    for( int iLayer = 0 ; iLayer < cntLayer ; iLayer++ )
    {
      TShapeItem::TLayer layer;
      if(mXML->EnterSection(sLayer, iLayer))// слои
      {
        int cntLOD = mXML->GetCountSection(sLOD);
        for( int iLOD = 0 ; iLOD < cntLOD ; iLOD++ )
        {
          std::string distance = mXML->ReadSectionAttr(sLOD, iLOD, sDistance);
          TShapeItem::TLOD lod;
          lod.distance = atof(distance.data());
          if(mXML->EnterSection(sLOD, iLOD))// ЛОД
          {
            std::string key, value;
            int cntProperty = GetCountProperty();
            for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
            {
              LoadProperty(iProperty, key, value);
              if(key==sColor)
                lod.color  = value;
              if(key==sNormal)
                lod.normal = value;
            }
            layer.push_back(lod);
            mXML->LeaveSection();
          }
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
  MakeMapByGeometry();

  if(mXML->AddSectionAndEnter(sGeometry))
  {
    TMapStrStrIt bit = mMapNameValue_Geometry.begin();
    TMapStrStrIt eit = mMapNameValue_Geometry.end();
    while(bit!=eit)
    {
      std::string key, value;
      key = bit->first; 
      value = bit->second;
      SaveProperty(key, value);
      bit++;
    }
    mXML->LeaveSection();
  }
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
        int cntLOD = mShape->mVecPaint[iLayer].size();
        for( int iLOD = 0 ; iLOD < cntLOD ; iLOD++ )
        {
          TShapeItem::TLOD lod = mShape->mVecPaint[iLayer].operator [](iLOD);
          TAttrInfo attr;
          char strDist[50];
          _gcvt_s(strDist, sizeof(strDist), lod.distance, 9);
          attr.Name  = sDistance;
          attr.Value = strDist;
          if(mXML->AddSectionAndEnter(sLOD, 1, &attr))
          {
            std::string key;
            key = sColor;
            SaveProperty(key, lod.color);
            key = sNormal;
            SaveProperty(key, lod.normal);
            mXML->LeaveSection();
          }
        }
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SaveMaterial()
{
  TAttrInfo attr;
  attr.Name  = sNameMaterial;
  attr.Value = mShape->mNameMaterial;

  mXML->AddSection(sMaterial, 1, &attr);
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::MakeGeometryByMap()
{
  nsParamBuilderShape::TBaseParam* pParam = mSerParamShape.GetParamByMap(&mMapNameValue_Geometry);
  mShape->mPtrGeometry.reset(pParam);
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::MakeMapByGeometry()
{
  mSerParamShape.GetMapByParam(mShape->mPtrGeometry.get(), &mMapNameValue_Geometry);
}
//--------------------------------------------------------------------------------  
