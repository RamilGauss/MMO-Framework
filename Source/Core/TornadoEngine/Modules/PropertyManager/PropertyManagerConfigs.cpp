/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/PropertyManager/PropertyManagerConfigs.h"

#include "TornadoEngine/Modules/PropertyManager/ImGuiWidgetsArchetypes.h"

namespace nsTornadoEngine
{
    void TPropertyManagerConfigs::GetArchetypes(std::list<TArchetype>& archetypes)
    {
        TImGuiWidgetsArchetypes::GetArchetypes(archetypes);
    }

    void TPropertyManagerConfigs::GetRelativeProperties(TRelativeProperties& relativeProperties)
    {
        TImGuiWidgetsArchetypes::GetRelativeProperties(relativeProperties);
    }
}
