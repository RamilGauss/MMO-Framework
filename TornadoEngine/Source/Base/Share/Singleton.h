/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SingletonH
#define SingletonH

#include <stddef.h>
//--------------------------------------
#define SINGLETON_H(T) \
protected: \
  T(T& p){} \
  bool operator=(T& p){} \
public: \
  static T* Singleton(); \
  static void Done(); \
private:
//--------------------------------------
#define SINGLETON_CPP(T) \
static T *g_Ptr = NULL; \
T* T::Singleton() \
{ \
  if(g_Ptr==NULL) \
    g_Ptr = new T; \
  return g_Ptr; \
} \
void T::Done() \
{ \
  delete g_Ptr; \
  g_Ptr = NULL; \
}
//--------------------------------------
#endif