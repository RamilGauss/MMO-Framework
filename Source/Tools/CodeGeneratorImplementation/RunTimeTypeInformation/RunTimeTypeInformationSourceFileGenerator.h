/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "RunTimeTypeInformationFileGenerator.h"
#include <functional>

namespace nsCodeGeneratorImplementation
{
    class TRunTimeTypeInformationSourceFileGenerator : public TRunTimeTypeInformationFileGenerator
    {
    public:
        virtual void Work() override;

    private:
        void AddImplementations();

        void AddInit();

        void AddMethodDeinitions();
    private:
    };
}
