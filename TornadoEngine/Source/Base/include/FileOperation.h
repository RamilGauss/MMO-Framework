/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "TypeDef.h"

bool DllExport FindAbsPath(char* sRelativePath, char* sAbsPath,int lenAbs);
void DllExport UpPath(char* path);
bool DllExport GetCurrentPath(std::string &sPath);
bool DllExport SetCurrentPath(std::string sPath);
