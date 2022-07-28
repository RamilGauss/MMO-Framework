/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <functional>
#include "TypeDef.h"

template<typename Type>
class DllExport TStateMachine
{
public:
    using TCallBackFunc = std::function<bool(Type&)>;
private:
    TCallBackFunc* mPtrStateFunc = nullptr;
public:
    TStateMachine(TCallBackFunc* pStateFunc) : mPtrStateFunc(pStateFunc)
    {
    }

    void Work(Type* pThis, TCallBackFunc beforeAction = nullptr, TCallBackFunc afterAction = nullptr)
    {
        while (true) {
            if (beforeAction && beforeAction(*pThis) == false)
                return;
            auto result = mPtrStateFunc[0](*pThis);
            if (result == false)
                return;
            if (afterAction && afterAction(*pThis) == false)
                return;
        }
    }
};
//---------------------------------------------------------------------------------------
