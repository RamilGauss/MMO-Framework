/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SortingEntityByRankProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TSortingEntityByRankProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        //ctx->file.ReOpen((char*)ctx->sceneAbsPath.c_str());
    }
    //-------------------------------------------------------------------------------
    void TSortingEntityByRankProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        /*
        auto fit = mScState->mParentGuidEntities.find(mScState->mCurrentLayerEntIt->second->guid);
        if (fit != mScState->mParentGuidEntities.end()) {

            if (mScState->mCurrentLayerIndex == mScState->mLayers.size() - 1) {
                mScState->mLayers.push_back(std::map<std::string, TEntityMetaContentPtr>());
            }

            for (auto& guidEntity : fit->second) {
                mScState->mLayers.back().insert({ guidEntity.first, guidEntity.second });
            }
        }

        mScState->mCurrentLayerEntIt++;

        if (mScState->mCurrentLayer->end() == mScState->mCurrentLayerEntIt) {

            if (mScState->mCurrentLayerIndex < mScState->mLayers.size() - 1) {

                mScState->mCurrentLayer = --(mScState->mLayers.end());
                mScState->mCurrentLayerEntIt = mScState->mCurrentLayer->begin();
                mScState->mCurrentLayerIndex++;
            }
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SortingEntitiesByRank()
    {
        int partSize = mScState->mSortingProgress.GetSteppedRemain();

        for (int i = 0; i < partSize; i++) {
            SingleSortingEntitiesByRank();
        }

        mScState->mSortingProgress.IncrementValue(partSize);

        if (mScState->mSortingProgress.IsCompleted()) {

            mScState->mSceneContent.entities.clear();

            std::list<TEntityContent> sortedByRankEntities;
            for (auto& layer : mScState->mLayers) {
                for (auto& entity : layer) {
                    sortedByRankEntities.push_back(entity.second->conent);
                }
            }

            mScState->mSceneContent.entities.splice(mScState->mSceneContent.entities.end(), sortedByRankEntities);

            mScState->mCurrentEntIt = mScState->mSceneContent.entities.begin();

            mScState->mSubState = TSceneInstanceState::SubState::COMPONENT_DESERIALIZING;
        }
    }*/
    }
    //-------------------------------------------------------------------------------
    uint32_t TSortingEntityByRankProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        return 1;
    }
    //-------------------------------------------------------------------------------
    void TSortingEntityByRankProcess::Finalize(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        //ctx->file.Close();
    }
    //-------------------------------------------------------------------------------
}
