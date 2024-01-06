/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "HandlerMMO.h"

class THandlerMMO_Client : public THandlerMMO
{
public:
    THandlerMMO_Client(nsMMOEngine::TBase* pBase);
protected:
    void HandleFromMMOEngine(nsEvent::TEvent* pEvent) override;
};
