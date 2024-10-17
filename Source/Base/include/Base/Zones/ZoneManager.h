/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include <boost/asio/io_context.hpp>

#include "Base/Common/TypeDef.h"
#include "Base/Common/StrandHolder.h"

#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class TZone;
    struct IHopProcessContext;
    class DllExport TZoneManager
    {
        std::list<SharedPtrZone> mZones;

        boost::asio::io_context mIoContext;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

    public:
        TZoneManager();
        void AddZone(SharedPtrZone pZone);

        TZone* GetZone(const std::string& zoneName);

        bool Work();

        void MoveContext(IHopProcessContext* pCtx, TZone* from, TZone* to);
    };
}
