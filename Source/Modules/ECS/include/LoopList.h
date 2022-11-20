/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "TypeDef.h"

namespace nsECSFramework
{
    template<typename Type>
    class DllExport TLoopList
    {
    public:
        using List = std::list<Type>;
        using Iterator = typename List::iterator;
    private:
        List* mList;
        Iterator mCurrentIt;
    public:
        TLoopList(List* pL)
        {
            Init(pL);
        }
        void Init(List* pL)
        {
            mList = pL;
            Reset();
        }
        bool Next(Type& t)
        {
            if (mCurrentIt == mList->end())
                return false;
            t = *mCurrentIt;
            mCurrentIt++;
            return true;
        }
        void Reset()
        {
            mCurrentIt = mList->begin();
        }

        TLoopList<Type>& operator = (const TLoopList<Type>& other)
        {
            mList = other.mList;
            mCurrentIt = other.mCurrentIt;
            return *this;
        }
    };
}