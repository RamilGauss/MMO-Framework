/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <mutex>

#include "Base/Common/GlobalEventHub.h"

namespace nsBase::nsCommon
{
    class TLockEventHub : public TEventHub
    {
    protected:
        std::mutex mMutex;
    public:
        void Lock()
        {
            mMutex.lock();
        }
        void Unlock()
        {
            mMutex.unlock();
        }
    };

TLockEventHub g_EventHub;

TEventHub* GetEventHub(const std::source_location loc)
{
    g_EventHub.Begin();
    g_EventHub.SetSourceLocation(loc);

    return &g_EventHub;
}

}
