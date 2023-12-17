/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EcsComponentExtensionFileGenerator.h"

#include <format>
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TEcsComponentExtensionHeaderFileGenerator : public TEcsComponentExtensionFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
std::format("    struct {}", s_Data),
            "    {",
            "        int rtti = 0;",
std::format("        std::function<void({}::{}* {}, {}::{} {}, void* p)> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_setFunc),
std::format("        std::function<const void*({}::{}* {}, {}::{} {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_viewFunc),
std::format("        std::function<bool({}::{}* {}, {}::{} {})> hasFunc;",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_hasFunc),
std::format("        std::function<void({}::{}* {}, {}::{} {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_removeFunc),
std::format("        std::function<nsECSFramework::TEntityList({}::{}* {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_getByHasFunc),
            "    };",
            "",
std::format("    static std::vector<{}> {};", s_Data, s_mRttiVector),
            "",
            "public:",
std::format("    static void {}();", s_Init),
std::format("    static bool {}(int {});", s_Has, s_rtti),
std::format("    static void {}({}::{}* {},", s_SetComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
std::format("        {}::{} {}, int {}, void* p);", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
std::format("    static const void* {}({}::{}* {},", s_ViewComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
std::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
std::format("    static bool {}({}::{}* {},", s_HasComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
std::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
std::format("    static void {}({}::{}* {},", s_RemoveComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
std::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
std::format("    static nsECSFramework::TEntityList {}({}::{}* {},", s_GetByHas, s_nsECSFramework, s_TEntityManager, s_pEntMng),
std::format("        int {});", s_rtti),
        };

    public:
        virtual void Work() override;
    };
}

