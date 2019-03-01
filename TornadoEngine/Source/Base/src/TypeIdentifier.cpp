/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TypeIdentifier.h"

TGlobalTypeIdentifier g_GlobalTypeIdentifier;

TGlobalTypeIdentifier* GlobalTypeIdentifier()
{
  return &g_GlobalTypeIdentifier;
}
