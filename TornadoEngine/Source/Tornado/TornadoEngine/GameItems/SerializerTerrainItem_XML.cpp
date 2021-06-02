/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SerializerTerrainItem_XML.h"
#include "IXML.h"
#include <boost/lexical_cast.hpp>
#include "boost/foreach.hpp"

namespace nsSerializerTerrainItem_XML
{
  const char* sTerrain    = "Terrain";

  const char* sName       = "name";
  const char* sHeightData = "HeightData";
  const char* sConvention = "Convention";
  const char* sX           = "x";
  const char* sY            = "y";
  const char* sMin          = "min";
  const char* sMax          = "max";
  const char* sGraphic     = "Graphic";

  const char* sMaxPixelError        = "MaxPixelError";
  const char* sCompositeMapDistance = "CompositeMapDistance";
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
  
  LoadNameHeightData();
  LoadGraphic();
  LoadConvention();
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

   SaveNameHeightData();
  SaveGraphic();
  SaveConvention();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadNameHeightData()
{
  mTerrain->mNameHeightData = mXML->ReadSectionAttr(sHeightData, 0, sName);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadConvention()
{
  if(mXML->EnterSection(sConvention,0))
  {
    LoadConventionArg(sX, mTerrain->mX);
    LoadConventionArg(sY, mTerrain->mY);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadConventionArg(const char* sArg, TTerrainItem::TConvention& conv)
{
  TAttrInfo attr;
  for( int i = 0 ; i < 2 ; i++ )
  {
    mXML->ReadSectionAttrByIndex(sArg, 0, i, attr);
    if( attr.Name==sMin )
      conv.min = boost::lexical_cast<int>(attr.Value.data());
    if( attr.Name==sMax )
      conv.max = boost::lexical_cast<int>(attr.Value.data());
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadGraphic()
{
  if(mXML->EnterSection(sGraphic,0))
  {
    std::string key, value;
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      LoadProperty(iProperty, key, value);
      if( key==sMaxPixelError )
        mTerrain->mGraphic.maxPixelError = boost::lexical_cast<float>(value);
      if( key==sCompositeMapDistance )
        mTerrain->mGraphic.compositeMapDistance = boost::lexical_cast<float>(value);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveNameHeightData()
{
  TAttrInfo attr;
  attr.Name  = sHeightData;
  attr.Value = mTerrain->mNameHeightData;
  mXML->AddSection(sHeightData,1,&attr);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveConvention()
{
  if(mXML->AddSectionAndEnter(sConvention))
  {
    SaveConventionArg(sX, mTerrain->mX);
    SaveConventionArg(sY, mTerrain->mY);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveConventionArg(const char* sArg, TTerrainItem::TConvention& conv)
{  
  TAttrInfo attr;
  attr.Name  = sMin;
  attr.Value = boost::lexical_cast<std::string>(conv.min);
  mXML->AddSection(sArg, 1, &attr);
  attr.Name  = sMax;
  attr.Value = boost::lexical_cast<std::string>(conv.max);
  mXML->AddSection(sArg, 1, &attr);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveGraphic()
{
  if(mXML->AddSectionAndEnter(sGraphic))
  {
    std::string key   = sMaxPixelError;
    std::string value = boost::lexical_cast<std::string>(mTerrain->mGraphic.maxPixelError);
    SaveProperty(key, value);

    key   = sCompositeMapDistance;
    value = boost::lexical_cast<std::string>(mTerrain->mGraphic.compositeMapDistance);
    SaveProperty(key, value);

    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
