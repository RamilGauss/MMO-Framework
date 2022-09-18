/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

class A
{
public:
    mutable int pub;
protected:
    mutable int pro;
private:
    mutable int pri = 0;
};

struct B
{
public:
    mutable int pub;
protected:
    mutable int pro;
private:
    mutable int pri = 0;
};