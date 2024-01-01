/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "EntityManager.h"

#pragma REFLECTION_ATTRIBUTE
struct TSimpleComponent : nsECSFramework::IComponent
{
    long long ll;
    unsigned long long ull;
    int64_t in64;
    uint64_t uin64;

    std::string name;

    bool IsLess(const IComponent* pOther) const override
    {
        return name < ((TSimpleComponent*) pOther)->name;
    }
    bool IsEqual(const IComponent* pOther) const override
    {
        return name == ((TSimpleComponent*) pOther)->name;
    }
};


#pragma REFLECTION_ATTRIBUTE
struct TFloat3 : nsECSFramework::IComponent
{
    float x = 1.2345678f;
    float y = 2.2345678f;
    float z = 3.2345678f;
};

#pragma REFLECTION_ATTRIBUTE
struct TFloat4 : nsECSFramework::IComponent
{
    float x = 1.2345678f;
    float y = 2.2345678f;
    float z = 3.2345678f;
    float w = 4.2345678f;
};

#pragma REFLECTION_ATTRIBUTE
class TParamClass : public nsECSFramework::IComponent
{
public:
    int id;
    TFloat3 pos;
    TFloat4 rot;
    TFloat3 vel;
};

