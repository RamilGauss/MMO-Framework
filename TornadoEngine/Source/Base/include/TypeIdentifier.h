/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <type_traits>
#include <cstddef>
#include <atomic>
#include "TypeDef.h"

// The idea has been taken from https://github.com/skypjack/entt/blob/master/src/entt/core/family.hpp
// Remove static from type(). Static values are the evil! In different Dll different id exists.

// use: SingletonManager()->Get<TTypeIdentifier<ClassSpace>>()
// ClassSpace - space for unique identity
template<typename...>
class DllExport TTypeIdentifier
{
public:
  typedef unsigned int TypeCounter;
  typedef std::atomic<TypeCounter> AtomicTypeCounter;
private:
  AtomicTypeCounter atc;

  template<typename...>
  static TypeCounter UniqueByType( AtomicTypeCounter& global )
  {
    static const TypeCounter value = global.fetch_add( 1 );
    return value;
  }

  template<typename... Type>
  TypeCounter _type()
  {
    return UniqueByType<std::decay_t<Type>...>( atc );
  }
public:
  template<typename T>
  TypeCounter type()
  {
    return _type<T>();
  }

  // for indifferent id for combinations, <T0,T1> == <T2,T1>
  template<typename T0, typename T1>
  TypeCounter type()
  {
    auto t0 = type<T0>();
    auto t1 = type<T1>();
    assert( t0 != t1 );
    if ( t0 < t1 )
      return _type<T0, T1>();
    return _type<T1, T0>();
  }

  // for indifferent id for combinations, <T0,T1,T2> == <T2,T1,T0> etc.
  template<typename T0, typename T1, typename T2>
  TypeCounter type()
  {
    auto t0 = type<T0>();
    auto t1 = type<T1>();
    auto t2 = type<T2>();
    assert( t0 != t1 );
    assert( t1 != t2 );
    assert( t0 != t2 );
    auto minT = std::min( std::min( t0, t1 ), std::min( t1, t2 ) );

    if ( minT == t0 )
    {
      if ( t1 < t2 )
        return _type<T0, T1, T2>();
      return _type<T0, T2, T1>();
    }
    if ( minT == t1 )
    {
      if ( t0 < t2 )
        return _type<T1, T0, T2>();
      return _type<T1, T2, T0>();
    }
    if ( t0 < t1 )
      return _type<T2, T0, T1>();
    return _type<T2, T1, T0>();
  }
};

typedef TTypeIdentifier<struct GlobalTypeIdentifier> TGlobalTypeIdentifier;
extern DllExport TGlobalTypeIdentifier* GlobalTypeIdentifier();// for use in SingletonManager 
