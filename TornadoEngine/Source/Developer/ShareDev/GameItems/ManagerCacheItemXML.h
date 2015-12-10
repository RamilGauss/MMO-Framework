/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerCacheItemXMLH
#define ManagerCacheItemXMLH

#include <map>
#include <set>

#include "TypeDef.h"

struct TBaseItem;
class IXML;

class DllExport TManagerCacheItemXML
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
  TManagerCacheItemXML();

  void Init(IXML* xml);
  
  int GetCountByStrType(std::string& type);
  bool GetNameByIndex(std::string& type, int index, std::string& name);
protected:

};

#endif
