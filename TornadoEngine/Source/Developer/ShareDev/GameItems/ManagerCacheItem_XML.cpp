/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ManagerCacheItem_XML.h"
#include "BaseSerializerItem_XML.h"
#include "IXML.h"


TManagerCacheItem_XML::TManagerCacheItem_XML()
{
  mXML = NULL;
}
//------------------------------------------------------------------------------------------------
void TManagerCacheItem_XML::Init(IXML* xml)
{
  mXML = xml;
  mXML->ResetPos();
  std::string sRoot = mXML->GetNameSection(0);
  if(mXML->EnterSection(sRoot.data(), 0))
  {
    int cnt = mXML->GetCountSection();
    for( int i = 0 ; i < cnt ; i++ )
    {
      std::string sType = mXML->GetNameSection(i);
      TMapStrSetIt fit = mMapStrType_SetName.find(sType);
      if(fit==mMapStrType_SetName.end())
      {
        mMapStrType_SetName.insert(TMapStrSetVT(sType,TSetStr()));
        fit = mMapStrType_SetName.find(sType);
      }
      std::string sName = TBaseSerializerItem_XML::ReadName(i, mXML);
      if(sName.length())
        fit->second.insert(sName);
    }
  }
}
//------------------------------------------------------------------------------------------------
int TManagerCacheItem_XML::GetCountByStrType(std::string& type)
{
  TMapStrSetIt fit = mMapStrType_SetName.find(type);
  if(fit==mMapStrType_SetName.end())
    return 0;

  return fit->second.size();
}
//------------------------------------------------------------------------------------------------
bool TManagerCacheItem_XML::GetNameByIndex(std::string& type, int index, std::string& name)
{
  TMapStrSetIt fit = mMapStrType_SetName.find(type);
  if(fit==mMapStrType_SetName.end())
    return false;

  if(index >= int(fit->second.size()))
    return false;
  TSetStrIt bit = fit->second.begin();
  for(int i = 0 ; i < index ; i++)
    bit++;
  name = *bit;
  return true;
}
//------------------------------------------------------------------------------------------------
bool TManagerCacheItem_XML::IsExist(std::string& type, std::string& name)
{
  TMapStrSetIt fitByType = mMapStrType_SetName.find(type);
  if(fitByType==mMapStrType_SetName.end())
    return false;

  TSetStrIt fitByName = fitByType->second.find(name);
  if( fitByName==fitByType->second.end() )
    return false;
  return true;
}
//------------------------------------------------------------------------------------------------
