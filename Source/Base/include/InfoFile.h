/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <stdio.h>
#include <string>

#include "TypeDef.h"

class DllExport InfoFile
{
protected:
    std::string sPath;
    FILE* pFile;
public:

    InfoFile();
    virtual ~InfoFile();

    static bool IsExist(char* path);

    virtual bool ReOpen(char* path, bool append = false) = 0;
    virtual bool IsOpen();
    virtual void Close();

    void GetName(std::string& path_name);
    void GetPath(std::string& path_name);
};
