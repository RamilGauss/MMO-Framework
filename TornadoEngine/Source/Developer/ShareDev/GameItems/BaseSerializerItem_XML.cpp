/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseSerializerItem_XML.h"
#include "IXML.h"
#include <errno.h>

namespace nsBaseSerializerItem_XML
{
  // Common
  const char* sName     = "name";
  const char* sProperty = "Property";
  const char* sKey      = "key";
  const char* sValue    = "value";

  const char* sAxeX     = "x";
  const char* sAxeY     = "y";
  const char* sAxeZ     = "z";

  const int CountAxes3  = 3;
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
bool TBaseSerializerItem_XML::AddAndEnterByType(std::string& name)
{
  TAttrInfo attr;
  attr.Name  = sName;
  attr.Value = name;
  return mXML->AddSectionAndEnter(mType.data(), 1, &attr);
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
bool TBaseSerializerItem_XML::SaveProperty(std::string& key, std::string& value)
{
  TAttrInfo attr[2];
  attr[0].Name  = sKey;
  attr[0].Value = key;
  attr[1].Name  = sValue;
  attr[1].Value = value;
  return mXML->AddSection(sProperty, 2, &attr[0]);
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_XML::LoadVector3ByProperty(nsMathTools::TVector3& v3)
{
  std::string key, value;
  int cnt = GetCountProperty();
  
  if(cnt!=CountAxes3)// кол-во компонентов в векторе
    return false;

  for( int i = 0 ; i < cnt ; i++ )
  {
    if(LoadProperty(i,key,value))
    {
      if(key==sAxeX)
        v3.x = atof(value.data());
      else if(key==sAxeY)
        v3.y = atof(value.data());
      else if(key==sAxeZ)
        v3.z = atof(value.data());

      if(errno==ERANGE)
        return false;
    }
    else 
      return false;
  }
  return true;
}
//------------------------------------------------------------------------------
bool TBaseSerializerItem_XML::SaveVector3ByProperty(nsMathTools::TVector3& v3)
{
  std::string key, value;
  char str[50];

  key = sAxeX;
  _gcvt_s(str, sizeof(str), v3.x, 9);
  value = str;
  if(SaveProperty(key,value)==false)
    return false;
  
  key = sAxeY;
  _gcvt_s(str, sizeof(str), v3.y, 9);
  value = str;
  if(SaveProperty(key,value)==false)
    return false;

  key = sAxeZ;
  _gcvt_s(str, sizeof(str), v3.z, 9);
  value = str;
  if(SaveProperty(key,value)==false)
    return false;

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
