/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ResolverSelf_IP_v4.h"
// boost, ты действительно кросс-платформенный? Почему под Linux не работаешь?
#ifdef WIN32
  #include <boost/asio/ip/tcp.hpp>
  #include <boost/asio/ip/impl/host_name.ipp>
#else
  #include <arpa/inet.h>
  #include <sys/socket.h>
  #include <netdb.h>
  #include <ifaddrs.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
#endif

TResolverSelf_IP_v4::TResolverSelf_IP_v4()
{
#ifdef WIN32
  boost::asio::io_service io_service;

  boost::asio::ip::tcp::resolver resolver(io_service);
  boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(),"");
  boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);

  while(it!=boost::asio::ip::tcp::resolver::iterator())
  {
    TDescHost desc;
    boost::asio::ip::address addr = (it++)->endpoint().address();
    if(addr.is_v4())
    {
      desc.ip = boost::asio::ip::address_v4::from_string(addr.to_string()).to_ulong();
      desc.s  = addr.to_string();
      mVecDesc.push_back(desc);
    }
  }
#else
  struct ifaddrs *ifaddr;
  if( getifaddrs(&ifaddr) == -1 )
    return;

  TVectorDesc vecTemp;
  for( struct ifaddrs* ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next )
  {
    if( ifa->ifa_addr==NULL )
      continue;

    if( ifa->ifa_addr->sa_family==AF_INET ) 
    {
      TDescHost desc;
      struct sockaddr_in* pSockaddr_in = (struct sockaddr_in*)ifa->ifa_addr;
      desc.ip = pSockaddr_in->sin_addr.s_addr;
      
      char host[NI_MAXHOST];
      int s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      if( s!=0 )
        continue;
      desc.s = host;
      vecTemp.push_back(desc);
    } 
  }
  freeifaddrs(ifaddr);
  // порядок вывода в ifconfig обратный
  for( int i = vecTemp.size() - 1 ; i >= 0 ; i-- )
    mVecDesc.push_back(vecTemp[i]);
#endif
}
//----------------------------------------------------------------------------------
int TResolverSelf_IP_v4::GetCount()
{
  return mVecDesc.size();
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get(std::string& sIP, int numNetWork )
{
  if( numNetWork>=GetCount() )
    return false;
  sIP = mVecDesc[numNetWork].s;
  return true;
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get(unsigned int& numIP, int numNetWork )
{
  if( numNetWork>=GetCount() )
    return false;
  numIP = mVecDesc[numNetWork].ip;
  return true;
}
//----------------------------------------------------------------------------------
