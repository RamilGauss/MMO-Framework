/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IFileGenerator.h"

namespace nsReflectionCodeGenerator
{
    class TTypeInformationFileGenerator : public IFileGenerator
    {
    protected:

        const std::string s_typeIdentifier = "typeIdentifier";
        const std::string s_typeName = "typeName";
        
        const std::string s_mTypeNameList = "mTypeNameList";
        const std::string s_mTypeIdentifierList = "mTypeIdentifierList";
        const std::string s_mIdentifierNameMap = "mIdentifierNameMap";
        const std::string s_mNameIdentifierMap = "mNameIdentifierMap";

        const std::string s_Init = "Init";
        const std::string s_GetTypeNameList = "GetTypeNameList";
        const std::string s_GetTypeIdentifierList = "GetTypeIdentifierList";
        const std::string s_ConvertTypeToName = "ConvertTypeToName";
        const std::string s_ConvertNameToType = "ConvertNameToType";
    };
}

