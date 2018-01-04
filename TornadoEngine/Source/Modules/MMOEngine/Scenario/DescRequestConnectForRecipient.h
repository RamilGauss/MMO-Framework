/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MMOEngineDescRequestConnectForRecipientH
#define MMOEngineDescRequestConnectForRecipientH

#include "TypeDef.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  struct DllExport TDescRequestConnectForRecipient
  {
    unsigned int key;
    unsigned int random_num;
    unsigned int id_session;
    TDescRequestConnectForRecipient();
    void Generate();
  }_PACKED;
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
