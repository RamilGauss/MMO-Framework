/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PropertyManager.h"
#include <TimeSliceEngine/ProjectConfigContainer.h>
#include <IPropertyOf.h>
#include <TextFile.h>

#include "PropertyManagerConfigs.h"

namespace nsTornadoEngine
{
    void TPropertyManager::Init()
    {
        auto& configs = TPropertyManagerConfigs::GetConfig();

        for (auto& config : configs) {
            mTypeNameDeps.insert({ config.typeName, config });
        }
    }
    //-------------------------------------------------------------------------------------------
    void TPropertyManager::SetupProperties(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, 
        const std::string& typeName, void* pObject)
    {
        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
        componentReflection->mEntMng->SetEntityManager(pEntMng);

        auto imGuiWidgetsReflection = nsTornadoEngine::Project()->mScenePartAggregator->mImGuiWidgets;

        int dstRtti;
        componentReflection->mTypeInfo->ConvertNameToType("nsTornadoEngine::IPropertyOf", dstRtti);

        int windowRtti;
        imGuiWidgetsReflection->mTypeInfo->ConvertNameToType(typeName/*"nsImGuiWidgets::TWindow"*/, windowRtti);

        std::list<std::string> downCasters;
        GetDownCasters(typeName, downCasters);

        for (auto& downCaster : downCasters) {// nsImGuiWidgets::TWidget, ...

            std::list<std::string> properties;
            GetProperties(downCaster, properties);
            for (auto& property : properties) {// nsGuiWrapper::TTitleComponent, ...

                int srcRtti;
                componentReflection->mTypeInfo->ConvertNameToType(property/*"nsGuiWrapper::TTitleComponent"*/, srcRtti);

                void* pC = (void*)componentReflection->mEntMng->ViewComponent(eid, srcRtti);

                auto propertyOf = (nsTornadoEngine::IPropertyOf*)componentReflection->mDynamicCaster->Cast(srcRtti, pC, dstRtti);

                int targetRtti;
                imGuiWidgetsReflection->mTypeInfo->ConvertNameToType(downCaster/*"nsImGuiWidgets::TWidget"*/, targetRtti);
                auto targetPtr = imGuiWidgetsReflection->mDynamicCaster->Cast(windowRtti, pObject, targetRtti);

                propertyOf->SetOwner(targetPtr);
            }
        }
    }
    //-------------------------------------------------------------------------------------------
    void TPropertyManager::GetDownCasters(const std::string& typeName, std::list<std::string>& downCasters) const
    {
        auto fit = mTypeNameDeps.find(typeName);

        if (fit == mTypeNameDeps.end()) {
            return;
        }

        downCasters.push_back(fit->second.typeName);

        for (auto& parentName : fit->second.parentComponentNames) {
            GetDownCasters(parentName, downCasters);
        }
    }
    //-------------------------------------------------------------------------------------------
    void TPropertyManager::GetProperties(const std::string& typeName, std::list<std::string>& properties) const
    {
        auto fit = mTypeNameDeps.find(typeName);

        if (fit == mTypeNameDeps.end()) {
            return;
        }

        properties = fit->second.properties;
    }
    //-------------------------------------------------------------------------------------------
}