/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemConveyorContainer.h"

#include "System.h"
#include "Feature.h"

using namespace nsECSFramework;

void TSystemConveyorContainer::AddSystem(TSystem* pSystem)
{
    mSystems.push_back(pSystem);

    if (pSystem->IsFeature()) {
        mFeatures.push_back(dynamic_cast<TFeature*>(pSystem));
    }

    TryAddToTopSystems(pSystem);
}
//-------------------------------------------------------------------------------------------
void TSystemConveyorContainer::RemoveSystem(TSystem* pSystem)
{
    mSystems.remove(pSystem);

    if (pSystem->IsFeature()) {
        mFeatures.remove(dynamic_cast<TFeature*>(pSystem));
    }

    mTopSystems.remove(pSystem);
}
//-------------------------------------------------------------------------------------------
const std::list<TSystem*>& TSystemConveyorContainer::GetSystems() const
{
    return mSystems;
}
//-------------------------------------------------------------------------------------------
const std::list<TSystem*>& TSystemConveyorContainer::GetTopSystems() const
{
    return mTopSystems;
}
//-------------------------------------------------------------------------------------------
void TSystemConveyorContainer::TryAddToTopSystems(TSystem* pSystem)
{
    for (auto& feature : mFeatures) {
        if (feature->Has(pSystem)) {
            return;
        }
    }

    if (pSystem->IsFeature()) {
        auto pFeature = dynamic_cast<TFeature*>(pSystem);

        auto copyTopSystems = mTopSystems;

        for (auto& topSystem : copyTopSystems) {
            if (pFeature->Has(topSystem)) {
                mTopSystems.remove(topSystem);
            }
        }
    }

    mTopSystems.push_back(pSystem);
}
//-------------------------------------------------------------------------------------------
