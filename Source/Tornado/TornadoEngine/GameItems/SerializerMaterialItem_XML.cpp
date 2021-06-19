/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SerializerMaterialItem_XML.h"
#include "MaterialItem.h"
#include "IXML.h"

#include <boost/lexical_cast.hpp>

namespace nsSerializerMaterialItem_XML
{
  const char* sMaterial     = "Material";
  const char* sGraphic      = "Graphic";
  const char* sOgreMaterial = "OgreMaterial";
  const char* sVariant      = "Variant";
  const char* sWidth        = "Width";
  const char* sLength       = "Length";
  const char* sColor        = "Color";
  const char* sNormal       = "Normal";

  const char* sPhysic       = "Physic";
  const char* sDensity      = "Density";
  const char* sElasticity   = "Elasticity";
  const char* sFriction     = "Friction";
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
      TMaterialItem::TVariant variant;
      if(mXML->EnterSection(sVariant, iVariant))
      {
        std::string key, value;
        int cntProperty = GetCountProperty();
        for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
        {
          LoadProperty(iProperty, key, value);
          if(key==sColor)
            variant.color  = value;
          if(key==sNormal)
            variant.normal = value;
          if(key==sWidth)
            variant.width  = boost::lexical_cast<float>(value.data());
          if(key==sLength)
            variant.length = boost::lexical_cast<float>(value.data());
          if(key==sOgreMaterial)
            variant.ogreMaterial = value;
        }
        mXML->LeaveSection();
      }
      mMaterial->mGraphic.push_back(variant);
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
        TMaterialItem::TVariant variant = mMaterial->mGraphic[iVariant];

        std::string key = sColor;  SaveProperty(key, variant.color);
                    key = sNormal; SaveProperty(key, variant.normal);
                    key = sOgreMaterial; SaveProperty(key, variant.ogreMaterial);
        key = sWidth; 
        std::string value = boost::lexical_cast<std::string>(variant.width);
        SaveProperty(key, value);
        
        key = sLength; 
        value = boost::lexical_cast<std::string>(variant.length);
        SaveProperty(key, value);

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
    mMaterial->mPhysic.density = boost::lexical_cast<float>(fit->second.data());

  fit = mMapNameValue_Physic.find(sElasticity);
  if(fit!=mMapNameValue_Physic.end())
    mMaterial->mPhysic.elasticity = boost::lexical_cast<float>(fit->second.data());

  fit = mMapNameValue_Physic.find(sFriction);
  if(fit!=mMapNameValue_Physic.end())
    mMaterial->mPhysic.friction = boost::lexical_cast<float>(fit->second.data());
}
//-------------------------------------------------------------------------------------------------------
