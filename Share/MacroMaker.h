/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DEF_MACRO_MAKER_H
#define DEF_MACRO_MAKER_H

#include "MacroMaker_Prepare.h"

//------------------------------------------------------------------------------------------------------------
// готово для использования
//------------------------------------------------------------------------------------------------------------
// с параметрами конструктора
#define MACRO_MAKER_H_USE_P(NameInterface, NameRealize, param_for_decl) \
MACRO_MAKER_H(NameInterface, NameRealize, param_for_decl)

#define MACRO_MAKER_H_EXPORT_USE_P(decl, NameInterface, NameRealize, param_for_decl) \
MACRO_MAKER_H_EXPORT(decl, NameInterface, NameRealize, param_for_decl)

#define MACRO_MAKER_CPP_USE_P(NameInterface, NameRealize, ClassRealize, param_for_decl, param_for_def) \
MACRO_MAKER_CPP(NameInterface, NameRealize, ClassRealize, param_for_decl, param_for_def)
//------------------------------------------------------------------------------------------------------------
// без параметров
#define MACRO_MAKER_H_USE(NameInterface, NameRealize)                 MACRO_MAKER_H(NameInterface, NameRealize,)
#define MACRO_MAKER_H_EXPORT_USE(decl, NameInterface, NameRealize)    MACRO_MAKER_H_EXPORT(decl, NameInterface, NameRealize,)
#define MACRO_MAKER_CPP_USE(NameInterface, NameRealize, ClassRealize) MACRO_MAKER_CPP(NameInterface, NameRealize, ClassRealize,,)
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
// если имя реализации совпадает с именем интерфейса
#define MACRO_MAKER_H_USE_P_SAME(NameInterface, param_for_decl) \
MACRO_MAKER_H_USE_P(NameInterface, NameInterface, param_for_decl)

#define MACRO_MAKER_H_EXPORT_USE_P_SAME(decl, NameInterface, param_for_decl) \
MACRO_MAKER_H_EXPORT_USE_P(decl, NameInterface, NameInterface, param_for_decl)

#define MACRO_MAKER_CPP_USE_P_SAME(NameInterface, ClassRealize, param_for_decl, param_for_def) \
MACRO_MAKER_CPP_USE_P(NameInterface, NameInterface, ClassRealize, param_for_decl, param_for_def)
//------------------------------------------------------------------------------------------------------------
// без параметров
#define MACRO_MAKER_H_USE_SAME(NameInterface)                 MACRO_MAKER_H_USE(NameInterface, NameInterface)
#define MACRO_MAKER_H_EXPORT_USE_SAME(decl, NameInterface)    MACRO_MAKER_H_EXPORT_USE(decl, NameInterface, NameInterface)
#define MACRO_MAKER_CPP_USE_SAME(NameInterface, ClassRealize) MACRO_MAKER_CPP_USE(NameInterface, NameInterface, ClassRealize)
//------------------------------------------------------------------------------------------------------------

#endif