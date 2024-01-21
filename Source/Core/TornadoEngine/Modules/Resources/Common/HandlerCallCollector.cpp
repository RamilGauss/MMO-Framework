/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Common/HandlerCallCollector.h"

using namespace nsTornadoEngine;

void THandlerCallCollector::Add(std::function<void()> func)
{
    mFuncs.push_back(func);
}
//--------------------------------------------------------------------------------------------------------
void THandlerCallCollector::Clear()
{
    mFuncs.clear();
}
//--------------------------------------------------------------------------------------------------------
void THandlerCallCollector::CallAll()
{
    for (auto& func : mFuncs) {
        func();
    }
}
//--------------------------------------------------------------------------------------------------------
