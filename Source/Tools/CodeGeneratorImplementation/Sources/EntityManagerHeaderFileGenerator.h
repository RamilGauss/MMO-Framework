/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EntityManagerFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TEntityManagerHeaderFileGenerator : public TEntityManagerFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::function<void*({}::{}* {}, {}::{} {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_createFunc),
fmt::format("        std::function<void({}::{}* {}, {}::{} {}, void* {}, bool withNotify)> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_applyChangesFunc),
fmt::format("        std::function<void({}::{}* {}, {}::{} {}, void* {})> {};",
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_setFunc),
fmt::format("        std::function<void*({}::{}* {}, {}::{} {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_viewFunc),
fmt::format("        std::function<bool({}::{}* {}, {}::{} {}, void*& {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_getFunc),
fmt::format("        std::function<bool({}::{}* {}, {}::{} {})> hasFunc;", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_hasFunc),
fmt::format("        std::function<void({}::{}* {}, {}::{} {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_removeFunc),
            "    };",
            "",
fmt::format("    static std::vector<{}> {};", s_Data, s_mRttiVector),
            "",
fmt::format("    static void {}();", s_Init),
            "",
            "public:",
fmt::format("    static bool {}(int {});", s_Has, s_rtti),
fmt::format("    static void* {}({}::{}* {},", s_CreateComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static void {}({}::{}* {},", s_ApplyChangesComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, void* {}, int {}, bool withNotify);", s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_rtti),
fmt::format("    static void {}({}::{}* {},", s_SetComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, void* {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_rtti),
fmt::format("    static void* {}({}::{}* {},", s_ViewComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static bool {}({}::{}* {},", s_GetComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, void*& {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_rtti),
fmt::format("    static bool {}({}::{}* {},", s_HasComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
fmt::format("    static void {}({}::{}* {},", s_RemoveComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, int {});", s_nsECSFramework, s_TEntityID, s_eid, s_rtti),
        };


    public:
        virtual void Work() override;
    };
}

