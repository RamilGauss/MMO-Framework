/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/JsonPushMaster.h"

TJsonPushMaster::Document::AllocatorType& TJsonPushMaster::Allocator()
{
    static Document mDocument;

    return mDocument.GetAllocator();
}
