/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IDumper.h"

class TStringCollectorDumper : public nsReflectionCodeGenerator::IDumper
{
public:
    void Save(const std::string& absFileName, std::list<std::string>& content) override
    {

    }
};