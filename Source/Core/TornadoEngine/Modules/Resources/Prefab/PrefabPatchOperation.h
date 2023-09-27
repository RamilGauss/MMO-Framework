/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabPatchOperation
    {        
        //AddEntity       -> components
        //RemoveEntity    -> guid
                             
        //AddComponent    -> guid, components
        //UpdateComponent -> guid, components
        //RemoveComponent -> guid, components
        enum Operation
        {
            ADD_ENTITY,
            REMOVE_ENTITY,

            ADD_COMPONENT,
            UPDATE_COMPONENT,
            REMOVE_COMPONENT
        };

        Operation operation;

        std::string guid;
        std::list<TComponentContent> components;
    };
}
