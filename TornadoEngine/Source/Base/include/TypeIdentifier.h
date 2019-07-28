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
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <assert.h>

#include "TypeDef.h"
#include "RemoveIthType.h"

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
  const TypeCounter UniqueByType( AtomicTypeCounter& global )
  {
    static const TypeCounter value = global.fetch_add( 1 );
    return value;
  }

  template<typename... Type>
  const TypeCounter _type()
  {
    return UniqueByType<std::decay_t<Type>...>( atc );
  }

  template<typename T0, typename T1, typename T2>
  TypeCounter TypeLm3( TypeCounter t1, TypeCounter t2 )
  {
    if ( t1 < t2 )
      return _type<T0, T1, T2>();
    return _type<T0, T2, T1>();
  }

  template<typename T0, typename T1, typename T2, typename T3>
  TypeCounter TypeLm4( TypeCounter t1, TypeCounter t2, TypeCounter t3 )
  {
    auto minT = std::min( std::min( t1, t2 ), std::min( t2, t3 ) );
    if ( minT == t1 )
    {
      if ( t2 < t3 )
        return _type<T0, T1, T2, T3>();
      return _type<T0, T1, T3, T2>();
    }
    if ( minT == t2 )
    {
      if ( t1 < t3 )
        return _type<T0, T2, T1, T3>();
      return _type<T0, T2, T3, T1>();
    }
    // 3
    if ( t1 < t2 )
      return _type<T0, T3, T1, T2>();
    return _type<T0, T3, T2, T1>();
  }

  template<typename T0, typename T1, typename T2, typename T3, typename T4>
  TypeCounter TypeLm5( TypeCounter t1, TypeCounter t2, TypeCounter t3, TypeCounter t4 )
  {
    auto minT = std::min( std::min( t1, t2 ), std::min( t2, t3 ) );
    minT = std::min( minT, t4 );
    if ( minT == t1 )
    {
      auto minT1 = std::min( t2, t3 );
      minT1 = std::min( minT1, t4 );
      if ( minT1 == t2 )
      {
        if ( t3 < t4 )
          return _type<T0, T1, T2, T3, T4>();
        return _type<T0, T1, T2, T4, T3>();
      }
      if ( minT1 == t3 )
      {
        if ( t2 < t4 )
          return _type<T0, T1, T3, T2, T4>();
        return _type<T0, T1, T3, T4, T2>();
      }
      if ( t2 < t3 )
        return _type<T0, T1, T4, T2, T3>();
      return _type<T0, T1, T4, T3, T2>();
    }
    //TODO: ###
    if ( minT == t2 )
    {
      if ( t1 < t3 )
        return _type<T0, T2, T1, T3>();
      return _type<T0, T2, T3, T1>();
    }
    if ( minT == t3 )
    {
      if ( t1 < t2 )
        return _type<T0, T3, T1, T2>();
      return _type<T0, T3, T2, T1>();
    }
    if ( t1 < t2 )
      return _type<T0, T3, T1, T2>();
    return _type<T0, T3, T2, T1>();
  }

  //template<typename T>
  //TypeCounter type()
  //{
  //  return _type<T>();
  //}

  //template<typename T0, typename T1>
  //TypeCounter type()
  //{
  //  static TypeCounter ret = -1;
  //  if ( ret != -1 )
  //    return ret;

  //  std::map<TypeCounter, std::function<TypeCounter()>> m;

  //  auto t0 = _type<T0>();
  //  auto t1 = _type<T1>();
  //  m.insert( { t0, [this]()
  //  {
  //    return _type<T0, T1>();
  //  } } );
  //  m.insert( { t1, [this]()
  //  {
  //    return _type<T1, T0>();
  //  } } );
  //  ret = m.begin()->second();
  //  assert( m.size() != 2 );
  //  return ret;
  //}

  //template<typename T0, typename T1, typename T2>
  //TypeCounter type()
  //{
  //  static TypeCounter ret = -1;
  //  if ( ret != -1 )
  //    return ret;

  //  std::map<TypeCounter, std::function<TypeCounter()>> m;

  //  auto t0 = _type<T0>();
  //  auto t1 = _type<T1>();
  //  auto t2 = _type<T2>();
  //  m.insert( { t0, [this, t1, t2]()
  //  {
  //    return TypeLm3<T0,T1,T2>( t1, t2 );
  //  } } );
  //  m.insert( { t1, [this, t0, t2]()
  //  {
  //    return TypeLm3<T1,T0,T2>( t0, t2 );
  //  } } );
  //  m.insert( { t2, [this, t0, t1]()
  //  {
  //    return TypeLm3<T2,T0,T1>( t0, t1 );
  //  } } );
  //  ret = m.begin()->second();
  //  assert( m.size() != 3 );
  //  return ret;
  //}

  //template<typename T0, typename T1, typename T2, typename T3>
  //TypeCounter type()
  //{
  //  static TypeCounter ret = -1;
  //  if ( ret != -1 )
  //    return ret;

  //  std::map<TypeCounter, std::function<TypeCounter()>> m;

  //  auto t0 = _type<T0>();
  //  auto t1 = _type<T1>();
  //  auto t2 = _type<T2>();
  //  auto t3 = _type<T3>();
  //  m.insert( { t0, [this, t1, t2, t3]()
  //  {
  //    return TypeLm4<T0,T1,T2,T3>( t1, t2, t3 );
  //  } } );
  //  m.insert( { t1, [this, t0, t2, t3]()
  //  {
  //    return TypeLm4<T1,T0,T2,T3>( t0, t2, t3 );
  //  } } );
  //  m.insert( { t2, [this, t0, t1, t3]()
  //  {
  //    return TypeLm4<T2,T0,T1,T3>( t0, t1, t3 );
  //  } } );
  //  m.insert( { t3, [this, t0, t1, t2]()
  //  {
  //    return TypeLm4<T3,T0,T1,T2>( t0, t1, t2 );
  //  } } );
  //  ret = m.begin()->second();
  //  assert( m.size() != 4 );
  //  return ret;
  //}

  //template<typename T0, typename T1, typename T2, typename T3, typename T4>
  //TypeCounter type()
  //{
  //  static TypeCounter ret = -1;
  //  if ( ret != -1 )
  //    return ret;

  //  std::map<TypeCounter, std::function<TypeCounter()>> m;

  //  auto t0 = _type<T0>();
  //  auto t1 = _type<T1>();
  //  auto t2 = _type<T2>();
  //  auto t3 = _type<T3>();
  //  auto t4 = _type<T4>();
  //  m.insert( { t0, [this, t1, t2, t3, t4]()
  //  {
  //    return TypeLm5<T0,T1,T2,T3,T4>( t1, t2, t3, t4 );
  //  } } );
  //  m.insert( { t1, [this, t0, t2, t3, t4]()
  //  {
  //    return TypeLm5<T1,T0,T2,T3,T4>( t0, t2, t3, t4 );
  //  } } );
  //  m.insert( { t2, [this, t0, t1, t3, t4]()
  //  {
  //    return TypeLm5<T2,T0,T1,T3,T4>( t0, t1, t3, t4 );
  //  } } );
  //  m.insert( { t3, [this, t0, t1, t2, t4]()
  //  {
  //    return TypeLm5<T3,T0,T1,T2,T4>( t0, t1, t2, t4 );
  //  } } );
  //  m.insert( { t4, [this, t4, t1, t2, t3]()
  //  {
  //    return TypeLm5<T3,T0,T1,T2,T4>( t4, t1, t2, t3 );
  //  } } );
  //  ret = m.begin()->second();

  //  assert( m.size() != 5 );
  //  return ret;
  //}

  typedef std::vector<TypeCounter> TTypeCounterVector;
  typedef std::function<TypeCounter( int, TTypeCounterVector& )> TFunc;
  typedef std::map<TypeCounter, TFunc> TMap;

  template<typename T>
  void AddTo( TTypeCounterVector& tVec )
  {
    auto t = _type<T>();
    tVec.push_back( t );
  }

  template<typename T0, typename T1, typename ... Args>
  void AddTo( TTypeCounterVector& tVec )
  {
    AddTo<T0>( tVec );
    AddTo<T1, Args...>( tVec );
  }

  template<typename tuples, std::size_t... Is>
  TypeCounter PreFunc( std::index_sequence<Is...> )
  {
    return _type<std::tuple_element<Is, tuples>::type...>();
  }

  template<int INDEX, typename AddingTuple, typename RestTuple>
  void AddToMap( TMap& m )
  {
    typedef std::tuple_element<INDEX, RestTuple>::type TCurrentType;
    //typedef TRemoveIthType<INDEX, RestTuple>::type TSmallTuple;

    //std::tuple<TCurrentType> currentTuple;
    //TSmallTuple smallTuple;
    //AddingTuple addingTuple;

    //// forming new args order
    //auto newAddingTuple = std::tuple_cat( addingTuple, currentTuple );
    //auto wholeTuple = std::tuple_cat( newAddingTuple, smallTuple );

    // unpack tuple
    auto currentTypeID = _type<TCurrentType>();
    m.insert( { currentTypeID, [this]( int index, TTypeCounterVector& sortedVec )
    {
      typedef TRemoveIthType<INDEX, RestTuple>::type TSmallTuple;

      std::tuple<TCurrentType> currentTuple;
      TSmallTuple smallTuple;
      AddingTuple addingTuple;

      // forming new args order
      auto newAddingTuple = std::tuple_cat( addingTuple, currentTuple );
      auto wholeTuple = std::tuple_cat( newAddingTuple, smallTuple );

      constexpr auto smallTypeSize = std::tuple_size<TSmallTuple>::value;
      if constexpr ( smallTypeSize == 0 )
      {
        constexpr auto size = std::tuple_size<decltype( wholeTuple )>::value;
        //auto ret = PreFunc<decltype( wholeTuple )>( std::make_index_sequence<size>() );
        return PreFunc<decltype( wholeTuple )>( std::make_index_sequence<size>() );
      }

      if constexpr ( smallTypeSize > 0 )
      {
        TMap newM;
        AddToMap<0, decltype( newAddingTuple ), TSmallTuple>( newM );

        auto key = sortedVec[index];
        return newM[key]( index + 1, sortedVec );
      }
      return 0;
    } } );

    constexpr auto restSize = std::tuple_size<RestTuple>::value;
    if constexpr ( restSize > 0 && INDEX < restSize - 1 )
      AddToMap<INDEX + 1, AddingTuple, RestTuple>( m );
  }


public:
  template<typename ... Args>
  TypeCounter type()
  {
    static TypeCounter ret = -1;
    if ( ret != -1 )
      return ret;

    TTypeCounterVector tVec;
    AddTo<Args...>( tVec );

    // make a labyrinth
    typedef std::tuple<Args...> TInTuple;
    TMap m;
    AddToMap<0, std::tuple<>, TInTuple>( m );

    // sort
    std::sort( tVec.begin(), tVec.end() );

    // apply sorted args on the labyrinth
    ret = m[tVec[0]]( 1, tVec );
    return ret;
  }
};

typedef TTypeIdentifier<struct GlobalTypeIdentifier> TGlobalTypeIdentifier;
extern DllExport TGlobalTypeIdentifier* GlobalTypeIdentifier();// for use in SingletonManager 
