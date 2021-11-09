/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <functional>
#include "VectorRise.h"

namespace nsECSFramework
{
    template <typename ElementType, typename IndexType>
    class DllExport TFastAllocatorVector
    {
    protected:
        std::list<IndexType> mFreeIndexes;

        TVectorRise<ElementType*> mElements;
    public:
        std::function<void(IndexType, ElementType*)> onDestroy;

        virtual ~TFastAllocatorVector() {}

        void Init(int elementCount);
        virtual IndexType Create(ElementType* newElement);
        virtual void Destroy(IndexType index);
        void Clear();
        ElementType* GetElement(IndexType index) const;
    };
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    void TFastAllocatorVector<ElementType, IndexType>::Init(int elementCount)
    {
        mElements.mVec.resize(elementCount);
    }
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    IndexType TFastAllocatorVector<ElementType, IndexType>::Create(ElementType* newElement)
    {
        auto index = (IndexType) mElements.mCounter;

        if (mFreeIndexes.size() > 0) {
            index = mFreeIndexes.back();
            mFreeIndexes.pop_back();
            mElements.mVec[index] = newElement;
        } else {
            mElements.Append(newElement);
        }

        return index;
    }
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    void TFastAllocatorVector<ElementType, IndexType>::Destroy(IndexType index)
    {
        auto pElement = GetElement(index);
        if (pElement == nullptr) {
            BL_FIX_BUG();
            return;
        }

        if (onDestroy != nullptr) {
            onDestroy(index, pElement);
        }

        mFreeIndexes.push_back(index);
        mElements.mVec[index] = nullptr;
    }
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    void TFastAllocatorVector<ElementType, IndexType>::Clear()
    {
        auto cnt = mElements.mCounter;
        for (size_t i = 0; i < cnt; i++) {
            auto pElement = mElements.mVec[i];
            if (pElement == nullptr) {
                continue;
            }
            Destroy(i);
        }
    }
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    ElementType* TFastAllocatorVector<ElementType, IndexType>::GetElement(IndexType index) const
    {
        return mElements.mVec[index];
    }
    //----------------------------------------------------------------------------------------------------
}