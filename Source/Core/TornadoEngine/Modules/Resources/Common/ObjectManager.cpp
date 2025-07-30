/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Base/Common/HiTimer.h"//###
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"

#include "TornadoEngine/GeneratedFiles/TornadoEngineJsonSerializer.h"
#include "TornadoEngine/TimeSliceEngine/TimeSliceEngine.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/Components/Meta/UniverseGuidComponent.h"
#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/ObjectManager.h"

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
