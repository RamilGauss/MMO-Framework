/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <vector>

#include "Base/Common/TypeDef.h"

// получение ip-адреса
class DllExport TResolverSelf_IP_v4
{
    struct TDescHost
    {
        std::string s;
        unsigned int ip = 0;
    };

    using TVectorDesc = std::vector<TDescHost>;

    static TVectorDesc* mVecDesc;
public:
    TResolverSelf_IP_v4();

    int GetCount();
    bool Get(std::string& sIP, int numNetWork = 0);
    bool Get(unsigned int& numIP, int numNetWork = 0);
private:
    static void GetSelfIp4(TVectorDesc* pDescList);
};
