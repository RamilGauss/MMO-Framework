/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "RunTimeTypeIndex.h"

TGlobalTypeIdentifier g_GlobalTypeIdentifier;

TGlobalTypeIdentifier* GlobalTypeIdentifier()
{
    return &g_GlobalTypeIdentifier;
}
