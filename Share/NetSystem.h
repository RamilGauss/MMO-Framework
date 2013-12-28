/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef NetSystemH
#define NetSystemH

#include "TypeDef.h"

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)

#else
  #define SOCKET          int
  #define INVALID_SOCKET  -1
  #define SOCKET_ERROR    -1

  #define closesocket     close  
#endif
bool SHARE_EI ns_Init();
void SHARE_EI ns_Done();

SHARE_EI char* ns_getHostIP( const char* name, int numNetWork = 0 ); // получение ip-адреса по имени хоста
SHARE_EI char* ns_getSelfIP(int numNetWork=0);                   // получение ip-адреса

// функция-обертка для inet_addr()
SHARE_EI unsigned long ns_inet_addr( const char* addr );

// функция-обертка для inet_ntoa()
SHARE_EI char* ns_str_addr( unsigned long addr );

// преобразовать имя носта или строку с его ip-адресом в число
// Результат: двоичный код адреса с сетевым расположением байт или INADDR_NONE (-1)
unsigned long ns_HostOrIPtoAddr( const char* hostOrIp );

// Конвертация значения из машинного в сетевой порядок байт
unsigned short SHARE_EI ns_htons( unsigned short value );
unsigned long  ns_htonl( unsigned long value );

// Конвертация значения из сетевого в машинный порядок байт
unsigned short SHARE_EI ns_ntohs( unsigned short value );
unsigned long  ns_ntohl( unsigned long value );

// получить сетевой адрес для сетевого адаптера с заданным именем
bool get_ip_for_net_interface( const char* interface_name, char* out_buf );  

// поиск первого доступного с именем интерфейса ethN
bool get_ip_first_eth(char* out_buf);

#endif
