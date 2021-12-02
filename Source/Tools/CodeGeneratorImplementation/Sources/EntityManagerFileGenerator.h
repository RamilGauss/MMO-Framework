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
    class TEntityManagerFileGenerator : public nsReflectionCodeGenerator::IFileGenerator
    {
    protected:
        const std::string s_Has = "Has";

        const std::string s_CreateComponent = "CreateComponent";
        const std::string s_SetComponent = "SetComponent";
        const std::string s_ViewComponent = "ViewComponent";
        const std::string s_HasComponent = "HasComponent";
        const std::string s_RemoveComponent = "RemoveComponent";

        const std::string s_Init = "Init";

        const std::string s_nsECSFramework = "nsECSFramework";
        const std::string s_TEntityManager = "TEntityManager";
        const std::string s_pEntMng = "pEntMng";
        const std::string s_TEntityID = "TEntityID";
        const std::string s_eid = "eid";
        const std::string s_rtti = "rtti";
        const std::string s_Ptr = "p";

        const std::string s_Data = "Data";

        const std::string s_createFunc = "createFunc";
        const std::string s_setFunc = "setFunc";
        const std::string s_viewFunc = "viewFunc";
        const std::string s_hasFunc = "hasFunc";
        const std::string s_removeFunc = "removeFunc";

        const std::string s_mRttiVector = "mRttiVector";

        const std::string s_EntityManagerHeaderPath = "entityManagerHeaderPath";

    protected:
        TEntityManagerFileGenerator();
    };
}

