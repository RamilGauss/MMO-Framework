/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <set>
#include <map>

namespace nsMMOEngine
{
    class TManagerLoginingClientsOnSlave
    {
        typedef std::set<unsigned int> TUintSet;
        typedef std::map<unsigned int, TUintSet> TUintSetUintMap;

        typedef std::map<unsigned int, unsigned int> TUintUintMap;

        TUintUintMap mClientKeySlaveSessionIDMap;

        TUintSetUintMap mSlaveSession_ClientSetMap;
    public:
        void AddSlave(unsigned int slaveSessionID);
        void RemoveSlave(unsigned int slaveSessionID);

        void AddClient(unsigned int slaveSessionID, unsigned int clientKey);
        void RemoveClient(unsigned int clientKey);

        int GetClientCountBySlave(unsigned int slaveSessionID);
    private:
        bool FindSlaveSessionByClientKey(unsigned int clientKey, unsigned int& slaveSessionID);
        void AddClientKeySlaveSession(unsigned int clientKey, unsigned int slaveSessionID);
    };
}
