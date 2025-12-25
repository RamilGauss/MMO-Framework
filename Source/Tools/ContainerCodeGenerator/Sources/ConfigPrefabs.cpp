/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ContainerCodeGenerator/Sources/ConfigPrefabs.h"

nsContainerCodeGenerator::TCoreConfig TConfigPrefabs::MakeCoreDefault() const
{
    nsContainerCodeGenerator::TCoreConfig cfg;
    cfg.nameSpace = "nsTornadoEngine";
    cfg.exportDeclaration = "DllExport";
    nsContainerCodeGenerator::TCodeGenerationResultList componentConfig;
    nsContainerCodeGenerator::TCodeGenerationResultList imGuiWidgetsConfig;

    componentConfig.generated = {
        {"rtti",          {"ComponentRtti",          "TComponentRtti"         }},
        {"json",          {"ComponentJson",          "TComponentJson"         }},
        {"entMng",        {"ComponentEntMng",        "TComponentEntMng"       }},
        {"dynamicCaster", {"ComponentDynamicCaster", "TComponentDynamicCaster"}},
        {"typeFactory",   {"ComponentTypeFactory",   "TComponentTypeFactory"  }}
    };

    imGuiWidgetsConfig.generated = {
        {"rtti",           {"ImGuiWidgetsRtti",          "TImGuiWidgetsRtti"          }},
        {"dynamicCaster",  {"ImGuiWidgetsDynamicCaster", "TImGuiWidgetsDynamicCaster" }},
    };

    cfg.containers = {
        {"componentConfig", componentConfig},
        {"imGuiWidgetsConfig", imGuiWidgetsConfig},
    };

    return cfg;
}

nsContainerCodeGenerator::TProjectConfig TConfigPrefabs::MakeProjectDefault(const std::string& projectNameSpace) const
{
    nsContainerCodeGenerator::TProjectConfig cfg;
    cfg.nameSpace = projectNameSpace;
    cfg.exportDeclaration = "DllExport";
    cfg.mainAggregator = { "ScenePartReflectionAggregatorImpl", "TScenePartReflectionAggregatorImpl"};

    nsContainerCodeGenerator::TCodeGenerationResultList componentConfig;
    nsContainerCodeGenerator::TCodeGenerationResultList handlerConfig;
    nsContainerCodeGenerator::TCodeGenerationResultList ecsSystemConfig;
    nsContainerCodeGenerator::TCodeGenerationResultList systemConfig;

    componentConfig.generated = {
        {"rtti",          {"ComponentRtti",          "TComponentRtti"         }},
        {"json",          {"ComponentJson",          "TComponentJson"         }},
        {"entMng",        {"ComponentEntMng",        "TComponentEntMng"       }},
        {"dynamicCaster", {"ComponentDynamicCaster", "TComponentDynamicCaster"}},
        {"typeFactory",   {"ComponentTypeFactory",   "TComponentTypeFactory"  }}
    };
    handlerConfig.generated = {
        {"typeInfo",      {"HandlerTypeInfo",    "THandlerTypeInfo" }},
        {"rtti",          {"HandlerRtti",        "THandlerRtti"         }},
        {"typeFactory",   {"HandlerTypeFactory", "THandlerTypeFactory"  }}
    };
    ecsSystemConfig.generated = {
        {"rtti",          {"EcsRtti",            "TEcsRtti"         }},
        {"dynamicCaster",   {"EcsDynamicCaster", "TEcsDynamicCaster"  }}
    };
    systemConfig.generated = {
        {"typeFactory",   {"SystemTypeFactory", "TSystemTypeFactory"  }}
    };
    cfg.containers = {
        {"componentConfig", componentConfig},
        {"handlerConfig",   handlerConfig},
        {"ecsSystemConfig", ecsSystemConfig},
        {"systemConfig",    systemConfig},
    };

    nsContainerCodeGenerator::TCodeGenerationResultList componentImpl;
    nsContainerCodeGenerator::TCodeGenerationResultList imGuiWidgetsImpl;
    componentImpl.generated = {
        {"impl",          {"ComponentReflectionAggregatorImpl", "TComponentReflectionAggregatorImpl"}},
        {"rtti",          {"ComponentRttiImpl",                 "TComponentRttiImpl"         }},
        {"json",          {"ComponentJsonImpl",                 "TComponentJsonImpl"         }},
        {"entMng",        {"ComponentEntMngImpl",               "TComponentEntMngImpl"       }},
        {"dynamicCaster", {"ComponentDynamicCasterImpl",        "TComponentDynamicCasterImpl"}},
        {"typeFactory",   {"ComponentTypeFactoryImpl",          "TComponentTypeFactoryImpl"  }}
    };
    imGuiWidgetsImpl.generated = {
        {"impl",          {"ImGuiWidgetsReflectionAggregatorImpl", "TImGuiWidgetsReflectionAggregatorImpl"}},
        {"rtti",          {"ImGuiWidgetsRttiImpl",                 "TImGuiWidgetsRttiImpl"         }},
        {"dynamicCaster", {"ImGuiWidgetsDynamicCasterImpl",        "TImGuiWidgetsDynamicCasterImpl"}}
    };
    cfg.aggregators = {
        {"componentConfig",    componentImpl},
        {"imGuiWidgetsConfig", imGuiWidgetsImpl}
    };

    return cfg;
}

