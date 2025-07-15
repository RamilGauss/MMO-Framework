/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>

#include "MMOEngine/SubSystem/DelegateManagerContextSc.h"

namespace nsMMOEngine
{
    class TContainerContextSc;
    class TManagerContextMoreDownClientConnection : public TDelegateManagerContextSc
    {
        typedef std::map<unsigned int, TContainerContextSc*> TMapUintPtr;
        typedef TMapUintPtr::iterator TMapUintPtrIt;

        typedef std::map<unsigned int, unsigned int> TMapUintUint;
        typedef TMapUintUint::iterator TMapUintUintIt;

        TMapUintPtr  mMapKeyContext;
        TMapUintUint mMapKeySession;

    public:
        TManagerContextMoreDownClientConnection(TBase* pBase);
        ~TManagerContextMoreDownClientConnection();

        // навигация
        bool FindSessionByClientKey(unsigned int clientKey, unsigned int& sessionID);
        TContainerContextSc* FindContextByClientKey(unsigned int id);
        // изменение сессии    
        bool SetSessionByClientKey(unsigned int clientKey, unsigned int sessionID);
        // добавление/удаление
        TContainerContextSc* AddContext(unsigned int clientKey, unsigned int sessionID);
        void EntrustContext(unsigned int clientKey, unsigned int sessionID, TContainerContextSc* pContext);
        // удаление
        void DeleteByKey(unsigned int key);
    private:
        void Clear();
    };
}
