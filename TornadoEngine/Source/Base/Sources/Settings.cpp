/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Settings.h"
#include "MakerXML.h"
#include "IXML.h"
#include "SaveToFile.h"

namespace nsSettings
{
  const char* sContent     = "Content";
  const char* sApplication = "Application";
  const char* sName        = "name";
  const char* sGroup        = "Group";
  const char* sEntry        = "Entry";
  const char* sKey          = "key";
  const char* sValue        = "value";
}

using namespace nsSettings;

TSettings::TSettings()
{
  TMakerXML makerXML;
  mXML = makerXML.New();
}
//-----------------------------------------------------------------------
TSettings::~TSettings()
{
  TMakerXML makerXML;
  makerXML.Delete(mXML);
  mXML = NULL;
}
//-----------------------------------------------------------------------
void TSettings::Init(std::string pathFileXML)
{
  // пытаемся загрузить
  if( TryLoad(pathFileXML) )
    return;// OK

  // либо файл некорректен, либо не существует
  if( CreateDefault((char*)pathFileXML.data())==false )
  {
    BL_FIX_BUG();
    return;// FAIL
  }

  if( TryLoad(pathFileXML)==false )
  {
    BL_FIX_BUG();
    return;// FAIL
  }
}
//-----------------------------------------------------------------------
void TSettings::BeginApplication(std::string nameApp)
{
  mNameApplication = nameApp;

  int cntApp = mXML->GetCountSection(sApplication);
  for( int iApp = 0 ; iApp < cntApp ; iApp++ )
  {
    std::string nameAppFromXML = mXML->ReadSectionAttr(sApplication, iApp, sName);
    if( nameAppFromXML==nameApp )
    {
      mXML->EnterSection(sApplication,iApp);
      return;
    }
  }
  TAttrInfo attr;
  attr.Name  = sName;
  attr.Value = nameApp;
  mXML->AddSectionAndEnter(sApplication,1,&attr);
  mXML->Save();
}
//-----------------------------------------------------------------------
std::string TSettings::GetNameApplication()
{
  return mNameApplication;
}
//-----------------------------------------------------------------------
void TSettings::BeginGroup(std::string nameGroup)
{
  if( mNameCurrentGroup.length() )
    mXML->LeaveSection();

  mNameCurrentGroup = nameGroup;
  int cntGroup = mXML->GetCountSection(sGroup);

  for( int iGroup = 0 ; iGroup < cntGroup ; iGroup++ )
  {
    std::string nameGroupAppFromXML = mXML->ReadSectionAttr(sGroup, iGroup, sName);
    if( nameGroupAppFromXML==nameGroup )
    {
      mXML->EnterSection(sGroup,iGroup);
      return;
    }
  }

  TAttrInfo attr;
  attr.Name  = sName;
  attr.Value = nameGroup;
  mXML->AddSectionAndEnter(sGroup,1,&attr);
  mXML->Save();
}
//-----------------------------------------------------------------------
std::string TSettings::GetNameCurrentGroup()
{
  return mNameCurrentGroup;
}
//-----------------------------------------------------------------------
bool TSettings::CreateDefault(char* sPath)
{
  TSaveToFile creater;
  if( creater.ReOpen(sPath)==false )
    return false;

  std::string content;
  content  = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
  content += "<!-- Qt-style, типа запись в реестр, но в XML -->\n";
  content += "<Content>\n";
  content += "</Content>\n";

  creater.Write((void*)content.data(), content.length());
  return true;
}
//-----------------------------------------------------------------------
void TSettings::WriteEntryPrivate(std::string key, std::string value)
{
  if( mNameCurrentGroup.length()==0 )
  {
    BL_FIX_BUG();
    return;
  }

  int cnt = mXML->GetCountSection(sEntry);
  for( int i = 0 ; i < cnt ; i++ )
  {
    std::string keyFromXML = mXML->ReadSectionAttr(sEntry,i,sKey);
    if( keyFromXML==key )
    {
      mXML->WriteSectionAttr(sEntry,i, sValue, value);
      mXML->Save();
      return;
    }
  }
  // не нашли
  TAttrInfo attr[2];
  attr[0].Name  = sKey;
  attr[0].Value = key;
  attr[1].Name  = sValue;
  attr[1].Value = value;
  mXML->AddSection(sEntry,2,&attr[0]);
  mXML->Save();
}
//-----------------------------------------------------------------------
bool TSettings::TryLoad(std::string pathFileXML)
{
  if( mXML->Load(pathFileXML.data())==false )
    return false;
  return mXML->EnterSection(sContent,0);
}
//-----------------------------------------------------------------------
std::string TSettings::ReadEntryPrivate(std::string key)
{
  if( mNameCurrentGroup.length()==0 )
  {
    BL_FIX_BUG();
    return "";
  }

  int cnt = mXML->GetCountSection(sEntry);
  for( int i = 0 ; i < cnt ; i++ )
  {
    std::string keyFromXML = mXML->ReadSectionAttr(sEntry,i,sKey);
    if( keyFromXML==key )
      return mXML->ReadSectionAttr(sEntry, i, sValue);
  }
  return "";
}
//-----------------------------------------------------------------------
