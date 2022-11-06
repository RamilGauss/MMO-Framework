/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ImGuiSerializeTask.h"

namespace nsTornadoEngine
{
    TImGuiSerializeTask::Mode TImGuiSerializeTask::GetMode() const 
    { 
        return mMode; 
    }
    //-------------------------------------------------------------------------------
    void TImGuiSerializeTask::SetMode(Mode mode) 
    { 
        mMode = mode; 
    }
    //-------------------------------------------------------------------------------
    nsImGuiWidgets::TFrame* TImGuiSerializeTask::GetFrame() 
    { 
        return &mFrame; 
    }
    //-------------------------------------------------------------------------------
    int TImGuiSerializeTask::GetRtti() const 
    { 
        return mRtti; 
    }
    //-------------------------------------------------------------------------------
    void TImGuiSerializeTask::SetRtti(int rtti) 
    { 
        mRtti = rtti; 
    }
    //-------------------------------------------------------------------------------
}