/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrepareTreeEntityProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TPrepareTreeEntityProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        //ctx->file.ReOpen((char*)ctx->sceneAbsPath.c_str());
    }
    //-------------------------------------------------------------------------------
    void TPrepareTreeEntityProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        /*
        std::string err;

        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
        int partSize = mScState->mPrepareTreeEntityProgress.GetSteppedRemain();

        for (int i = 0; i < partSize; i++, mScState->mCurrentEntIt++) {

            TEntityMetaContentPtr entityMetaContentPtr = std::make_shared<TEntityMetaContent>();

            bool isRoot = false;

            entityMetaContentPtr->conent = *(mScState->mCurrentEntIt);

            for (auto component : mScState->mCurrentEntIt->components) {
                if (component.typeName == mGuidComponentTypeName) {
                    nsCommonWrapper::TGuidComponent guidComponent;
                    componentReflection->mJson->Deserialize(&guidComponent, component.jsonBody, mGuidComponentRtti, err);
                    entityMetaContentPtr->guid = guidComponent.value;
                }
                if (component.typeName == mParentGuidComponentTypeName) {
                    nsCommonWrapper::TParentGuidComponent parentGuidComponent;
                    componentReflection->mJson->Deserialize(&parentGuidComponent, component.jsonBody, mParentGuidComponentRtti, err);
                    entityMetaContentPtr->parentGuid = parentGuidComponent.value;
                }
                if (component.typeName == mSceneRootComponentTypeName) {
                    isRoot = true;
                }
            }

            if (isRoot) {
                mScState->mRootEntity = entityMetaContentPtr;
            } else {
                auto fit = mScState->mParentGuidEntities.find(entityMetaContentPtr->parentGuid);
                if (fit == mScState->mParentGuidEntities.end()) {
                    mScState->mParentGuidEntities.insert({ entityMetaContentPtr->parentGuid, {} });
                    fit = mScState->mParentGuidEntities.find(entityMetaContentPtr->parentGuid);
                }

                fit->second.insert({ entityMetaContentPtr->guid, entityMetaContentPtr });
            }
        }

        mScState->mPrepareTreeEntityProgress.IncrementValue(partSize);

        if (mScState->mPrepareTreeEntityProgress.IsCompleted()) {
            std::map<std::string, TEntityMetaContentPtr> rootLayer;
            rootLayer.insert({ mScState->mRootEntity->guid, mScState->mRootEntity });

            mScState->mLayers.push_back(rootLayer);
            mScState->mCurrentLayerIndex = 0;
            mScState->mCurrentLayer = --(mScState->mLayers.end());

            mScState->mCurrentLayerEntIt = mScState->mLayers.back().begin();

            mScState->mSubState = TSceneInstanceState::SubState::SORTING_ENTITIES_BY_RANK;
        }
        */
    }
    //-------------------------------------------------------------------------------
    uint32_t TPrepareTreeEntityProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        return 1;
    }
    //-------------------------------------------------------------------------------
    void TPrepareTreeEntityProcess::Finalize(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        //ctx->file.Close();
    }
    //-------------------------------------------------------------------------------
}
