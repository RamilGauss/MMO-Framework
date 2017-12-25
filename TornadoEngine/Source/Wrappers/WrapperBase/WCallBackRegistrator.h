/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WCallBackRegistratorH
#define WCallBackRegistratorH

#include <map>
#include <memory.h>

public ref class WCallBackRegistrator
{
public:
  template<typename F, class A1> void Register(F pFunc, A1 pObject);
  template<class A1> void Unregister(A1 pObject);
  int RegisteredCount();
  void Clear();
};
//-------------------------------------------------------------
public ref class WCallBackRegistrator0 : public WCallBackRegistrator
{
public:
  void Notify();
};
//-------------------------------------------------------------
template < typename T1 >
class WCallBackRegistrator1 : public WCallBackRegistrator
{
public:
  void Notify(T1 t1);
};
//-------------------------------------------------------------
template < typename T1, typename T2 >
class WCallBackRegistrator2 : public WCallBackRegistrator
{
public:
  void Notify(T1 t1, T2 t2);
};
//-------------------------------------------------------------
template < typename T1, typename T2, typename T3>
class WCallBackRegistrator3 : public WCallBackRegistrator
{
public:
  void Notify(T1 t1, T2 t2, T3 t3);
};
//-------------------------------------------------------------
#endif
