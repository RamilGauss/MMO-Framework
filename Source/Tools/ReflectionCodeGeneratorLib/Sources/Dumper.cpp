/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Dumper.h"
#include "Base/Common/SaveToFile.h"

using namespace nsReflectionCodeGenerator;

void TDumper::Save(const std::string& absFileName, std::list<std::string>& content)
{
    nsBase::nsCommon::TSaveToFile stf;
    auto isOpen = stf.ReOpen((char*) absFileName.c_str());
    if (isOpen == false) {
        return;
    }

    for (auto& str : content) {
        stf.WriteF("%s\n", str.c_str());
    }
    stf.Close();
}
    