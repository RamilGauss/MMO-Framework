/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <set>
#include <string>

#include "TypeDef.h"

struct TBaseItem;
class IXML;

class DllExport TManagerCacheItem_XML
{
  IXML* mXML;

  // кэш
  typedef std::set<std::string> TSetStr;// все имена итэмов данного типа
  typedef TSetStr::iterator     TSetStrIt;

  typedef std::map<std::string,TSetStr> TMapStrSet;
  typedef TMapStrSet::iterator          TMapStrSetIt;
  typedef TMapStrSet::value_type        TMapStrSetVT;

  TMapStrSet mMapStrType_SetName;// для поиска кэшированных имен итэмов в XML по типам

public:
  TManagerCacheItem_XML();

  void Init(IXML* xml);
  
  bool IsExist(std::string& type, std::string& name);
  
  int GetCountByStrType(std::string& type);
  bool GetNameByIndex(std::string& type, int index, std::string& name);
protected:

};
