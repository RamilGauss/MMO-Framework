/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "UdpDevice.h"


#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
  #include <Winsock2.h>
  #include <winsock.h>
  #include <mswsock.h>
#endif
#include "NetSystem.h"
#include <stdio.h>

#ifndef WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#define SOCKET int
#else
#include <winsock2.h>
#include <errno.h>
#define ioctl     ioctlsocket
#endif
#include "common_defs.h"

//-----------------------------------------------------------------------------
UdpDevice::UdpDevice()
{
  ns_Init(); // инициализируем сетевую подсистему (WinSock в винде)
  mSocket = INVALID_SOCKET;
}
//-----------------------------------------------------------------------------
UdpDevice::~UdpDevice() 
{
	close();
}
//-----------------------------------------------------------------------------
/**
 * «акрывает порт и освобождает св€занные с ним ресурсы
 */
void UdpDevice::close()
{
  if( isOpen() )  
  {
#ifdef WIN32
  	closesocket( mSocket );
#else
	  ::close( mSocket );
#endif
	  mSocket = INVALID_SOCKET;
  }
}
//-----------------------------------------------------------------------------
bool UdpDevice::open(void)
{
	// вдруг уже открыто все? закроем, чтоб все проще было
  close();

  bool res = false;
  mSocket = socket( AF_INET, SOCK_DGRAM, 0 );
  if( mSocket != INVALID_SOCKET )
  {
    sockaddr_in localAddr;
    memset( &localAddr, 0, sizeof(localAddr) ); // ???
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = ns_htons( m_Params.m_LocalPort );
    localAddr.sin_addr.s_addr = m_Params.m_LocalHost;

    if(! bind( mSocket, (sockaddr*)&localAddr, sizeof(localAddr) ) == 0 )
      close();
  } 

	return isOpen();
}
//-----------------------------------------------------------------------------
/**
 * ¬озвращает true, если устройство готово дл€ обмена данными
 */
bool UdpDevice::isOpen()
{
	return mSocket != INVALID_SOCKET;
}
//-----------------------------------------------------------------------------
/**
 * „итает данные из последовательного устройства в буфер <buf> размером <size> байт.
 * „тение прерываетс€ если данные не поступили в течении timeout миллисекунд.
 * „тение может быть прервано вызовом BreakRead ƒќ до истечени€ тайм-аута.
 * 
 * ¬озвращает > 0 - размер прочитанных данных
 * RR_TIMEOUT - если данных получено не было
 * RR_ERROR - если произошла ошибка чтени€
 * RR_BREAK - если произошло асинхронное прерывание чтени€
 */
int UdpDevice::read(void* buffer, unsigned long len, unsigned long timeout, unsigned int &ip, unsigned short &port)
{
  unsigned long szMsg;
l_checkQueue:
  if( ioctl( mSocket, FIONREAD, &szMsg ) == -1 )
    return RR_ERROR;

  if( !szMsg )
  {
    fd_set rset;
    struct timeval tv;

    tv.tv_sec = timeout/1000;
    tv.tv_usec = timeout*1000%1000000;

l_repeatRead:
    FD_ZERO(&rset);
    FD_SET(mSocket, &rset);

    int rc = (int)select( mSocket+1, &rset, NULL, NULL, &tv );
    if( !rc ) 
      return RR_TIMEOUT;

    if( rc < 0 )
    {
      if( errno == EINTR ) 
        goto l_repeatRead;
      return RR_ERROR;
    }
    else goto l_checkQueue;
  }   

  if( len > szMsg ) len = szMsg;
	
	sockaddr_in SenderAddr;
	int SenderAddrSize = sizeof(SenderAddr);
	
  int res = recvfrom(	mSocket,(char*)buffer,(int)len,0,(SOCKADDR *)&SenderAddr,&SenderAddrSize);
	
	ip   = SenderAddr.sin_addr.s_addr;
	port = ns_ntohs(SenderAddr.sin_port);
  if( res == -1 ) // == 
    return RR_ERROR;

  return res;
}
//-----------------------------------------------------------------------------
/**
 * ѕередает через устройство size байт из буфера buf. ¬озвращает true в случае успеха
 * и false в противном случае
 */
bool UdpDevice::write(const void* buf, unsigned long size, unsigned int ip, unsigned short port) 
{
  if( !size ) return true;
  // запись в закрытое устройство невозможна
	if( !isOpen() )	return false;
  
  sockaddr_in remoteAddr;
  remoteAddr.sin_family = AF_INET;
  remoteAddr.sin_port = ns_htons( port );
  remoteAddr.sin_addr.s_addr = ip;

  int res = sendto( mSocket, (const char*)buf, (int)size, 0, (struct sockaddr*)&remoteAddr, sizeof(remoteAddr) );

  return (res == (int)size);
}
//-----------------------------------------------------------------------------
bool UdpDevice::SetRecvBuffer(unsigned int size)
{
  bool resSet = false;
#ifdef WIN32
  int res = setsockopt(mSocket, SOL_SOCKET, SO_RCVBUF, (char*)&size, sizeof(int));
  resSet = ( res != SOCKET_ERROR );
#else
#endif
  return resSet;
}
//-----------------------------------------------------------------------------
bool UdpDevice::SetSendBuffer(unsigned int size)
{
  bool resSet = false;
#ifdef WIN32

  int res = setsockopt(mSocket, SOL_SOCKET, SO_SNDBUF, (char*)&size, sizeof(int));
  resSet = ( res != SOCKET_ERROR );

#else
#endif
  return resSet;
}
//-----------------------------------------------------------------------------
unsigned int UdpDevice::GetMaxSizeBufferForSocket()
{
  unsigned int size = 0;
#ifdef WIN32
  int retSize = sizeof(int);
  int resGet = getsockopt(mSocket, SOL_SOCKET, SO_MAX_MSG_SIZE, (char*)&size, &retSize);
  if( resGet != SOCKET_ERROR ) size = 0;
#else
#endif
  return size;
}
//-----------------------------------------------------------------------------
