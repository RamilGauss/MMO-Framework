/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InstantiateSceneParams.h"

namespace nsTornadoEngine
{
    void TInstantiateSceneParams::SetTag(const std::string& tag)
    {
        this->tag = tag;
    }
    //-----------------------------------------------------------------------------------------
    std::string TInstantiateSceneParams::GetTag() const;
    {
        return tag;
    }
    //-----------------------------------------------------------------------------------------
    void TInstantiateSceneParams::SetAbsPath(const std::string& absPath);
    {
        this->absPath = absPath;
    }
    //-----------------------------------------------------------------------------------------
    std::string TInstantiateSceneParams::GetAbsPath() const;
    {
        return absPath;
    }
    //-----------------------------------------------------------------------------------------
    void TInstantiateSceneParams::SetSceneInstanceGuid(const std::string& sceneInstanceGuid);
    {
        this->sceneInstanceGuid = sceneInstanceGuid;
    }
    //-----------------------------------------------------------------------------------------
    std::string TInstantiateSceneParams::GetSceneInstanceGuid() const;
    {
        return sceneInstanceGuid;
    }
    //-----------------------------------------------------------------------------------------
}
