/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "OutDumper.h"
#include "SaveToFile.h"
#include "JsonSerializer.h"

using namespace nsReflectionCodeGenerator;

void TOutDumper::Save(TExternalSource& extSrc, const std::string& fileAbsPath)
{
    TSaveToFile stf;
    auto isOpen = stf.ReOpen((char*) fileAbsPath.c_str());
    if (isOpen == false) {
        return;
    }

    std::string serializedExtSrc;

    nsJson::TJsonSerializer::Serialize(&extSrc, serializedExtSrc);

    stf.WriteF("%s\n", serializedExtSrc.c_str());
    stf.Close();
}
