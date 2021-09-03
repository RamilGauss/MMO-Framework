/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Feature.h"

using namespace nsECSFramework;

bool TFeature::Add(TSystem* system)
{
    if (mSystems.find(system) != mSystems.end()) {
        return false;
    }
    system->SetEntMng(mEntMng);
    mSystems.insert(system);

    if (system->IsInit()) {
        mInitSystems.push_back(dynamic_cast<TInitSystem*>(system));
    }
    if (system->IsExecute()) {
        mExecuteSystems.push_back(dynamic_cast<TExecuteSystem*>(system));
    }
    return true;
}
//--------------------------------------------------------------------------------------
void TFeature::Remove(TSystem* system)
{
    if (mSystems.find(system) == mSystems.end()) {
        return;
    }

    if (system->IsInit()) {
        mInitSystems.remove(dynamic_cast<TInitSystem*>(system));
    }
    if (system->IsExecute()) {
        mExecuteSystems.remove(dynamic_cast<TExecuteSystem*>(system));
    }
    if (system->IsTearDown()) {
        mTearDownSystems.push_back(dynamic_cast<TTearDownSystem*>(system));
    }
    mSystems.erase(system);
}
//--------------------------------------------------------------------------------------
const std::set<TSystem*>* TFeature::GetSystems()
{
    return &mSystems;
}
//--------------------------------------------------------------------------------------
void TFeature::Execute()
{
    // Initialize
    if (mInitSystems.size() > 0) {
        for (auto& system : mInitSystems) {
            system->Init();
        }
        mInitSystems.clear();
    }

    for (auto& system : mExecuteSystems) {
        system->Execute();
    }

    // Tear down
    if (mTearDownSystems.size() > 0) {
        for (auto& system : mTearDownSystems) {
            system->TearDown();
        }
        mTearDownSystems.clear();
    }
}
//--------------------------------------------------------------------------------------
