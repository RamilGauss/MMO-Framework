/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <atomic>

#include "DataExchange2ThreadElement.h"

#define DECLARATION_ATOMIC_BOOL(X)                 std::atomic_bool X;
#define DECLARATION_ATOMIC_BOOL_LOAD(X)            X.load()
#define DECLARATION_ATOMIC_BOOL_STORE(X,Y)         {bool temp_bool = Y; X.store(temp_bool);}

#define DECLARATION_ATOMIC_CHAR(X)                 std::atomic_char X;
#define DECLARATION_ATOMIC_CHAR_LOAD(X)            X.load()
#define DECLARATION_ATOMIC_CHAR_STORE(X,Y)         {char temp_char = Y; X.store(temp_char);}

#define DECLARATION_ATOMIC_INT(X)                  std::atomic_int X;
#define DECLARATION_ATOMIC_INT_LOAD(X)             X.load()
#define DECLARATION_ATOMIC_INT_STORE(X,Y)          {int temp_int = Y; X.store(temp_int);}

#define DECLARATION_ATOMIC_POINTER(X,TYPE)         std::atomic<TYPE*> X;
#define DECLARATION_ATOMIC_POINTER_LOAD(X)         X.load()
#define DECLARATION_ATOMIC_POINTER_STORE(X,Y,TYPE) {TYPE* ptr_type = Y; X.store(ptr_type);}
