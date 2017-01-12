/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LockFreeDefH
#define LockFreeDefH

#define BOOST_ATOMIC_OPERATION

#ifdef BOOST_ATOMIC_OPERATION
  #include <boost/atomic/atomic.hpp>
  #define DECLARATION_ATOMIC_BOOL(X)                 boost::atomics::atomic_bool X;
  #define DECLARATION_ATOMIC_BOOL_LOAD(X)            X.load()
  #define DECLARATION_ATOMIC_BOOL_STORE(X,Y)         {bool temp_bool = Y; X.store(temp_bool);}

  #define DECLARATION_ATOMIC_CHAR(X)                 boost::atomics::atomic_char X;
  #define DECLARATION_ATOMIC_CHAR_LOAD(X)            X.load()
  #define DECLARATION_ATOMIC_CHAR_STORE(X,Y)         {char temp_char = Y; X.store(temp_char);}

  #define DECLARATION_ATOMIC_INT(X)                  boost::atomics::atomic_int X;
  #define DECLARATION_ATOMIC_INT_LOAD(X)             X.load()
  #define DECLARATION_ATOMIC_INT_STORE(X,Y)          {int temp_int = Y; X.store(temp_int);}

  #define DECLARATION_ATOMIC_POINTER(X,TYPE)         boost::atomics::atomic<TYPE*> X;
  #define DECLARATION_ATOMIC_POINTER_LOAD(X)         X.load()
  #define DECLARATION_ATOMIC_POINTER_STORE(X,Y,TYPE) {TYPE* ptr_type = Y; X.store(ptr_type);}
#else
  #define VOLATILE_DEF volatile
	#define FLUSH_FROM_CACHE __asm{sfence}//??? возможно дело в высокой оптимизации, а не устаревших данных в ОЗУ

  #define DECLARATION_ATOMIC_BOOL(X)                 VOLATILE_DEF bool X;
  #define DECLARATION_ATOMIC_BOOL_LOAD(X)            X
  #define DECLARATION_ATOMIC_BOOL_STORE(X,Y)         X = Y;FLUSH_FROM_CACHE

  #define DECLARATION_ATOMIC_CHAR(X)                 VOLATILE_DEF char X;
  #define DECLARATION_ATOMIC_CHAR_LOAD(X)            X
  #define DECLARATION_ATOMIC_CHAR_STORE(X,Y)         X = Y;FLUSH_FROM_CACHE

  #define DECLARATION_ATOMIC_INT(X)                  VOLATILE_DEF int X;
  #define DECLARATION_ATOMIC_INT_LOAD(X)             X
  #define DECLARATION_ATOMIC_INT_STORE(X,Y)          X = Y;FLUSH_FROM_CACHE

  #define DECLARATION_ATOMIC_POINTER(X,TYPE)         TYPE* VOLATILE_DEF X;
  #define DECLARATION_ATOMIC_POINTER_LOAD(X)         X
  #define DECLARATION_ATOMIC_POINTER_STORE(X,Y,TYPE) X = Y;FLUSH_FROM_CACHE
#endif

#endif
