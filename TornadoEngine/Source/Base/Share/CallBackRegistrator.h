/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CallBackRegistratorH
#define CallBackRegistratorH

//-------------------------------------------------------------
// например:
// Register(&TClass::Method, &object)
// Unregister(&object)
//-------------------------------------------------------------

//#define USE_CALLBACK_BOOST_IMPL
#ifdef USE_CALLBACK_BOOST_IMPL

#include <boost/signals2/signal.hpp>

class TCallBackRegistrator0
{
  boost::signals2::signal<void (void)> sig;
public:
  template<typename F, class A1>  void Register(F pFunc, A1 pObject)
  {sig.connect(boost::bind(pFunc, pObject));}

  template<class A1>  void Unregister(A1 pObject)
  {sig.disconnect(pObject);}

  void Notify(){sig();}
};
//-------------------------------------------------------------
template < typename T1 >
class TCallBackRegistrator1
{
  boost::signals2::signal<void (T1)> sig;
public:
  template<typename F, class A1>  void Register(F pFunc, A1 pObject)
  {sig.connect(boost::bind(pFunc, pObject, _1));}
  
  template<class A1>  void Unregister(A1 pObject)
  {sig.disconnect(pObject);}
  
  void Notify(T1 t1){sig(t1);}
};
//-------------------------------------------------------------
template < typename T1, typename T2 >
class TCallBackRegistrator2
{
  boost::signals2::signal<void (T1, T2)> sig;
public:
  template<typename F, class A1>  void Register(F pFunc, A1 pObject)
  {sig.connect(boost::bind(pFunc, pObject, _1, _2));}

  template<class A1>  void Unregister(A1 pObject)
  {sig.disconnect(pObject);}

  void Notify(T1 t1, T2 t2){sig(t1,t2);}
};
//-------------------------------------------------------------
#else// STL_IMPL
#include <map>

class TCallBackRegistrator
{
protected:
  class TDescFunc
  {
    class TF{};

    unsigned int mFunc;
    unsigned int mObject;
  public:
    template<typename F, class A1>  
    void Set(F pFunc, A1 pObject)
    {
      memcpy( &mFunc,   &pFunc,   sizeof(F));
      memcpy( &mObject, &pObject, sizeof(A1));
    }
    void Call()
    {
      typedef void (TF::*TFunc)();
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(mFunc));
      memcpy( &pT, &mObject, sizeof(mObject));
      (pT->*tf)();
    }
    template <typename T1> void Call(T1 t1)
    {
      typedef void (TF::*TFunc)(T1);
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(mFunc));
      memcpy( &pT, &mObject, sizeof(mObject));
      (pT->*tf)(t1);
    }
    template <typename T1, typename T2> void Call(T1 t1, T2 t2)
    {
      typedef void (TF::*TFunc)(T1,T2);
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(mFunc));
      memcpy( &pT, &mObject, sizeof(mObject));
      (pT->*tf)(t1,t2);
    }
  };

  typedef std::multimap<void*,TDescFunc> TMMapPtrPtr;
  typedef TMMapPtrPtr::value_type TMMapVT;
  typedef TMMapPtrPtr::iterator TMMapPtrPtrIt;

  TMMapPtrPtr mMapObjFunc;
public:
  template<typename F, class A1> void Register(F pFunc, A1 pObject)
  {
    TDescFunc DF;
    DF.Set(pFunc, pObject);
    mMapObjFunc.insert(TMMapVT(pObject, DF));
  }
  template<class A1> void Unregister(A1 pObject)
  {
    mMapObjFunc.erase(pObject);
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
    TMMapPtrPtrIt bit = mMapObjFunc.begin();
    TMMapPtrPtrIt eit = mMapObjFunc.end();
    while(bit!=eit)
    {
      bit->second.Call();
      bit++;
    }
  }
};
//-------------------------------------------------------------
template < typename T1 >
class TCallBackRegistrator1 : public TCallBackRegistrator
{
public:
  void Notify(T1 t1)
  {
    TMMapPtrPtrIt bit = mMapObjFunc.begin();
    TMMapPtrPtrIt eit = mMapObjFunc.end();
    while(bit!=eit)
    {
      bit->second.Call<T1>(t1);
      bit++;
    }
  }
};
//-------------------------------------------------------------
template < typename T1, typename T2 >
class TCallBackRegistrator2 : public TCallBackRegistrator
{
public:
  void Notify(T1 t1, T2 t2)
  {
    TMMapPtrPtrIt bit = mMapObjFunc.begin();
    TMMapPtrPtrIt eit = mMapObjFunc.end();
    while(bit!=eit)
    {
      bit->second.Call<T1,T2>(t1,t2);
      bit++;
    }
  }
};
//-------------------------------------------------------------
#endif
#endif
