/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IFileGenerator.h"
#include "Parser/Sources/TypeInfo.h"

namespace nsCodeGeneratorImplementation
{
    class TBinaryMarshallerFileGenerator : public nsReflectionCodeGenerator::IFileGenerator
    {
    protected:
        const std::string s_THeader = "THeader";

        const std::string s_GeneralDeallocate = "Deallocate";
        const std::string s_GeneralAllocate = "Allocate";

        const std::string s_SetLimitForCompression = "SetLimitForCompression";
        const std::string s_PrepareForUnpackPopMaster = "PrepareForUnpackPopMaster";
        const std::string s_GetID = "GetID";
        const std::string s_PushIsNotNullptr = "PushIsNotNullptr";
        const std::string s_PopIsNotNullptr = "PopIsNotNullptr";
        const std::string s_Unpack = "Unpack";

        const std::string s_TypeID = "TypeID";

        const std::string s_Serialize = "_Serialize";
        const std::string s_Deserialize = "_Deserialize";
        const std::string s_GetTypeID = "_GetTypeID";
        const std::string s_Deallocate = "_Deallocate";

        const std::string s_PushMaster = "mPushMaster";
        const std::string s_PopMaster = "mPopMaster";

        const std::string s_PushBool = "PushBool";
        const std::string s_PushNum = "PushNum";
        const std::string s_PushStr = "PushStr";

        const std::string s_PushBoolArray = "PushBoolArray";
        const std::string s_PushNumArray = "PushNumArray";
        const std::string s_PushStrArray = "PushStrArray";

        const std::string s_PushSerObjArray = "PushSerObjArray";
        const std::string s_PushSerPtrArray = "PushSerPtrArray";
        const std::string s_PushSerSmartPtrArray = "PushSerSmartPtrArray";

        const std::string s_PushNumNumMap = "PushNumNumMap";
        const std::string s_PushNumStrMap = "PushNumStrMap";
        const std::string s_PushNumBoolMap = "PushNumBoolMap";
        const std::string s_PushStrNumMap = "PushStrNumMap";
        const std::string s_PushStrStrMap = "PushStrStrMap";
        const std::string s_PushStrBoolMap = "PushStrBoolMap";

        const std::string s_PushStrSerObjMap = "PushStrSerObjMap";
        const std::string s_PushStrSerPtrMap = "PushStrSerPtrMap";
        const std::string s_PushStrSerSmartPtrMap = "PushStrSerSmartPtrMap";
        const std::string s_PushNumSerObjMap = "PushNumSerObjMap";
        const std::string s_PushNumSerPtrMap = "PushNumSerPtrMap";
        const std::string s_PushNumSerSmartPtrMap = "PushNumSerSmartPtrMap";

        const std::string s_PopBool = "PopBool";
        const std::string s_PopNum = "PopNum";
        const std::string s_PopStr = "PopStr";

        const std::string s_PopBoolArray = "PopBoolArray";
        const std::string s_PopNumArray = "PopNumArray";
        const std::string s_PopStrArray = "PopStrArray";

        const std::string s_PopNumSet = "PopNumSet";
        const std::string s_PopStrSet = "PopStrSet";

        const std::string s_PopSerObjArray = "PopSerObjArray";
        const std::string s_PopSerPtrArray = "PopSerPtrArray";
        const std::string s_PopSerSmartPtrArray = "PopSerSmartPtrArray";

        const std::string s_PopNumNumMap = "PopNumNumMap";
        const std::string s_PopNumStrMap = "PopNumStrMap";
        const std::string s_PopNumBoolMap = "PopNumBoolMap";
        const std::string s_PopStrNumMap = "PopStrNumMap";
        const std::string s_PopStrStrMap = "PopStrStrMap";
        const std::string s_PopStrBoolMap = "PopStrBoolMap";

        const std::string s_PopStrSerObjMap = "PopStrSerObjMap";
        const std::string s_PopStrSerPtrMap = "PopStrSerPtrMap";
        const std::string s_PopStrSerSmartPtrMap = "PopStrSerSmartPtrMap";
        const std::string s_PopNumSerObjMap = "PopNumSerObjMap";
        const std::string s_PopNumSerPtrMap = "PopNumSerPtrMap";
        const std::string s_PopNumSerSmartPtrMap = "PopNumSerSmartPtrMap";

        std::string MakeEnumName(nsCppParser::TTypeInfo* p);

        std::list<std::string> GetParamListForSerialize(const std::string& namespaceWithType);
        std::list<std::string> GetParamListForDeserialize(const std::string& namespaceWithType);
        std::list<std::string> GetParamListForGetID(const std::string& namespaceWithType);
    };
}

