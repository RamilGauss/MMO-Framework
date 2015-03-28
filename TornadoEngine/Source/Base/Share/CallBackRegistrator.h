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

#include <map>
#include <memory.h>

class TCallBackRegistrator
{
protected:
  class TDescFunc
  {
    class TF{};

		char mFunc[20];
		char mObject[20];
  public:
    template<typename F, class A1>  
    void Set(F pFunc, A1 pObject)
    {
      memcpy( &mFunc[0],   &pFunc,   sizeof(F));
      memcpy( &mObject[0], &pObject, sizeof(A1));
    }
    void Call()
    {
      typedef void (TF::*TFunc)();
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(TFunc));
      memcpy( &pT, &mObject, sizeof(TF*));
      (pT->*tf)();
    }
    template <typename T1> void Call(T1 t1)
    {
      typedef void (TF::*TFunc)(T1);
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(TFunc));
      memcpy( &pT, &mObject, sizeof(TF*));
      (pT->*tf)(t1);
    }
    template <typename T1, typename T2> void Call(T1 t1, T2 t2)
    {
      typedef void (TF::*TFunc)(T1,T2);
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(TFunc));
      memcpy( &pT, &mObject, sizeof(TF*));
      (pT->*tf)(t1,t2);
    }
    template <typename T1, typename T2, typename T3> void Call(T1 t1, T2 t2, T3 t3)
    {
      typedef void (TF::*TFunc)(T1,T2,T3);
      TF* pT = NULL;
      TFunc tf;
      memcpy( &tf, &mFunc,   sizeof(TFunc));
      memcpy( &pT, &mObject, sizeof(TF*));
      (pT->*tf)(t1,t2,t3);
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
template < typename T1, typename T2, typename T3>
class TCallBackRegistrator3 : public TCallBackRegistrator
{
public:
  void Notify(T1 t1, T2 t2, T3 t3)
  {
    TMMapPtrPtrIt bit = mMapObjFunc.begin();
    TMMapPtrPtrIt eit = mMapObjFunc.end();
    while(bit!=eit)
    {
      bit->second.Call<T1,T2,T3>(t1,t2,t3);
      bit++;
    }
  }
};
//-------------------------------------------------------------
#endif
