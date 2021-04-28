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
            "public:",
fmt::format("    static void {}({}::{}* {},", s_SetComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, void* {}, const std::string& {});", s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_typeName),
fmt::format("    static void* {}({}::{}* {},", s_ViewComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, const std::string& {});", s_nsECSFramework, s_TEntityID, s_eid, s_typeName),
fmt::format("    static bool {}({}::{}* {},", s_GetComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, void*& {}, const std::string& {});", s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_typeName),
fmt::format("    static bool {}({}::{}* {},", s_HasComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, const std::string& {});", s_nsECSFramework, s_TEntityID, s_eid, s_typeName),
fmt::format("    static void {}({}::{}* {},", s_RemoveComponent, s_nsECSFramework, s_TEntityManager, s_pEntMng),
fmt::format("        {}::{} {}, const std::string& {});", s_nsECSFramework, s_TEntityID, s_eid, s_typeName),
            "",
            "private:",
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::string {};", s_typeName),
fmt::format("        std::function<void({}::{}* {}, {}::{} {}, void* {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_setFunc),
fmt::format("        std::function<void* ({}::{}* {}, {}::{} {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_viewFunc),
fmt::format("        std::function<bool({}::{}* {}, {}::{} {}, void*& {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_Ptr, s_getFunc),
fmt::format("        std::function<bool({}::{}* {}, {}::{} {})> hasFunc;", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_hasFunc),
fmt::format("        std::function<void({}::{}* {}, {}::{} {})> {};", 
                s_nsECSFramework, s_TEntityManager, s_pEntMng, s_nsECSFramework, s_TEntityID, s_eid, s_removeFunc),
            "    };",
            "",
fmt::format("    static std::map<std::string, {}> {};", s_Data, s_mTypeNameMap),
            "",
fmt::format("    static void {}();", s_Init),
        };


    public:
        virtual void Work() override;
    };
}

