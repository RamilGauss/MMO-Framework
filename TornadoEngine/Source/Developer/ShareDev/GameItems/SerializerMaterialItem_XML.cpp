/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMaterialItem_XML.h"
#include "MaterialItem.h"
#include "IXML.h"

#include <boost/lexical_cast.hpp>

namespace nsSerializerMaterialItem_XML
{
  const char* sMaterial   = "Material";
  const char* sGraphic    = "Graphic";
  const char* sVariant    = "Variant";
  const char* sLOD        = "LOD";
  const char* sDistance   = "distance";
  const char* sWidth      = "Width";
  const char* sLength     = "Length";
  const char* sColor      = "Color";
  const char* sNormal     = "Normal";

  const char* sPhysic     = "Physic";
  const char* sDensity    = "Density";
  const char* sElasticity = "Elasticity";
  const char* sFriction   = "Friction";
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
  LoadGraphic();
  LoadPhysic();
  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMaterialItem_XML::Save(TBaseItem* pItem)
{
  mMaterial = (TMaterialItem*)pItem;
  RemoveSection(mMaterial->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = AddAndEnterByType(mMaterial->mName);
  if(resEnter==false)
    return false;

  SaveGraphic();
  SavePhysic();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMaterialItem_XML::LoadGraphic()
{
  if(mXML->EnterSection(sGraphic, 0))// начало секции Графика
  {
    mMaterial->mGraphic.clear();
    int cntVariant = mXML->GetCountSection(sVariant);
    for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )// перебор Вариантов
    {
      TMaterialItem::TVecLOD vecLOD;
      if(mXML->EnterSection(sVariant, iVariant))
      {
        int cntLOD = mXML->GetCountSection(sLOD);
        for( int iLOD = 0 ; iLOD < cntLOD ; iLOD++ )// перебор ЛОДов
        {
          std::string distance = mXML->ReadSectionAttr(sLOD, iLOD, sDistance);
          TMaterialItem::TLOD lod;
          lod.distance = atof(distance.data());
          if(mXML->EnterSection(sLOD, iLOD))
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
              if(key==sWidth)
                lod.width  = atof(value.data());
              if(key==sLength)
                lod.length = atof(value.data());
            }
            vecLOD.push_back(lod);
            mXML->LeaveSection();
          }
        }
        mXML->LeaveSection();
      }
      mMaterial->mGraphic.push_back(vecLOD);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMaterialItem_XML::LoadPhysic()
{
  mMapNameValue_Physic.clear();

  if(mXML->EnterSection(sPhysic, 0))// начало секции Физика
  {
    std::string key, value;
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      LoadProperty(iProperty, key, value);
      mMapNameValue_Physic.insert(TMapStrStrVT(key,value));
    }
    mXML->LeaveSection();
  }

  FillPhysicParam();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMaterialItem_XML::SaveGraphic()
{
  if(mXML->AddSectionAndEnter(sGraphic))// начало секции Графика
  {
    int cntVariant = mMaterial->mGraphic.size();
    for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )// добавление Вариантов
    {
      if(mXML->AddSectionAndEnter(sVariant))
      {
        int cntLOD = mMaterial->mGraphic[iVariant].size();
        for( int iLOD = 0 ; iLOD < cntLOD ; iLOD++ )// добавление ЛОДов
        {
          TMaterialItem::TLOD lod = mMaterial->mGraphic[iVariant].operator [](iLOD);

          TAttrInfo attr;
          attr.Name  = sDistance;
          attr.Value = boost::lexical_cast<std::string>(lod.distance);
          if(mXML->AddSectionAndEnter(sLOD, 1, &attr))
          {
            std::string key = sColor;  SaveProperty(key, lod.color);
                        key = sNormal; SaveProperty(key, lod.normal);
            key = sWidth; 
            std::string value = boost::lexical_cast<std::string>(lod.width);
            SaveProperty(key, value);
            
            key = sLength; 
            value = boost::lexical_cast<std::string>(lod.length);
            SaveProperty(key, value);

            mXML->LeaveSection();
          }
        }
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMaterialItem_XML::SavePhysic()
{
  if(mXML->AddSectionAndEnter(sPhysic))// начало секции Физика
  {
    std::string key, value;

    key = sDensity; 
    value = boost::lexical_cast<std::string>(mMaterial->mPhysic.density);
    SaveProperty(key, value);

    key = sElasticity; 
    value = boost::lexical_cast<std::string>(mMaterial->mPhysic.elasticity);
    SaveProperty(key, value);

    key = sFriction; 
    value = boost::lexical_cast<std::string>(mMaterial->mPhysic.friction);
    SaveProperty(key, value);

    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMaterialItem_XML::FillPhysicParam()
{
  TMapStrStrIt fit = mMapNameValue_Physic.find(sDensity);
  if(fit!=mMapNameValue_Physic.end())
    mMaterial->mPhysic.density = atof(fit->second.data());

  fit = mMapNameValue_Physic.find(sElasticity);
  if(fit!=mMapNameValue_Physic.end())
    mMaterial->mPhysic.elasticity = atof(fit->second.data());

  fit = mMapNameValue_Physic.find(sFriction);
  if(fit!=mMapNameValue_Physic.end())
    mMaterial->mPhysic.friction = atof(fit->second.data());
}
//-------------------------------------------------------------------------------------------------------
