/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Scene/UniverseManager.h"
#include "Base/Common/BL_Debug.h"

using namespace nsTornadoEngine;

TUniverseManager::IndexType TUniverseManager::Create(const std::string& guid)
{
    auto foundIndex = GetIndexByGuid(guid);
    if (foundIndex != UNDEFINED_INDEX) {
        return foundIndex;
    }

    auto freeIndex = GetFreeIndex();

    mGuidIndexMap.insert({guid, freeIndex});
    mGuids[freeIndex] = guid;

    IncrementReferenceCounter(freeIndex);

    return freeIndex;
}
//-------------------------------------------------------------------------------------
TUniverseManager::IndexType TUniverseManager::GetIndexByGuid(const std::string& guid)
{
    auto fit = mGuidIndexMap.find(guid);

    if (fit == mGuidIndexMap.end()) {
        return UNDEFINED_INDEX;
    }

    return fit->second;
}
//-------------------------------------------------------------------------------------
const std::string TUniverseManager::GetGuidByIndex(IndexType index)
{
    return mGuids[index];
}
//-------------------------------------------------------------------------------------
void TUniverseManager::Delete(IndexType index)
{
    auto guid = mGuids[index];
    Delete(guid);
}
//-------------------------------------------------------------------------------------
void TUniverseManager::Delete(const std::string& guid)
{
    auto index = GetIndexByGuid(guid);
    if (index == UNDEFINED_INDEX) {
        return;
    }
    DecrementReferenceCounter(index);

    if (GetReferenceCounter(index) == 0) {
        mGuids[index] = UNDEFINED_GUID;
        mGuidIndexMap.erase(guid);
    }
}
//-------------------------------------------------------------------------------------
TUniverseManager::IndexType TUniverseManager::GetFreeIndex()
{
    auto count = mGuids.Size();

    for (int i = 0; i < count; i++) {
        auto& guid = mGuids[i];
        if (guid == UNDEFINED_GUID) {
            return i;
        }
    }


    return count;
}
//-------------------------------------------------------------------------------------
void TUniverseManager::IncrementReferenceCounter(TUniverseManager::IndexType index)
{
    mReferenceCounters[index].counter++;
}
//--------------------------------------------------------------------------------------------------------
void TUniverseManager::DecrementReferenceCounter(TUniverseManager::IndexType index)
{
    mReferenceCounters[index].counter--;

    BL_ASSERT(mReferenceCounters[index].counter >= 0);
}
//--------------------------------------------------------------------------------------------------------
int TUniverseManager::GetReferenceCounter(TUniverseManager::IndexType index)
{
    return mReferenceCounters[index].counter;
}
//--------------------------------------------------------------------------------------------------------
