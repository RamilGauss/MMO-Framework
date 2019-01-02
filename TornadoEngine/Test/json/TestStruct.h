/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <string>
#include <list>
#include <set>

struct TTestStruct
{
  std::string    password;
  unsigned short port = 0;
  bool flag = false;
  std::list<int> numList;
  std::set<std::string> strSet;
};