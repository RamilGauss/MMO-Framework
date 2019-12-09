/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

namespace ShuffledComponents
{
  struct A
  {
    int a;
    bool operator<( const A &o ) const
    {
      return a < o.a;
    }

    bool operator==( const A &other ) const
    {
      return (a == other.a);
    }
  };

  struct B
  {
    int b;
  };

  struct C
  {
    int c;
  };

  struct D
  {
    int d;
  };

  struct E
  {
    int e;
  };

  struct F
  {
    int f;
  };
}

namespace std
{
  template<> struct hash<ShuffledComponents::A>
  {
    typedef ShuffledComponents::A argument_type;
    typedef std::size_t result_type;
    result_type operator()( argument_type const& s ) const noexcept
    {
      return s.a;
    }
  };
}
