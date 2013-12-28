/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)

  //необходимо, т.к. #include <winsock2.h> -> #include <pshpack4.h> нарушает выравнивание
  #if !defined(WIN32)
    #define WIN32
  #endif

  #if defined(__BORLANDC__)
    #pragma option push -w
      #pragma warn -8061
      #pragma warn -8060
      #include <winsock2.h>
      #include <Ws2tcpip.h>
    #pragma option pop
  #else
    #include <winsock2.h>
    #include <Ws2tcpip.h>
  #endif

  #define ioctl  ioctlsocket
  #define close  closesocket

  #define TYPE_SO_BROADCAST BOOL

  #define GET_ERROR()         WSAGetLastError()
  #define SET_ERR_NET( err )  errSDK_SET( err )
#else
  #include <sys/socket.h>
  #include <sys/types.h>
  #include <netinet/in.h>
  #include <netdb.h>
  #include <sys/ioctl.h>
  #include <unistd.h>
  #include <errno.h>
  #include <arpa/inet.h>
  #include "ErrorReg.h"
  #include <string.h>
  #include <stdlib.h>
  #include <stdio.h>

  #include <features.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <sys/ioctl.h>
  #include <netinet/in.h>
  #include <net/if.h>
  #include <net/if_arp.h>
  #include <errno.h>
  #include <fcntl.h>
  #include <ctype.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <netdb.h>

  #ifndef SOCKET
    #define SOCKET int
  #endif
  
  #define INVALID_SOCKET  -1
  #define SOCKET_ERROR    -1

  #define TYPE_SO_BROADCAST int


  #define GET_ERROR()         h_errno
  #define SET_ERR_NET( err )  errSTD_SET( err )

#endif

#include "NetSystem.h"
#include "BL_Debug.h"
#include <stdio.h>
//---------------------------------------------------------------------------

