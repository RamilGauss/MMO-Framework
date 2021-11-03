/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <functional>

#include "LinkToList.h"
#include "MemoryObjectPool.h"
#include "SingletonManager.h"

namespace nsECSFramework
{
    struct IComponent;
    struct TComponentContainer
    {
        TLinkToList<short> mLinkToList;
        IComponent* p = nullptr;// from memory pool

        template<typename Component>
        inline void Init()
        {
            auto pMP = SingletonManager()->Get<TMemoryObjectPool<Component>>();
            p = pMP->Pop();
            mDoneFunc = [this, pMP] () {
                pMP->Push((Component*) this->p);
            };
        }
        void Done()
        {
            if ( mDoneFunc != nullptr ) {
                mDoneFunc();
            }

            mDoneFunc = nullptr;
            mLinkToList.Erase();
        }

        std::function<void()> mDoneFunc = nullptr;
    };
}