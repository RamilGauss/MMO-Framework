/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

class X
{
int x; public   
: int a;  protected : int b; private  : int c;
};

#include <string>
#include <list>
#include <set>

#include "EntityManager.h"


namespace nsBS
{
#pragma REFLECTION_ATTRIBUTE
#pragma "мой комментарий here"
    struct TBaseStruct : nsECSFramework::IComponent
    {
        std::string s = "0123456789";

        TBaseStruct()
        {
        }
        TBaseStruct(std::string ss)
        {
            s = ss;
        }
    };
}
