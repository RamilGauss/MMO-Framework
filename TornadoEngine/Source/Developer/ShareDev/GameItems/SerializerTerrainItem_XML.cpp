/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerTerrainItem_XML.h"
#include "TerrainItem.h"
#include "IXML.h"
#include <boost/lexical_cast.hpp>
#include "boost/foreach.hpp"

namespace nsSerializerTerrainItem_XML
{
  const char* sTerrain   = "Terrain";
  const char* sGeometry  = "Geometry";
  const char* sLength    = "Length";
  const char* sWidth     = "Width";
  const char* sGraphic   = "Graphic";
  const char* sColor     = "Color";
  const char* sNormal    = "Normal";
  const char* sHeightMap = "HeightMap";
  const char* sPoint     = "Point";
  const char* sX         = "x";
  const char* sY         = "y";
  const char* sH         = "h";
  const char* sU         = "u";
  const char* sV         = "v";
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
  LoadGeometry();
  LoadGraphic();
  LoadHeightMap();
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

  SaveGeometry();
  SaveGraphic();
  SaveHeightMap();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadGeometry()
{
  if(mXML->EnterSection(sGeometry,0))
  {
    std::string key, value;
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      LoadProperty(iProperty, key, value);
      if(key==sLength)
        mTerrain->mLength = boost::lexical_cast<float>(value.data());
      if(key==sWidth)
        mTerrain->mWidth = boost::lexical_cast<float>(value.data());
    }
    mXML->LeaveSection();
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
      if(key==sColor)
        mTerrain->mGraphic.color  = value;
      if(key==sNormal)
        mTerrain->mGraphic.normal = value;
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadHeightMap()
{
  if(mXML->EnterSection(sHeightMap,0))
  {
    int cntPoint = mXML->GetCountSection(sPoint);
    for( int iPoint = 0 ; iPoint < cntPoint ; iPoint++ )
    {
      std::string x = mXML->ReadSectionAttr(sPoint, iPoint, sX);
      std::string y = mXML->ReadSectionAttr(sPoint, iPoint, sY);
      std::string h = mXML->ReadSectionAttr(sPoint, iPoint, sH);
      std::string u = mXML->ReadSectionAttr(sPoint, iPoint, sU);
      std::string v = mXML->ReadSectionAttr(sPoint, iPoint, sV);

      TTerrainItem::TPoint point;
      point.x = boost::lexical_cast<float>(x.data());
      point.y = boost::lexical_cast<float>(y.data());
      point.h = boost::lexical_cast<float>(h.data());
      point.u = boost::lexical_cast<float>(u.data());
      point.v = boost::lexical_cast<float>(v.data());

      mTerrain->mHeightMap.push_back(point);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveGeometry()
{
	if(mXML->AddSectionAndEnter(sGeometry))
	{
		std::string key   = sLength;
		std::string value = boost::lexical_cast<std::string>(mTerrain->mLength);
		SaveProperty(key, value);
		key   = sWidth;
		value = boost::lexical_cast<std::string>(mTerrain->mWidth);
		SaveProperty(key, value);
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveGraphic()
{
	if(mXML->AddSectionAndEnter(sGraphic))
	{
		std::string key   = sColor;
		std::string value = mTerrain->mGraphic.color;
		SaveProperty(key, value);
		key   = sNormal;
		value = mTerrain->mGraphic.normal;
		SaveProperty(key, value);
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveHeightMap()
{
	if(mXML->AddSectionAndEnter(sHeightMap))
	{
		BOOST_FOREACH(TTerrainItem::TPoint& point, mTerrain->mHeightMap)
		{
			TAttrInfo attr[5];
			attr[0].Name  = sX;
			attr[0].Value = boost::lexical_cast<std::string>(point.x);
			attr[1].Name  = sY;
			attr[1].Value = boost::lexical_cast<std::string>(point.y);
			attr[2].Name  = sH;
			attr[2].Value = boost::lexical_cast<std::string>(point.h);
			attr[3].Name  = sU;
			attr[3].Value = boost::lexical_cast<std::string>(point.u);
			attr[4].Name  = sV;
			attr[4].Value = boost::lexical_cast<std::string>(point.v);

			mXML->AddSection(sPoint, 5, &attr[0]);
		}
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
