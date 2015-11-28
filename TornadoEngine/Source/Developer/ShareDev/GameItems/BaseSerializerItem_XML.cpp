/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseSerializerItem_XML.h"
#include "IXML.h"

namespace nsBaseSerializerItem_XML
{
  // Common
  const char* sName     = "name";
  const char* sProperty = "Property";
  const char* sKey      = "key";
  const char* sValue    = "value";
}

using namespace nsBaseSerializerItem_XML;

TBaseSerializerItem_XML::TBaseSerializerItem_XML(std::string type)
{
  mType = type;
}
//------------------------------------------------------------------------------
TBaseSerializerItem_XML::~TBaseSerializerItem_XML()
{
  mXML = NULL;
}
//------------------------------------------------------------------------------
void TBaseSerializerItem_XML::Init(IXML* xml)
{
  mXML = xml;
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_XML::EnterByType(std::string& name)
{
  if(EnterRoot()==false)
    return false;
  int cnt = mXML->GetCountSection(mType.data());
  if(cnt==0)
    return false;

  for(int i = 0 ; i < cnt ; i++)
  {
    std::string sAttrName = mXML->ReadSectionAttr(mType.data(), i, sName);
    if(name==sAttrName)
      return mXML->EnterSection(mType.data(), i);
  }
  return false;
}
//------------------------------------------------------------------------------
int TBaseSerializerItem_XML::GetCountProperty()
{
  return mXML->GetCountSection(sProperty);
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_XML::LoadProperty(int index, std::string& key, std::string& value)
{
  if(index>=GetCountProperty())
    return false;

  key = mXML->ReadSectionAttr(sProperty, index, sKey);
  value = mXML->ReadSectionAttr(sProperty, index, sValue);
  return true;
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_XML::EnterRoot()
{
  mXML->ResetPos();
  std::string sRoot = mXML->GetNameSection(0);
  return mXML->EnterSection(sRoot.data(), 0);
}
//------------------------------------------------------------------------------
std::string TBaseSerializerItem_XML::ReadName(int index, IXML* xml)
{
  return xml->ReadSectionAttr(index, sName );
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_XML::RemoveSection(std::string& name)
{
  if(EnterRoot()==false)
    return false;
  int cnt = mXML->GetCountSection(mType.data());
  if(cnt==0)
    return false;

  for(int i = 0 ; i < cnt ; i++)
  {
    std::string sAttrName = mXML->ReadSectionAttr(mType.data(), i, sName);
    if(name==sAttrName)
      return mXML->RemoveSection(mType.data(), i);
  }
  return false;
}
//------------------------------------------------------------------------------
std::string TBaseSerializerItem_XML::Type()
{
  return mType;
}
//------------------------------------------------------------------------------
