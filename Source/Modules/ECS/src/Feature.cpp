/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Feature.h"

using namespace nsECSFramework;

TFeature::~TFeature()
{ 
    Clear(); 
}
//--------------------------------------------------------------------------------------
bool TFeature::IsFeature() const
{ 
    return true; 
}
//--------------------------------------------------------------------------------------
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
        auto tearDownSystem = dynamic_cast<TTearDownSystem*>(system);
        tearDownSystem->TearDown();
    }

    mSystems.erase(system);
}
//--------------------------------------------------------------------------------------
bool TFeature::Has(TSystem* system) const
{
    return mSystems.find(system) != mSystems.end();
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
}
//--------------------------------------------------------------------------------------
void TFeature::TearDown()
{
    Clear();
}
//--------------------------------------------------------------------------------------
void TFeature::Clear()
{
    auto systemsCopy = mSystems;
    for (auto& system : systemsCopy) {
        Remove(system);
    }
}
//--------------------------------------------------------------------------------------
void TFeature::SetEntMng(TEntityManager* entMng)
{
    TSystem::SetEntMng(entMng);

    InitConveyor();
}
//--------------------------------------------------------------------------------------