/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include "Modules/Common/Modules.h"
#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"

#include "SceneInstantiatingThread.h"
#include "Modules/Resources/Scene/SceneInstanceState.h"

#include "Components/Meta/GuidComponent.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Meta/SceneRootComponent.h"
#include "ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsTornadoEngine
{
    TSceneInstantiatingThread::TSceneInstantiatingThread(TSceneInstanceState* pSceneInstanceState)
    {
        mScState = pSceneInstanceState;

        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;

        auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();

        mGuidComponentRtti = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
        mParentGuidComponentRtti = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
        mSceneRootComponentRtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();

        componentReflection->mRtti->ConvertTypeToName(mGuidComponentRtti, mGuidComponentTypeName);
        componentReflection->mRtti->ConvertTypeToName(mParentGuidComponentRtti, mParentGuidComponentTypeName);
        componentReflection->mRtti->ConvertTypeToName(mSceneRootComponentRtti, mSceneRootComponentTypeName);
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::Work()
    {
        switch (mScState->mSubState) {
            case TSceneInstanceState::SubState::INIT:
                Init();
                break;
            case TSceneInstanceState::SubState::FILE_LOADING:
                FileLoading();
                break;
            case TSceneInstanceState::SubState::SCENE_DESERIALIZING:
                SceneDeserializing();
                break;
            case TSceneInstanceState::SubState::PREPARE_TREE_ENTITY:
                PrepareTreeEntity();
                break;
            case TSceneInstanceState::SubState::SORTING_ENTITIES_BY_RANK:
                SortingEntitiesByRank();
                break;
            case TSceneInstanceState::SubState::COMPONENT_DESERIALIZING:
                ComponentDeserialising();
                break;
            default:;
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::Init()
    {
        mScState->mFile.ReOpen((char*)mScState->mAbsPath.c_str());

        auto size = mScState->mFile.Size();

        mScState->mFileProgress.SetTotal(size);
        mScState->mFileContent.reserve(size);

        CalculateRoughProgressValues();

        mScState->mSubState = TSceneInstanceState::SubState::FILE_LOADING;
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::FileLoading()
    {
        int partSize = mScState->mFileProgress.GetSteppedRemain();

        mScState->mFile.Read(mScState->mFileBuffer.GetPtr(), partSize, mScState->mFileProgress.GetValue());

        mScState->mFileContent.append(mScState->mFileBuffer.GetPtr(), partSize);
        mScState->mFileProgress.IncrementValue(partSize);

        if (mScState->mFileProgress.IsCompleted()) {
            mScState->mFile.Close();
            mScState->mSubState = TSceneInstanceState::SubState::SCENE_DESERIALIZING;
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SceneDeserializing()
    {
        std::string err;
        auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&mScState->mSceneContent, mScState->mFileContent, err);

        CalculateAccurateProgressValues();

        mScState->mCurrentEntIt = mScState->mSceneContent.entities.begin();

        //std::list<std::string> entityGuids;

        // Calculate the hash and compare with a hash in the saved file
        //std::string calculatedHash = TSceneHashCalculator::Calculate(entityGuids);

        //if (calculatedHash != mScState->mSceneContent.groupedByRankEntityGuidHash) {
        //    mScState->mSubState = TSceneInstanceState::SubState::PREPARE_TREE_ENTITY;
        //} else {
        //    mScState->mSubState = TSceneInstanceState::SubState::COMPONENT_DESERIALIZING;
        //}
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::PrepareTreeEntity()
    {
        std::string err;

        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
        int partSize = mScState->mPrepareTreeEntityProgress.GetSteppedRemain();

        for (int i = 0; i < partSize; i++, mScState->mCurrentEntIt++) {

            TEntityMetaContentPtr entityMetaContentPtr = std::make_shared<TEntityMetaContent>();

            bool isRoot = false;

            entityMetaContentPtr->content = *(mScState->mCurrentEntIt);

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
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SingleSortingEntitiesByRank()
    {
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
                    sortedByRankEntities.push_back(entity.second->content);
                }
            }

            mScState->mSceneContent.entities.splice(mScState->mSceneContent.entities.end(), sortedByRankEntities);

            mScState->mCurrentEntIt = mScState->mSceneContent.entities.begin();

            mScState->mSubState = TSceneInstanceState::SubState::COMPONENT_DESERIALIZING;
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SingleComponentDeserialising()
    {
        std::string err;

        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
        for (auto& component : mScState->mCurrentEntIt->components) {
            // Add component by rtti
            auto convertResult = componentReflection->mRtti->ConvertNameToType(component.typeName, component.rtti);
            if (convertResult == false) {
                continue;
            }

            component.p = componentReflection->mTypeFactory->New(component.rtti);

            // Deserialize component by rtti and json body
            std::string err;
            componentReflection->mJson->Deserialize(component.p, component.jsonBody, component.rtti, err);
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::ComponentDeserialising()
    {
        int partSize = mScState->mComponentDeserializingProgress.GetSteppedRemain();

        for (int i = 0; i < partSize; i++, mScState->mCurrentEntIt++) {
            SingleComponentDeserialising();
        }

        mScState->mComponentDeserializingProgress.IncrementValue(partSize);

        if (mScState->mComponentDeserializingProgress.IsCompleted()) {
            mScState->mSubState = TSceneInstanceState::SubState::PREPARE_INSTANTIATING;
        }
    }
        //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::CalculateAccurateProgressValues()
    {
        int entityCount = mScState->mSceneContent.entities.size();

        mScState->mPrepareTreeEntityProgress.SetTotal(entityCount);
        mScState->mSortingProgress.SetTotal(entityCount);
        mScState->mEntityProgress.SetTotal(entityCount);
        mScState->mPrefabProgress.SetTotal(mScState->mSceneContent.prefabInstances.size());
        mScState->mComponentDeserializingProgress.SetTotal(entityCount);
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::CalculateRoughProgressValues()
    {
        auto fileSize = mScState->mFileProgress.GetTotal();

        int entityCount = fileSize / ROUGH_ENTITY_SIZE_IN_FILE;
        entityCount = std::min(entityCount, 1);

        mScState->mPrepareTreeEntityProgress.SetTotal(entityCount);
        mScState->mSortingProgress.SetTotal(entityCount);
        mScState->mEntityProgress.SetTotal(entityCount);
        mScState->mPrefabProgress.SetTotal(1);
        mScState->mComponentDeserializingProgress.SetTotal(entityCount);
    }
    //---------------------------------------------------------------------------------------------------
}