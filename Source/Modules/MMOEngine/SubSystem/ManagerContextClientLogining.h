/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>

#include "Base/Common/BiMap.h"

#include "MMOEngine/SubSystem/DelegateManagerContextSc.h"

namespace nsMMOEngine
{
    class TContainerContextSc;
    class TManagerContextClientLogining : public TDelegateManagerContextSc
    {
        typedef std::map<unsigned int, TContainerContextSc*> TMapUintPtr;
        typedef TMapUintPtr::iterator TMapUintPtrIt;

        using bmUintUint = TBiMap<unsigned int, unsigned int>;

        TMapUintPtr  mMapSessionContext;
        bmUintUint   mMapSessionKey;

    public:
        TManagerContextClientLogining(TBase* pBase);
        ~TManagerContextClientLogining();

        // навигация
        bool FindSessionByClientKey(unsigned int clientKey, unsigned int& sessionID);
        bool FindClientKeyBySession(unsigned int sessionID, unsigned int& clientKey);
        TContainerContextSc* FindContextBySession(unsigned int sessionID);

        // добавление/удаление
        TContainerContextSc* AddContext(unsigned int sessionID);
        bool AddKeyBySession(unsigned int sessionID, unsigned int clientKey);
        // удаление
        void DeleteBySession(unsigned int sessionID);
        // отцепиться
        void UnlinkContextBySession(unsigned int sessionID);
    private:
        void Clear();
    };
}
