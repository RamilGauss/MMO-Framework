/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "EntityManager.h"

namespace XXX
{
#pragma REFLECTION_ATTRIBUTE
    class TSimpleClass : nsECSFramework::IComponent
    {
    public:
        enum SimpleEnum
        {
            FIRST, SECOND, ETC
        };
        enum class NumberEnum
        {
            _0, _1, _2
        };
    };

#pragma REFLECTION_ATTRIBUTE
    struct TSimpleComponent : nsECSFramework::IComponent
    {
        struct TInnerStruct
        {
            int asd = 0;
        };

#pragma CHAR
        char c;
#pragma LONG LONG
        long long ll;

        unsigned long long ull;
        int64_t in64;
        uint64_t uin64;

        std::string name;
#pragma MUTABLE
        mutable int x = 0;
#pragma CONST
        const int y = 42;
#pragma STATIC CONST
        static const int z = 0;
#pragma STATIC
        static int w;

        void SimpleFoo()
        {
            {// empty space

            }
        }

        virtual void Virtual()
        {

        }

#pragma METHOD
        bool IsLess(const IComponent* pOther) const override
        {
            return name < ((TSimpleComponent*) pOther)->name;
        }
#pragma METHOD
        bool IsEqual(const IComponent* pOther) const override
        {
            return name == ((TSimpleComponent*) pOther)->name;
        }

        static void SFoo()
        {

        }
        const int CFoo()
        {
            return 42;
        }
    };

    int TSimpleComponent::w = 0;
}
