/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

template <typename T>
class A
{

};

class B : public A<int>
{

};

class C
{
public: 
    A<int> a;
};