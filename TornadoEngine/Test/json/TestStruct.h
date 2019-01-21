/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include "BaseStruct.h"

REFLECTION_ATTRIBUTE
struct TTestStruct : public TBaseStruct
{
  std::string    password;
  unsigned short port = 0;
  bool flag = false;

  // array
  std::list<int> numList;
  std::set<std::string> strSet;
  std::vector<int> numVector;
  std::set<int> intSet;

  // map
  std::map<int, std::string> intStrMap;
  std::map<std::string, std::string> strStrMap;
  std::map<std::string, int> strIntMap;
  std::map<std::string, bool> strBoolMap;

  // ser array
  std::vector<TBaseStruct> baseVec;
  std::vector<TBaseStruct*> basePtrVec;
  std::vector<std::shared_ptr<TBaseStruct>> baseSPVec;

  // map
  std::map<std::string, TBaseStruct> strBaseMap;
  std::map<std::string, TBaseStruct*> strBasePtrMap;
  std::map<std::string, std::shared_ptr<TBaseStruct>> strBaseSPMap;

  std::map<int, TBaseStruct> intBaseMap;
  std::map<int, TBaseStruct*> intBasePtrMap;
  std::map<int, std::shared_ptr<TBaseStruct>> intBaseSPMap;
};
