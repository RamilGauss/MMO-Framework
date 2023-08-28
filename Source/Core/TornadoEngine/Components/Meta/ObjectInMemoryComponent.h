///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss
//Гудаков Рамиль Сергеевич
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#pragma once
//
//#include <string>
//#include "TypeDef.h"
//
//#include <ECS/include/IComponent.h>
//#include "ObjectInMemory.h"
//
//namespace nsCommonWrapper
//{
//    struct DllExport TObjectInMemoryComponent : nsECSFramework::IComponent
//    {
//        // Not use directly!
//#pragma IGNORE_ATTRIBUTE
//        mutable nsTornadoEngine::TObjectInMemory* value = 0;
//
//        std::string prefabGuid;
//
//        bool IsLess(const IComponent* pOther) const override
//        {
//            return prefabGuid < ((TObjectInMemoryComponent*) pOther)->prefabGuid;
//        }
//
//        bool IsEqual(const IComponent* pOther) const override
//        {
//            return prefabGuid == ((TObjectInMemoryComponent*) pOther)->prefabGuid;
//        }
//    };
//}