static void* errSource;
static bool ns_IsInit;
bool ns_Init()
{
  if( ns_IsInit ) return true;
  ns_IsInit = true;
  //errSource = err_RegisterSource( "—етева€ служба" );
#if defined(TD_WINDOWS)
  WSADATA data;
  #if defined(__BORLANDC__)
  #pragma option push -w
    #pragma warn -8084
  if( WSAStartup( MAKEWORD(2,0), &data ) )
  #pragma option pop
  #else
      if( WSAStartup( MAKEWORD(2,0), &data ) )
  #endif
  {
    BL_FIX_BUG();
    return false;
  }
  else
    if( LOBYTE( data.wVersion ) != 2 )
    {
      BL_FIX_BUG();
      return false;
    }
#endif
  return true;
}
//---------------------------------------------------------------------------
void ns_Done()
{
#if defined(TD_WINDOWS)
  WSACleanup();
#endif
}
//---------------------------------------------------------------------------
/*void ns_getaddrinfo()
{
  BL_Log( "//..........................." );
  BL_Log( "//...  ns_getaddrinfo()  ...." );
  BL_Log( "//..........................." );
  char name[255];
  if( !gethostname( name, sizeof(name) ) )
  {
    struct addrinfo aiHints;
    memset( &aiHints, 0, sizeof(aiHints) );
    aiHints.ai_family = AF_INET;
    aiHints.ai_socktype = SOCK_STREAM;
    aiHints.ai_protocol = IPPROTO_TCP;
    struct addrinfo *aiList = NULL;
    if( !getaddrinfo( "127.0.0.1", NULL, &aiHints, &aiList) != 0 )
    //  if( !getaddrinfo( name, NULL, &aiHints, &aiList) != 0 )
    {
      addrinfo * curAddr = aiList;
      while( curAddr )
      {
        if( curAddr->ai_family == AF_INET )
        {
          sockaddr_in* sai = (sockaddr_in*)(curAddr->ai_addr);
          char* ip = inet_ntoa( sai->sin_addr );
          if( ip )
          {
            BL_Log( "ip:" );
            BL_Log( ip );
          }
        }
        curAddr = curAddr->ai_next;
      }
      freeaddrinfo( aiList );
    }
  }
  BL_Log( "//..........................." );
}*/
//---------------------------------------------------------------------------
//получение ip-адреса по имени хоста
char* ns_getHostIP( const char* name, int numNetWork )
{
	int foundNet = 0;
  hostent* he = gethostbyname( name );
  if( he )
  {
    bool isLocalHost = false;
    char* ip = NULL;
    struct sockaddr ** ppAddr = (sockaddr **)he->h_addr_list;
    int i = 0;
    while( ppAddr[i] )
    {
      ip = inet_ntoa( *(in_addr*)ppAddr[i] );
      if( ip )
      {
        if( strcmp( ip, "127.0.0.1" ) == 0 )
          isLocalHost = true;
        else
					if(numNetWork==foundNet)
						return ip;
					else
						foundNet++;
      }
      else BL_FIX_BUG();
      i++;
    }
    if( isLocalHost )
      return "127.0.0.1";
  }
  return NULL;
}
//---------------------------------------------------------------------------
//получение ip-адреса
char* ns_getSelfIP(int numNetWork)
{
  char name[255];
  if( !gethostname( name, sizeof(name) ) )
  {
    return ns_getHostIP( name, numNetWork );
  }
  return NULL;
}
//---------------------------------------------------------------------------
unsigned long ns_inet_addr( const char* addr )
{
  return inet_addr( addr );
}
//---------------------------------------------------------------------------
char* ns_str_addr( unsigned long addr )
{
  sockaddr_in addrOuter;
  addrOuter.sin_addr.s_addr = addr;
  return inet_ntoa(addrOuter.sin_addr);
}
//---------------------------------------------------------------------------
unsigned long ns_HostOrIPtoAddr( const char* hostOrIp )
{
  // интерпретируем hostOrIp как ip-адрес хоста и преобразуем его в число
  unsigned long ret = hostOrIp ? inet_addr( hostOrIp ) : INADDR_NONE;  
  if( ret == INADDR_NONE )
  {  
    // интерпретируем hostOrIp как им€ хоста и запрашиваем его ip-адрес
    const char* ip_str = ns_getHostIP( hostOrIp );
    if( ip_str )
      ret = inet_addr( ip_str );
  }
  return ret;
}
//---------------------------------------------------------------------------
//  онвертаци€ значени€ из машинного в сетевой пор€док байт
unsigned short ns_htons( unsigned short value )
{
  return htons( value );
}
unsigned long ns_htonl( unsigned long value )
{
  return htonl( value );
}
//---------------------------------------------------------------------------
//  онвертаци€ значени€ из сетевого в машинный пор€док байт
unsigned short ns_ntohs( unsigned short value )
{
  return ntohs( value );
}
unsigned long ns_ntohl( unsigned long value )
{
  return ntohl( value );
}
//-----------------------------------------------------------------------------
// получить сетевой адрес дл€ сетевого адаптера с заданным именем
bool get_ip_for_net_interface( const char* interface_name, char* out_buf )
{
  #if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
  #else
    // получаем сокет дл€ IPv4
    int fd = socket( AF_INET, SOCK_DGRAM, 0 );
    if( fd >= 0 ) 
    {
      // забиваем название интерфейса и название семейства протоколов
      struct ifreq ifr;
      strcpy( ifr.ifr_name, interface_name );
      ifr.ifr_addr.sa_family = AF_INET;
      
      // обращаемс€ к устройству и получаем информацию о сетевом адресе
      if( !ioctl(fd, SIOCGIFADDR, &ifr) ) 
      {
        struct sockaddr_in* addr = (struct sockaddr_in*)(&ifr.ifr_addr);
        sprintf( out_buf, inet_ntoa( addr->sin_addr ) );
      }
    }
  #endif

  return strlen( out_buf ) != 0;
}
//-----------------------------------------------------------------------------
bool get_ip_first_eth(char* out_buf)
{
  char interface_name[100];
  for(int i = 0 ; i < 3/*???*/ ; i++)
  {
    sprintf(interface_name,"eth%d",i);
    bool res = get_ip_for_net_interface((const char*)interface_name,out_buf);
    if(res) return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
