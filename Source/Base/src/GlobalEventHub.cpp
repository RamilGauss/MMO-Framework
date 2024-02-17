/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/GlobalEventHub.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/ThreadIndexator.h"

namespace nsBase::nsCommon
{

    class DllExport TGlobalEventHub : public TEventHub
    {
    public:
        void SetSourceLocation(int index, const std::source_location& loc)
        {
            mSrcLocations[index] = loc;
        }
    };

    TGlobalEventHub g_EventHub;

    TEventHub* GetEventHub(const std::source_location loc)
    {
        auto index = SingletonManager()->Get<TThreadIndexator>()->GetThreadIndex();
        g_EventHub.SetSourceLocation(index, loc);

        return &g_EventHub;
    }
}
