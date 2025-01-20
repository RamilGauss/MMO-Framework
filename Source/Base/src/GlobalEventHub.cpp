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
    struct TGlobalEventHub : TEventHub
    {
        TGlobalEventHub() : TEventHub(SingletonManager()->Get<TThreadIndexator>())
        {
        }
    };

    TEventHub* GetEventHub(std::string&& source, std::source_location loc)
    {
        auto eventHub = SingletonManager()->Get<TGlobalEventHub>();
        auto index = SingletonManager()->Get<TThreadIndexator>()->GetThreadIndex();
        eventHub->SetSourceLocation(std::move(loc), index);
        eventHub->SetSource(std::move(source), index);
        return eventHub;
    }
}
