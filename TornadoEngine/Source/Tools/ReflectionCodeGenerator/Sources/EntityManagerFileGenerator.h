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
    class TEntityManagerFileGenerator : public IFileGenerator
    {
    protected:
        const std::string s_SetComponent = "SetComponent";
        const std::string s_ViewComponent = "ViewComponent";
        const std::string s_GetComponent = "GetComponent";
        const std::string s_HasComponent = "HasComponent";
        const std::string s_RemoveComponent = "RemoveComponent";
        const std::string s_Init = "Init";

        const std::string s_nsECSFramework = "nsECSFramework";
        const std::string s_TEntityManager = "TEntityManager";
        const std::string s_pEntMng = "pEntMng";
        const std::string s_TEntityID = "TEntityID";
        const std::string s_eid = "eid";
        const std::string s_typeName = "typeName";
        const std::string s_Ptr = "p";

        const std::string s_Data = "Data";
        const std::string s_setFunc = "setFunc";
        const std::string s_viewFunc = "viewFunc";
        const std::string s_getFunc = "getFunc";
        const std::string s_hasFunc = "hasFunc";
        const std::string s_removeFunc = "removeFunc";
        const std::string s_mTypeNameMap = "mTypeNameMap";

    protected:
        TEntityManagerGeneratorConfig* mEntityManagerConfig;

        TEntityManagerFileGenerator();
    };
}

