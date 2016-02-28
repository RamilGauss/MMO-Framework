/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerShapeItem_XML.h"
#include "ShapeItem.h"
#include "IXML.h"
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

namespace nsShapeItem
{
  const char* sShape          = "Shape";
  const char* sGeometry       = "Geometry";

  const char* sName           = "name";
  const char* sJoining        = "Joining";
  const char* sJoint          = "Joint";
  const char* sPosition       = "Position";
  const char* sRotation       = "Rotation";

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
  LoadJoining();
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
  SaveJoining();
  SavePaint();
  SaveMaterial();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerShapeItem_XML::LoadJoining()
{
  if(mXML->EnterSection(sJoining,0))
  {
    int cntJoint = mXML->GetCountSection(sJoint);
    for( int iJoint = 0 ; iJoint < cntJoint ; iJoint++ )
    {
      std::string nameJoint = mXML->ReadSectionAttr(iJoint, sName);
      TShapeItem::TJoint joint;
      if(mXML->EnterSection(sJoint,iJoint))
      {
        nsMathTools::TVector3 v3;
        if(mXML->EnterSection(sPosition,0))
        {
          LoadVector3ByProperty(v3);
          joint.position = v3;
          mXML->LeaveSection();
        }
        if(mXML->EnterSection(sRotation,0))
        {
          LoadVector3ByProperty(v3);
          joint.rotation = v3;
          mXML->LeaveSection();
        }
        mXML->LeaveSection();
      }
      mShape->mMapNameJoint.insert(TShapeItem::TMapStrJointVT(nameJoint, joint));
    }
    mXML->LeaveSection();
  }
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
      TShapeItem::TMapFloatLayer layer;
      if(mXML->EnterSection(sLayer, iLayer))// слои
      {
        int cntLOD = mXML->GetCountSection(sLOD);
        for( int iLOD = 0 ; iLOD < cntLOD ; iLOD++ )
        {
          std::string distance = mXML->ReadSectionAttr(sLOD, iLOD, sDistance);
          TShapeItem::TLOD lod;
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
            layer.insert(TShapeItem::TMapFloatLayerVT(atof(distance.data()),lod));
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
  mShape->mNameMaterial = mXML->ReadSectionAttr(sMaterial, 0, sName);
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SaveGeometry()
{
  MakeMapByGeometry();

  if(mXML->AddSectionAndEnter(sGeometry))
  {
    BOOST_FOREACH(TMapStrStrVT& bit, mMapNameValue_Geometry)
    {
      std::string key, value;
      key   = bit.first; 
      value = bit.second;
      SaveProperty(key, value);
    }
    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SaveJoining()
{
  if(mXML->AddSectionAndEnter(sJoining))
  {
    BOOST_FOREACH( TShapeItem::TMapStrJointVT& bit, mShape->mMapNameJoint )
    {
      if(mXML->AddSectionAndEnter(sJoint))
      {
        if(mXML->AddSectionAndEnter(sPosition))
        {
          SaveVector3ByProperty(bit.second.position);
          mXML->LeaveSection();
        }
        if(mXML->AddSectionAndEnter(sRotation))
        {
          SaveVector3ByProperty(bit.second.rotation);
          mXML->LeaveSection();
        }
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//--------------------------------------------------------------------------------  
void TSerializerShapeItem_XML::SavePaint()
{
  TAttrInfo attr;
  attr.Name  = sUseNatureColor;
  attr.Value = mShape->flgUseNatureColor ? "true" : "false";
  if(mXML->AddSectionAndEnter(sPaint, 1, &attr))
  {
    int cntLayer = mShape->mVecPaint.size();
    for( int iLayer = 0 ; iLayer < cntLayer ; iLayer++ )
    {
      if(mXML->AddSectionAndEnter(sLayer))
      {
        BOOST_FOREACH(TShapeItem::TMapFloatLayerVT& bit, mShape->mVecPaint[iLayer])
        {
          attr.Name  = sDistance;
          attr.Value = boost::lexical_cast<std::string>(bit.first);
          if(mXML->AddSectionAndEnter(sLOD, 1, &attr))
          {
            std::string key;
            key = sColor;
            SaveProperty(key, bit.second.color);
            key = sNormal;
            SaveProperty(key, bit.second.normal);
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
  attr.Name  = sName;
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
