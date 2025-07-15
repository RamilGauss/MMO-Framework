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
    class TManagerContextClient_slave : public TDelegateManagerContextSc
    {
        typedef std::map<unsigned int, TContainerContextSc*> TMapUintPtr;
        typedef TMapUintPtr::iterator TMapUintPtrIt;

        typedef std::map<unsigned int, unsigned int> TMapUintUint;
        typedef TMapUintUint::iterator TMapUintUintIt;

        TMapUintPtr  mMapKeyContext;
        TMapUintUint mMapKeySession;// 

        // содержит отличные от INVALID_HANDLE_SESSION значения
        TMapUintUint mMapSessionKey;// размер может быть меньше чем mMapKeySession

    public:
        TManagerContextClient_slave(TBase* pBase);
        ~TManagerContextClient_slave();

        // навигация
        bool FindSessionByKey(unsigned int id, unsigned int& sessionID);
        bool FindKeyBySession(unsigned int sessionID, unsigned int& id);
        TContainerContextSc* FindContextByKey(unsigned int id);
        TContainerContextSc* FindContextBySession(unsigned int sessionID);

        bool GetSessionByIndex(int index, unsigned int& sessionID);
        int  GetCountSession();

        bool GetFirstKey(unsigned int& id);
        int GetCountKey();

        // добавление/удаление
        TContainerContextSc* AddContextByKey(unsigned int key);

        // изменение
        void AddSessionByKey(unsigned int key, unsigned int sessionID);

        // удаление
        void DeleteByKey(unsigned int key);
    private:
        void Clear();

        bool FindInMapUintUint(TMapUintUint& map, unsigned int key, unsigned int& value);
    };
}
