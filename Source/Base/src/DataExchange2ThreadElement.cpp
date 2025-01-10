/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/DataExchange2ThreadElement.h"

namespace nsDataExchange2Thread
{
    void TElement::Init()
    {
        ThisPointer = this;
        data = nullptr;
        DECLARATION_ATOMIC_POINTER_STORE(pNext, nullptr, TElement);

        DECLARATION_ATOMIC_CHAR_STORE(needRemove, false);
        DECLARATION_ATOMIC_CHAR_STORE(prepareRemove, false);
        DECLARATION_ATOMIC_CHAR_STORE(dummy, false);
    }
    //----------------------------------------------------------------------
    void TElement::Done(TCallBackRegistrator1<void*>* pCB)
    {
        if (data == nullptr) {
            return;
        }
        if (pCB) {
            pCB->Notify(data);
        } else {
            delete data;// don't touch! pair new/delete
        }
    }
    //----------------------------------------------------------------------
}

