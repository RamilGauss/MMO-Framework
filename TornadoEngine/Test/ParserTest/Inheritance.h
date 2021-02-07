/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

namespace ParentNamespace
{
    class TParent {};
}

namespace Child
{
    class TChild : public ParentNamespace::TParent
    {
    };
}
