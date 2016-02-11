/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerTableSoundItem_XML.h"
#include "IXML.h"
#include "TableSoundItem.h"
#include <errno.h>


namespace nsSerializerTableSoundItem_XML
{
	const char* sTableSound  = "TableSound";
	const char* sRange       = "Range";
	const char* sVelocity    = "Velocity";
	const char* sAngle       = "Angle";
	const char* sMass        = "Mass";
	const char* sMaterial    = "Material";
	const char* sCollision   = "Collision";
	const char* sSound       = "Sound";
	const char* sCombination = "Combination";
	const char* sParam       = "Param";
	const char* sVariant     = "Variant";

  const char* sMass0       = "Mass0";
  const char* sMaterial0   = "Material0";
  const char* sMass1       = "Mass1";
  const char* sMaterial1   = "Material1";
}

using namespace nsSerializerTableSoundItem_XML;

TSerializerTableSoundItem_XML::TSerializerTableSoundItem_XML():
TBaseSerializerItem_XML(sTableSound)
{
	mTableSound = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerTableSoundItem_XML::~TSerializerTableSoundItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTableSoundItem_XML::Load(TBaseItem* pItem)
{
	mTableSound = (TTableSoundItem*)pItem;

	bool resEnter = EnterByType(mTableSound->mName);
	if(resEnter==false)
		return false;

  LoadRange();
  LoadCollision();
	return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerTableSoundItem_XML::Save(TBaseItem* pItem)
{
	mTableSound = (TTableSoundItem*)pItem;
	RemoveSection(mTableSound->mName);// грохнуть всю запись, связанную с данным item

	bool resEnter = AddAndEnterByType(mTableSound->mName);
	if(resEnter==false)
		return false;

  SaveRange();
  SaveCollision();
	return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadRange()
{
  if(mXML->EnterSection(sRange,0))
  {
    LoadRangeVelocity();
    LoadRangeAngle();
    LoadRangeMass();
    LoadRangeMaterial();

    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadCollision()
{
  if(mXML->EnterSection(sCollision,0))
  {
    int cntSound = mXML->GetCountSection(sSound);
    for( int iSound = 0 ; iSound < cntSound ; iSound++ )
    {
      if(mXML->EnterSection(sSound, iSound))
      {
        LoadSound();
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::SaveRange()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::SaveCollision()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadRangeVelocity()
{
  if(mXML->EnterSection(sVelocity,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
      {
        float v = (float)atof(value.data());
        int index = atoi(key.data());
        if(errno!=ERANGE)
          mTableSound->mMapVelocity.insert(TTableSoundItem::TMapFloatIntVT(v, index));
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadRangeAngle()
{
  if(mXML->EnterSection(sAngle,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
      {
        float v = (float)atof(value.data());
        int index = atoi(key.data());
        if(errno!=ERANGE)
          mTableSound->mMapAngle.insert(TTableSoundItem::TMapFloatIntVT(v, index));
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadRangeMass()
{
  if(mXML->EnterSection(sMass,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
      {
        float v = (float)atof(value.data());
        int index = atoi(key.data());
        if(errno!=ERANGE)
          mTableSound->mMapMass.insert(TTableSoundItem::TMapFloatIntVT(v, index));
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadRangeMaterial()
{
  if(mXML->EnterSection(sMaterial,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
      {
        int index = atoi(key.data());
        if(errno!=ERANGE)
          mTableSound->mMapMaterial.insert(TTableSoundItem::TMapStrIntVT(value, index));
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::SaveRangeVelocity()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::SaveRangeAngle()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::SaveRangeMass()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::SaveRangeMaterial()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadSound()
{
  if(mXML->EnterSection(sCombination,0))
  {
    LoadCombination();
    mXML->LeaveSection();
  }

  if(mXML->EnterSection(sParam,0))
  {
    LoadParam();
    mXML->LeaveSection();
  }

  MakeAndInsertSound();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadCombination()
{
  mMapCombination.clear();

  int cntProperty = GetCountProperty();
  for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
  {
    std::string key, value;
    if(LoadProperty(iProperty, key, value))
    {
      int index = atoi(value.data());
      if(errno!=ERANGE)
        mMapCombination.insert(TTableSoundItem::TMapStrIntVT(key, index));
    }
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::LoadParam()
{
  mVecMapStrStr.clear();

  int cntVariant = mXML->GetCountSection(sVariant);
  for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
  {
    if(mXML->EnterSection(sVariant,iVariant))
    {
      TTableSoundItem::TMapStrStr mapStrStr;
      std::string key, value;
      if(LoadProperty(iVariant, key, value))
      {
        int cntProperty = GetCountProperty();
        for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
        {
          std::string key, value;
          if(LoadProperty(iProperty, key, value))
            mapStrStr.insert(TTableSoundItem::TMapStrStrVT(key,value));
        }
      }
      mVecMapStrStr.push_back(mapStrStr);
      mXML->LeaveSection();
    }
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerTableSoundItem_XML::MakeAndInsertSound()
{
  TTableSoundItem::TMapStrIntIt VelocityIt = mMapCombination.find(sVelocity);
  if(VelocityIt==mMapCombination.end())
    return;

  TTableSoundItem::TMapStrIntIt Mass0It = mMapCombination.find(sMass0);
  if(Mass0It==mMapCombination.end())
    return;

  TTableSoundItem::TMapStrIntIt Material0It = mMapCombination.find(sMaterial0);
  if(Material0It==mMapCombination.end())
    return;

  TTableSoundItem::TMapStrIntIt Mass1It = mMapCombination.find(sMass1);
  if(Mass1It==mMapCombination.end())
    return;

  TTableSoundItem::TMapStrIntIt Material1It = mMapCombination.find(sMaterial1);
  if(Material1It==mMapCombination.end())
    return;

  TTableSoundItem::TMapStrIntIt AngleIt = mMapCombination.find(sAngle);
  if(AngleIt==mMapCombination.end())
    return;

  TTableSoundItem::TCombination combination;

  combination.velocity  = VelocityIt ->second;
  combination.mass0     = Mass0It    ->second;
  combination.mass1     = Mass1It    ->second;
  combination.material0 = Material0It->second;
  combination.material1 = Material1It->second;
  combination.angle     = AngleIt    ->second;

  mTableSound->Add(combination, mVecMapStrStr);
}
//-------------------------------------------------------------------------------------------------------
