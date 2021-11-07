/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "FastAllocatorVector.h"

namespace nsECSFramework
{
    template <typename ElementType, typename IndexType>
    class DllExport TFastAllocatorForeachVector : public TFastAllocatorVector<ElementType, IndexType>
    {
    protected:
        std::list<IndexType> mBusyIndexes;
    public:
        std::function<void(IndexType, ElementType*)> onDestroy;

        IndexType Create(ElementType* newElement) override;
        void Destroy(IndexType index) override;

        const std::list<IndexType>& GetBusyIndexes() const;
    };
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    IndexType TFastAllocatorForeachVector<ElementType, IndexType>::Create(ElementType* newElement)
    {
        auto index = TFastAllocatorVector<ElementType, IndexType>::Create(newElement);
        mBusyIndexes.push_back(index);

        return index;
    }
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    void TFastAllocatorForeachVector<ElementType, IndexType>::Destroy(IndexType index)
    {
        TFastAllocatorVector<ElementType, IndexType>::Destroy(index);
        std::erase_if(mBusyIndexes, [&](IndexType x) { return x == index; });
    }
    //----------------------------------------------------------------------------------------------------
    template <typename ElementType, typename IndexType>
    const std::list<IndexType>& TFastAllocatorForeachVector<ElementType, IndexType>::GetBusyIndexes() const
    {
        return mBusyIndexes;
    }
    //----------------------------------------------------------------------------------------------------
}