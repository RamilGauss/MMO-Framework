/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <boost/lexical_cast.hpp>
#include <typeinfo.h>

#include "TypeDef.h"
#include "BL_Debug.h"

class IXML;

// not thread save

class DllExport TSettings
{
  IXML* mXML;

  // есть всегда
  std::string mNameApplication;
  // если нет, то не входили в группу, 
  // если есть, то сам выйдет и войдёт в нужную
  std::string mNameCurrentGroup;

public:
  TSettings();
  virtual ~TSettings();

  // если не найдёт, то создаст
  void Init(std::string pathFileXML);

  // если не найдёт, то создаст
  void BeginApplication(std::string nameApp);
  std::string GetNameApplication();

  // если не найдёт, то создаст
  void BeginGroup(std::string nameGroup);
  std::string GetNameCurrentGroup();
  
  // если не найдёт, то создаст
  template <typename T>
  void WriteEntry(std::string key, T value);

  template <typename T>
  T ReadEntry( std::string key, T* defaultValue = NULL);
protected:
  bool CreateDefault(char* sPath);
  
  void WriteEntryPrivate(std::string key, std::string value);
  std::string ReadEntryPrivate(std::string key);

  bool TryLoad(std::string pathFileXML);
};
//-----------------------------------------------------------------------
template <typename T>
void TSettings::WriteEntry(std::string key, T value)
{
  std::string strValue = boost::lexical_cast<std::string>(value);
  WriteEntryPrivate(key, strValue);
}
//-----------------------------------------------------------------------
template <typename T>
T TSettings::ReadEntry( std::string key, T* defaultValue)
{
  T t;
  std::string value = ReadEntryPrivate(key);
  if( value.length() )
    t = boost::lexical_cast<T>(value);
  else
    if( defaultValue )
      t = *defaultValue;
  return t;
}
