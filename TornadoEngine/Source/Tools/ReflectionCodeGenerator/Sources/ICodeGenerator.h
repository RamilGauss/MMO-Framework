/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IGenerator.h"

namespace nsReflectionCodeGenerator
{
    class ICodeGenerator : public IGenerator
    {
        std::string mName;
    protected:
        TPairList* mPairList;
    public:
        ICodeGenerator(std::string name);

        // abs path file - list parts of file
        void Init(TPairList& result);
        virtual void Work() = 0;
    protected:
        std::string GeneratedFileFullPath(std::string fileNameWithExt);
    };
}