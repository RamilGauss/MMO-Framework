/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ResolverSelf_IP_v4.h"
#include <stdio.h>
#include <libuv/include/uv.h>
#include <string.h>

TResolverSelf_IP_v4::TResolverSelf_IP_v4()
{
  if( mVecDesc == nullptr )
    mVecDesc = SingletonManager()->Get<TVectorDesc>();
  if( mVecDesc->size() == 0 )
    InitVecDesc();
}
//----------------------------------------------------------------------------------
void TResolverSelf_IP_v4::InitVecDesc()
{
  char buf[512];
  uv_interface_address_t *info;
  int count;

  uv_interface_addresses( &info, &count );
  int i = count;
  while( i-- )
  {
    uv_interface_address_t intf = info[i];
    if( intf.address.address4.sin_family == AF_INET &&
      intf.is_internal == 0 )
    {
      TDescHost desc;
      uv_ip4_name( &intf.address.address4, buf, sizeof( buf ) );
      memcpy( &desc.ip, &intf.address.address4.sin_addr, sizeof( desc.ip ) );
      desc.s = buf;
      mVecDesc->push_back( desc );
    }
  }
  uv_free_interface_addresses( info, count );
}
//----------------------------------------------------------------------------------
int TResolverSelf_IP_v4::GetCount()
{
  return mVecDesc->size();
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get( std::string& sIP, int numNetWork )
{
  if( numNetWork >= GetCount() )
    return false;
  sIP = mVecDesc->operator[]( numNetWork ).s;
  return true;
}
//----------------------------------------------------------------------------------
bool TResolverSelf_IP_v4::Get( unsigned int& numIP, int numNetWork )
{
  if( numNetWork >= GetCount() )
    return false;
  numIP = mVecDesc->operator[]( numNetWork ).ip;
  return true;
}
//----------------------------------------------------------------------------------
