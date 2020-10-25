/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ICodeGenerator.h"

namespace nsReflectionCodeGenerator
{
    class TTypeInformationGenerator : public ICodeGenerator
    {
    public:
        TTypeInformationGenerator() : ICodeGenerator("TypeInformationGenerator")
        {
        }

        virtual void Work() override;
    private:
        void GenerateHeader();
        void GenerateSource();
    };
}


