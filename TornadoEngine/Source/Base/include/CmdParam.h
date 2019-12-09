/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <string>
#include <vector>
#include <set>

#include "TypeDef.h"

class DllExport TCmdParam
{
  typedef std::multimap<std::string, std::string> TMultiMapStrStr;
  typedef TMultiMapStrStr::iterator TMultiMapStrStrIt;

  typedef std::set<std::string> TSetStr;
  typedef TSetStr::iterator TSetStrIt;

  TMultiMapStrStr mMapKey;
  TSetStr mSetDefKey;
  TSetStr mSetFoundKey;
public:
  TCmdParam();
  virtual ~TCmdParam();
  // задать список возможных ключей
  void AddDefKey( std::string& key );
  void SetDefKey( std::vector<std::string>& vecKey );
  // вставка элементов командной строки, парсинг по заданным ключам
  void SetArg( std::vector<std::string>& vecArgv );
  // есть ли такой ключ?
  bool IsKey( std::string& sKey );
  // определить кол-во значений, идущих после ключа в списке аргументов 
  // до следующего ключа или до окончания списка
  int  GetCountValueByKey( std::string& sKey );
  // получить строку по ключу
  bool GetByKey( std::string& sKey, int index, std::string& sOut );
protected:
  bool FindInDefKey( std::string& sKey );
};
