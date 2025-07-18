/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <stdio.h>
#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/ContainerTypes.h"
#include "Base/Common/InfoFile.h"
/*
  Загрузка из файла
*/

namespace nsBase::nsCommon
{
    class DllExport TLoadFromFile : public TInfoFile
    {
    public:
        TLoadFromFile(char* path = nullptr);
        virtual ~TLoadFromFile();

        virtual bool ReOpen(char* path, bool append = false);

        unsigned int Size();
        unsigned int Read(void* buffer, unsigned int size, unsigned int offset = 0);
        int ReadSmall(TContainer& c);
    };
}