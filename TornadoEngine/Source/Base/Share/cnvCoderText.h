/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef cnvCoderTextH
#define cnvCoderTextH

#include "TypeDef.h"

extern int DllExport convert_utf8_to_windows1251(const char* utf8, char* windows1251, size_t n);

extern int DllExport utf8_to_cp1251(const char* utf8,   char* windows1251, size_t n);
extern int DllExport cp1251_to_utf8(const char* cp1251, char* utf8, size_t n);

#endif
