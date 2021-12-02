#pragma once

struct FunctionMember
{
    std::function<void(int x)> func0;
    std::function<void(std::function<void(int x)> y, bool f)> func1;
    std::function<const void* (nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> func2;
};
