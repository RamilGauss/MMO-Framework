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
    if (system->GetType() == TSystem::Type::INIT) {
        mInitSystems.push_back((TInitSystem*) system);
    }
    if (system->GetType() == TSystem::Type::EXECUTE) {
        mExecuteSystems.push_back((TExecuteSystem*) system);
    }
    return true;
}
void TFeature::Remove(TSystem* system)
{
    if (system->GetType() == TSystem::Type::INIT) {
        mInitSystems.remove((TInitSystem*) system);
    }
    if (system->GetType() == TSystem::Type::EXECUTE) {
        mExecuteSystems.remove((TExecuteSystem*) system);
    }
    mSystems.erase(system);
}
const std::set<TSystem*>* TFeature::GetSystems()
{
    return &mSystems;
}

void TFeature::Execute()
{
    if (mInitSystems.size() > 0) {
        for (auto& system : mInitSystems) {
            system->Init();
        }
        mInitSystems.clear();
    }

    for (auto& system : mExecuteSystems) {
        system->Execute();
    }
}

