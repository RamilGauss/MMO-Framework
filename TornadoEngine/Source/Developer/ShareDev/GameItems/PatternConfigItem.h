/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternConfigItemH
#define PatternConfigItemH

#include "BaseItem.h"

#include <map>
#include <vector>


struct DllExport TPatternConfigItem : public TBaseItem
{
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;
  //---------------------------------------------------------
  typedef std::map<std::string,TMapStrStr> TMapStrMap;// для объекта-поведения
  typedef TMapStrMap::iterator   TMapStrMapIt;
  typedef TMapStrMap::value_type TMapStrMapVT;
  //---------------------------------------------------------
  TMapStrMap mMapVariant;

  TPatternConfigItem(std::string& name);
};

#endif
