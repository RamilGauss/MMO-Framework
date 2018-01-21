/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperEventsH
#define NativeMMOEngineWrapperEventsH

#include "TypeDef.h"

#if defined( WIN32 )
#pragma pack(push, 1)
#endif

DllExport_C 
typedef struct _TBaseEvent
{
  unsigned char type;
}_TBaseEvent;

DllExport_C 
typedef struct _TEventRecv : _TBaseEvent
{
  unsigned int id_session;
  void* data;
  int sizeData;
}_TEventRecv;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
