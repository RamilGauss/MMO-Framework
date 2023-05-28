/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_05_28 18:25:37.934
	
#pragma once

#include <string>
#include <map>
#include <functional>
#include "TypeDef.h"
#include "EntityManager.h"
#include "EcsComponentExtensionIncludeList.h"

namespace nsTest
{
    class DllExport TEcsComponentExtensionExtension
    {
        struct Data
        {
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, std::function<void(void*)> onAfterCreation)> createFunc;
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, void* p)> setFunc;
            std::function<const void*(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> viewFunc;
            std::function<bool(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> hasFunc;
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> removeFunc;
            std::function<nsECSFramework::TEntityList(nsECSFramework::TEntityManager* pEntMng)> getByHasFunc;
        };
    
        static std::vector<Data> mRttiVector;
    
        static void Init();
    
    public:
        static bool Has(int rtti);
        static void CreateComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation);
        static void SetComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti, void* p);
        static const void* ViewComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static bool HasComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static void RemoveComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static nsECSFramework::TEntityList GetByHas(nsECSFramework::TEntityManager* pEntMng,
            int rtti);
    };
}
