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

#include "Base/Common/TypeDef.h"
#include "Base/Common/TypeName.h"

#include "ECS/Include/EntityManager.h"

#include "TornadoEngine/Share/IPropertyOf.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"

#include "TornadoEngine/Modules/PropertyManager/Archetype.h"
#include "TornadoEngine/Modules/PropertyManager/RelativeProperties.h"

#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

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

        auto imGuiWidgetsReflection = nsTornadoEngine::Project()->mScenePartAggregator->mImGuiWidgets;

        auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
        auto propertyOfRtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();

        std::list<std::string> downCasters;
        GetDownCasters(componentTypeName, downCasters);

        for (auto& downCaster : downCasters) {

            std::list<std::string> properties;
            GetProperties(downCaster, properties);
            for (auto& componentProperty : properties) {

                std::string typeProperty;
                mRelativeProperties.componentType.FindByKey(componentProperty, typeProperty);

                int srcRtti;
                componentReflection->mRtti->ConvertNameToType(componentProperty, srcRtti);

                void* pC = (void*)componentReflection->mEntMng->ViewComponent(eid, srcRtti);

                auto propertyOf = (nsTornadoEngine::IPropertyOf*)componentReflection->mDynamicCaster->Cast(srcRtti, pC, propertyOfRtti);

                int targetRtti;
                imGuiWidgetsReflection->mRtti->ConvertNameToType(typeProperty, targetRtti);
                auto targetPtr = imGuiWidgetsReflection->mDynamicCaster->Cast(typeRtti, (void*)pObject, targetRtti);

                propertyOf->SetOwner(targetPtr);
            }
        }
    }
    //-------------------------------------------------------------------------------------------
}
