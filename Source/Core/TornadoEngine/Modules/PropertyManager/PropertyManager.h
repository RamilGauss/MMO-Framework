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

#include <TypeDef.h>
#include <TypeName.h>

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
        void GetProperties(const std::string& typeName, std::list<std::string>& properties) const;
    };
    //-------------------------------------------------------------------------------------------
    template <typename Type>
    void TPropertyManager::SetupProperties(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, Type* pObject)
    {
        auto typeRtti = SingletonManager()->Get<TRunTimeTypeIndex<>>()->Type<Type>();
        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;

        std::string typeName = nsBase::TTypeName::Get<Type>();
        std::string componentTypeName;
        mRelativeProperties.componentType.FindByValue(typeName, componentTypeName);

        componentReflection->mEntMng->SetEntityManager(pEntMng);

        auto imGuiWidgetsReflection = nsTornadoEngine::Project()->mScenePartAggregator->mImGuiWidgets;

        int dstRtti;
        componentReflection->mTypeInfo->ConvertNameToType("nsTornadoEngine::IPropertyOf", dstRtti);

        std::list<std::string> downCasters;
        GetDownCasters(componentTypeName, downCasters);

        for (auto& downCaster : downCasters) {

            std::list<std::string> properties;
            GetProperties(downCaster, properties);
            for (auto& componentProperty : properties) {

                std::string typeProperty;
                mRelativeProperties.componentType.FindByKey(componentProperty, typeProperty);

                int srcRtti;
                componentReflection->mTypeInfo->ConvertNameToType(componentProperty, srcRtti);

                void* pC = (void*)componentReflection->mEntMng->ViewComponent(eid, srcRtti);

                auto propertyOf = (nsTornadoEngine::IPropertyOf*)componentReflection->mDynamicCaster->Cast(srcRtti, pC, dstRtti);

                int targetRtti;
                imGuiWidgetsReflection->mTypeInfo->ConvertNameToType(typeProperty, targetRtti);
                auto targetPtr = imGuiWidgetsReflection->mDynamicCaster->Cast(typeRtti, pObject, targetRtti);

                propertyOf->SetOwner(targetPtr);
            }
        }
    }
    //-------------------------------------------------------------------------------------------
}