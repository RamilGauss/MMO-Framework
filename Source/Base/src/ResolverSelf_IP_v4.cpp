/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ResolverSelf_IP_v4.h"

#include <stdio.h>
#include <boost/asio.hpp>

#include "SingletonManager.h"

#ifndef WIN32
#include <sys/types.h>
#include <ifaddrs.h>
#endif


TResolverSelf_IP_v4::TVectorDesc* TResolverSelf_IP_v4::mVecDesc = nullptr;

TResolverSelf_IP_v4::TResolverSelf_IP_v4()
{
    if (mVecDesc == nullptr) {
        mVecDesc = SingletonManager()->Get<TVectorDesc>();
    }
    if (mVecDesc->size() == 0) {
        GetSelfIp4(mVecDesc);
    }
}
//----------------------------------------------------------------------------------
int TResolverSelf_IP_v4::GetCount()
{
    return mVecDesc->size();
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get(std::string& sIP, int numNetWork)
{
    if (numNetWork >= GetCount()) {
        return false;
    }
    sIP = mVecDesc->operator[](numNetWork).s;
    return true;
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get(unsigned int& numIP, int numNetWork)
{
    if (numNetWork >= GetCount()) {
        return false;
    }
    numIP = mVecDesc->operator[](numNetWork).ip;
    return true;
}
//----------------------------------------------------------------------------------
#ifdef WIN32
void TResolverSelf_IP_v4::GetSelfIp4(TVectorDesc* pDescList)
{
    using boost::asio::ip::tcp;

    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(boost::asio::ip::host_name(), "");
    tcp::resolver::iterator iter = resolver.resolve(query);
    tcp::resolver::iterator end; // End marker.
    while (iter != end) {
        tcp::endpoint ep = *iter;
        iter++;
        auto address = ep.address();
        if (address.is_v4() == false) {
            continue;
        }
        TDescHost desc;
        desc.s = ep.address().to_string();
        desc.ip = ep.address().to_v4().to_uint();
        pDescList->push_back(desc);
    }
}
#else
// http://man7.org/linux/man-pages/man3/getifaddrs.3.html
void TResolverSelf_IP_v4::GetSelfIp4(TVectorDesc* pDescList)
{
    struct ifaddrs* ifaddr, * ifa;
    if (getifaddrs(&ifaddr) == -1)
        return;

    char host[NI_MAXHOST];
    for (ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == nullptr)
            continue;

        int family = ifa->ifa_addr->sa_family;
        if (family == AF_INET) {
            struct sockaddr* addr;
            int s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                host, NI_MAXHOST, nullptr, 0, NI_NUMERICHOST);
            if (s != 0)
                continue;
            TDescHost desc;
            desc.s = host;
            desc.ip = ((sockaddr_in*)(ifa->ifa_addr))->sin_addr.s_addr;
            pDescList->push_back(desc);
        }
    }
    freeifaddrs(ifaddr);
    }
#endif
