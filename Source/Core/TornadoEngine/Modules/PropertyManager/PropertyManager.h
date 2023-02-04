/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>

#include "TypeDef.h"
#include <ECS/include/EntityManager.h>
#include <IPropertyOf.h>
#include <TimeSliceEngine/ProjectConfigContainer.h>

#include "Archetype.h"
#include "RelativeProperties.h"

namespace nsTornadoEngine
{
    class DllExport TPropertyManager
    {
        std::unordered_map<std::string, TArchetype> mTypeNameDeps;

        TRelativeProperties mRelativeProperties;

    public:
        void Init();

        template <typename Type>
        void SetupProperties(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, Type* pObject);

    protected:

        void GetDownCasters(const std::string& typeName, std::list<std::string>& downCasters) const;
        void GetProperties(const std::string& typeName, TRelativeProperties& properties) const;
    };
    //-------------------------------------------------------------------------------------------
    template <typename Type>
    void TPropertyManager::SetupProperties(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, Type* pObject)
    {
        //auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
        //componentReflection->mEntMng->SetEntityManager(pEntMng);

        //auto imGuiWidgetsReflection = nsTornadoEngine::Project()->mScenePartAggregator->mImGuiWidgets;

        //auto typeRtti = SingletonManager()->Get<TRunTimeTypeIndex<>>()->Type<T>();
        //std::string typeName;
        //componentReflection->mTypeInfo->ConvertTypeToName(typeRtti, typeName);

        //int dstRtti;
        //componentReflection->mTypeInfo->ConvertNameToType("nsTornadoEngine::IPropertyOf", dstRtti);

        //int windowRtti;
        //imGuiWidgetsReflection->mTypeInfo->ConvertNameToType(typeName, windowRtti);

        //std::list<std::string> downCasters;
        //GetDownCasters(typeName, downCasters);

        //for (auto& downCaster : downCasters) {// nsImGuiWidgets::TWidget, ...

        //    TRelativeProperties properties;
        //    GetProperties(downCaster, properties);
        //    for (auto& property : properties.value) {// nsGuiWrapper::TTitleComponent, ...

        //        int srcRtti;
        //        componentReflection->mTypeInfo->ConvertNameToType(property.first/*"nsGuiWrapper::TTitleComponent"*/, srcRtti);

        //        void* pC = (void*)componentReflection->mEntMng->ViewComponent(eid, srcRtti);

        //        auto propertyOf = (nsTornadoEngine::IPropertyOf*)componentReflection->mDynamicCaster->Cast(srcRtti, pC, dstRtti);

        //        int targetRtti;
        //        imGuiWidgetsReflection->mTypeInfo->ConvertNameToType(property.second/*"nsImGuiWidgets::TWidget"*/, targetRtti);
        //        auto targetPtr = imGuiWidgetsReflection->mDynamicCaster->Cast(windowRtti, pObject, targetRtti);

        //        propertyOf->SetOwner(targetPtr);
        //    }
        //}
    }
    //-------------------------------------------------------------------------------------------
}