/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneHashCalculator.h"
#include "Base/Common/MD5.h"

namespace nsTornadoEngine
{
    std::string TSceneHashCalculator::Calculate(const std::list<std::string>& entityGuids)
    {
        std::string accGuid;

        for (auto& guid : entityGuids) {
            accGuid += guid;
        }

        TContainer hash;
        TMD5 md5;

        md5.FastCalc((void*)accGuid.c_str(), accGuid.size(), hash);

        return std::string(hash.GetPtr(), hash.GetSize());
    }
}
