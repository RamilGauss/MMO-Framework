/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IOutDumper.h"

class TStringCollectorOutDumper : public nsReflectionCodeGenerator::IOutDumper
{
public:
    void Save(nsReflectionCodeGenerator::TExternalSource& extSrc, const std::string& fileAbsPath) override
    {

    }
};