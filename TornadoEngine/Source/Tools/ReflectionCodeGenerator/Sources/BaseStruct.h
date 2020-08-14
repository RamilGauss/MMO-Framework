/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <string>
#include <list>
#include <set>
#include <map>

namespace nsBS
{
#pragma REFLECTION_ATTRIBUTE
#pragma Table
  struct TBaseStruct
  {
    union
    {
      struct
      {
        float a;
      }ss;
      unsigned char m[4];
    };

    std::map<int, int> iiMap;

    float a, b, c, d;

#pragma Primary key
#pragma Index
    std::string s = "0123456789";

    int Foo( int a, int b )
    {
      return 0;
    }
    static int StaticFoo( int a, int b )
    {
      return 0;
    }
    virtual int VirtualFoo( int a, int b )
    {
      return 0;
    }
  };
}
