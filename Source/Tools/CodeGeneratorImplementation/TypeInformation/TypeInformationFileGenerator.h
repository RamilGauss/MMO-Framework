/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IFileGenerator.h"

namespace nsCodeGeneratorImplementation
{
    class TTypeInformationFileGenerator : public nsReflectionCodeGenerator::IFileGenerator
    {
    protected:

        const std::string s_rtti = "rtti";
        const std::string s_typeName = "typeName";
        
        const std::string s_mTypeNameList = "mTypeNameList";
        const std::string s_mRttiList = "mRttiList";
        const std::string s_mNameVector = "mNameVector";
        const std::string s_mNameRttiMap = "mNameRttiMap";

        const std::string s_Init = "Init";
        const std::string s_GetTypeNameList = "GetTypeNameList";
        const std::string s_GetRttiList = "GetRttiList";

        const std::string s_ConvertTypeToName = "ConvertRttiToName";
        const std::string s_ConvertNameToType = "ConvertNameToRtti";
    };
}

