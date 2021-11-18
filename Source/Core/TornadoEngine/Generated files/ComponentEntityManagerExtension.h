/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_18 08:21:03.977
	
#pragma once

#include <string>
#include <map>
#include <functional>
#include "TypeDef.h"
#include <ECS/include/EntityManager.h>
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TComponentEntityManagerExtension
    {
        struct Data
        {
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, void* p)> setFunc;
            std::function<void*(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> viewFunc;
            std::function<bool(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, void*& p)> getFunc;
            std::function<bool(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> hasFunc;
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> removeFunc;
        };
    
        static std::vector<Data> mRttiVector;
    
        static void Init();
    
    public:
        static void SetComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, void* p, int rtti);
        static void* ViewComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static bool GetComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, void*& p, int rtti);
        static bool HasComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static void RemoveComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
    };
}
