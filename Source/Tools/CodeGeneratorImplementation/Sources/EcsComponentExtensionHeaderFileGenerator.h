/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EcsComponentExtensionFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TEcsComponentExtensionHeaderFileGenerator : public TEcsComponentExtensionFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::function<void({}::{}* {}, {}::{} {}, std::function<void(void*)> onAfterCreation, bool isNotify)> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_createFunc),
fmt::format("        std::function<void({}::{}* {}, {}::{} {}, void* p, bool isNotify)> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_setFunc),
fmt::format("        std::function<const void*({}::{}* {}, {}::{} {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_viewFunc),
fmt::format("        std::function<bool({}::{}* {}, {}::{} {})> hasFunc;", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_hasFunc),
fmt::format("        std::function<void({}::{}* {}, {}::{} {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_removeFunc),
fmt::format("        std::function<nsECSFramework::TEntityList({}::{}* {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_getByHasFunc),
            "    };",
            "",
fmt::format("    static std::vector<{}> {};", s_Data, s_mRttiVector),
            "",
fmt::format("    static void {}();", s_Init),
            "",
            "public:",
fmt::format("    static bool {}(int {});", s_Has, s_rtti),
fmt::format("    static void {}({}::{}* {},", s_CreateComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {}, std::function<void(void*)> onAfterCreation, bool isNotify);", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static void {}({}::{}* {},", s_SetComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {}, void* p, bool isNotify);", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static const void* {}({}::{}* {},", s_ViewComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static bool {}({}::{}* {},", s_HasComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static void {}({}::{}* {},", s_RemoveComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static nsECSFramework::TEntityList {}({}::{}* {},", s_GetByHas, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        int {});", s_rtti),
        };


    public:
        virtual void Work() override;
    };
}

