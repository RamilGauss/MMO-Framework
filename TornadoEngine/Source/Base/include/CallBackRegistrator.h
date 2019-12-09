/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

//-------------------------------------------------------------
// например:
// Register( &TClass::Method, &object )
// Unregister( &object )
//-------------------------------------------------------------

#include <map>
#include <memory.h>

class TCallBackRegistrator
{
protected:
  class TDescFunc
  {
    class TF
    {
    };

    char mFunc[20];
    char mObject[20];
  public:
    template<typename F, class A1>
    void Set( F pFunc, A1 pObject )
    {
      memcpy( &mFunc[0], &pFunc, sizeof( F ) );
      memcpy( &mObject[0], &pObject, sizeof( A1 ) );
    }

    template <typename ... Args>
    void Call( Args& ... args )
    {
      typedef void ( TF:: * TFunc )( Args ... );
      TF* pT = nullptr;
      TFunc tf;
      memcpy( &tf, &mFunc, sizeof( TFunc ) );
      memcpy( &pT, &mObject, sizeof( TF* ) );
      ( pT->*tf )( args ... );
    }
  };

  typedef std::multimap<void*, TDescFunc> TMMapPtrPtr;
  typedef TMMapPtrPtr::value_type TMMapVT;
  typedef TMMapPtrPtr::iterator TMMapPtrPtrIt;

  TMMapPtrPtr mMapObjFunc;
public:
  template<typename F, class A1> void Register( F pFunc, A1 pObject )
  {
    TDescFunc DF;
    DF.Set( pFunc, pObject );
    mMapObjFunc.insert( TMMapVT( pObject, DF ) );
  }
  template<class A1> void Unregister( A1 pObject )
  {
    mMapObjFunc.erase( pObject );
  }
  int RegisteredCount()
  {
    return (int) mMapObjFunc.size();
  }
  void Clear()
  {
    mMapObjFunc.clear();
  }

};
//-------------------------------------------------------------
class TCallBackRegistrator0 : public TCallBackRegistrator
{
public:
  void Notify()
  {
    for( auto pair : mMapObjFunc )
      pair.second.Call();
  }
};
//-------------------------------------------------------------
template < typename T1 >
class TCallBackRegistrator1 : public TCallBackRegistrator
{
public:
  void Notify( T1 t1 )
  {
    for( auto pair : mMapObjFunc )
      pair.second.Call<T1>( t1 );
  }
};
//-------------------------------------------------------------
template < typename T1, typename T2 >
class TCallBackRegistrator2 : public TCallBackRegistrator
{
public:
  void Notify( T1 t1, T2 t2 )
  {
    for( auto pair : mMapObjFunc )
      pair.second.Call<T1, T2>( t1, t2 );
  }
};
//-------------------------------------------------------------
template < typename T1, typename T2, typename T3>
class TCallBackRegistrator3 : public TCallBackRegistrator
{
public:
  void Notify( T1 t1, T2 t2, T3 t3 )
  {
    for( auto pair : mMapObjFunc )
      pair.second.Call<T1, T2, T3>( t1, t2, t3 );
  }
};
//-------------------------------------------------------------
