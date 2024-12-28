/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Common/ObjectManager.h"

#include "Base/Common/HiTimer.h"//###
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"

#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "Modules/Common/Modules.h"
#include "TimeSliceEngine/TimeSliceEngine.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"
#include "Components/Meta/UniverseGuidComponent.h"
#include "ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsTornadoEngine
{
    void TObjectManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
    {
        mEntityManager = entMng;
    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::DestroyObject(const std::string& guid)
    {

    }
    //------------------------------------------------------------------------------------------------------
}
