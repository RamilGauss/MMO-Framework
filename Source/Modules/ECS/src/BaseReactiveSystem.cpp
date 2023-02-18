/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
    void TBaseReactiveSystem::SetEnableReactive(bool value)
    {
        mIsEnableReactive = value;
    }
    //---------------------------------------------------------------------------------------------------
    bool TBaseReactiveSystem::IsEnableReactive() const
    {
        return mIsEnableReactive;
    }
    //---------------------------------------------------------------------------------------------------
    bool TBaseReactiveSystem::IsInstantReactive() const
    {
        return true;
    }
    //---------------------------------------------------------------------------------------------------
}
