/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

class A
{
    unsigned int x = 0;
    float y;
    double z;

    std::vector<int> vx;

public:
    virtual void Foo(){}
};

class B : public A
{
public:
    void Foo() override {}
};

#pragma REFLECTION_ATTRIBUTE
#pragma "my comment is here"
template<class TTT, typename XXX, int abc>
class X
{
    TTT t;

    void Func(std::string& s = std::string()) const
    {

    }

    template<TTT ttt = TTT()>
    TTT TemplateFunc(T& s = T()) const
    {
        return t;
    }

    inline static std::vector<std::string> TFunc(T& s = T()) const
    {

    }
};

#include <string>
#include <list>
#include <set>

#include "EntityManager.h"


namespace nsBS
{
#pragma REFLECTION_ATTRIBUTE
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
