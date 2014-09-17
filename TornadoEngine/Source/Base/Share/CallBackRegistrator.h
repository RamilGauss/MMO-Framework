/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CallBackRegistratorH
#define CallBackRegistratorH

#include <boost/signals2/signal.hpp>
//-------------------------------------------------------------
// например:
// Register(&TClass::Method, &object)
// Unregister(&object)
//-------------------------------------------------------------
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
#endif
