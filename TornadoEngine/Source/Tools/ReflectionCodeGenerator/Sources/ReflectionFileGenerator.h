/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IFileGenerator.h"

namespace nsReflectionCodeGenerator
{
    class TReflectionFileGenerator : public IFileGenerator
    {
    protected:
        const std::string s_Init = "Init";
        const std::string s_New = "New";
        const std::string s_typeName = "typeName";

        const std::string s_Data = "Data";
        const std::string s_newFunc = "newFunc";
        const std::string s_mTypeNameMap = "mTypeNameMap";
    protected:
        TReflectionGeneratorConfig* mReflectionConfig;

        TReflectionFileGenerator();
    };
}
