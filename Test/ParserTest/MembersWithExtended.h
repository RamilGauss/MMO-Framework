/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <memory>

class MWE
{
public:
    std::string str = "asdasd";
    std::shared_ptr<std::string> sp_str;
    int* p = nullptr;
};