/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/impl/host_name.ipp>
#include "ResolverSelf_IP_v4.h"

int TResolverSelf_IP_v4::GetCount()
{
  int count = 0;
  boost::asio::io_service io_service;

  boost::asio::ip::tcp::resolver resolver(io_service);
  boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(),"");
  boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);

  while(it!=boost::asio::ip::tcp::resolver::iterator())
  {
    boost::asio::ip::address addr = (it++)->endpoint().address();
    if(addr.is_v4())
      count++;
  }
  return count;
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get(std::string& sIP, int numNetWork )
{
  int count = 0;
  boost::asio::io_service io_service;

  boost::asio::ip::tcp::resolver resolver(io_service);
  boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(),"");
  boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);

  while(it!=boost::asio::ip::tcp::resolver::iterator())
  {
    boost::asio::ip::address addr = (it++)->endpoint().address();
    if(addr.is_v4())
    {
      if( numNetWork==count )
      {
        sIP = addr.to_string();
        return true;
      }
      count++;
    }
  }
  return false;
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get(unsigned int& numIP, int numNetWork )
{
  int count = 0;
  boost::asio::io_service io_service;

  boost::asio::ip::tcp::resolver resolver(io_service);
  boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(),"");
  boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);

  while(it!=boost::asio::ip::tcp::resolver::iterator())
  {
    boost::asio::ip::address addr = (it++)->endpoint().address();
    if(addr.is_v4())
    {
      if( numNetWork==count )
      {
        numIP = boost::asio::ip::address_v4::from_string(addr.to_string()).to_ulong();
        return true;
      }
      count++;
    }
  }
  return false;
}
//----------------------------------------------------------------------------------
