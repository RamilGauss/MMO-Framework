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
  const char* sTerrain   = "Terrain";
  const char* sGeometry  = "Geometry";
  const char* sLength    = "Length";
  const char* sWidth     = "Width";
  const char* sGraphic   = "Graphic";
  const char* sLOD       = "LOD"; 
  const char* sDistance  = "distance";
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
        mTerrain->mLength = atof(value.data());
      if(key==sWidth)
        mTerrain->mWidth = atof(value.data());
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::LoadGraphic()
{
  if(mXML->EnterSection(sGraphic,0))
  {
    int cntLOD = mXML->GetCountSection(sLOD);
    for( int iLOD = 0 ; iLOD < cntLOD ; iLOD++ )
    {
      TTerrainItem::TLOD lod;
      std::string distance = mXML->ReadSectionAttr(sLOD, iLOD, sDistance);
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
        mTerrain->mGraphic.push_back(lod);
        mXML->LeaveSection();
      }
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
      point.x = atof(x.data());
      point.y = atof(y.data());
      point.h = atof(h.data());
      point.u = atof(u.data());
      point.v = atof(v.data());

      mTerrain->mHeightMap.push_back(point);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveGeometry()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveGraphic()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTerrainItem_XML::SaveHeightMap()
{

}
//-------------------------------------------------------------------------------------------------------
