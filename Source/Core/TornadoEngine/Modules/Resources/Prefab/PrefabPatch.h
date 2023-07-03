/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <unordered_map>

#include "TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabPatchOperation
    {
        enum Operation
        {
            ADD_ENTITY,
            REMOVE_ENTITY,

            ADD_COMPONENT,
            UPDATE_COMPONENT,
            REMOVE_COMPONENT
        };

        Operation operation;

        TEntityContent value;

        std::string guid;
        TComponentContent value;

        //AddEntity       -> TEntityContent
        //RemoveEntity    -> guid
                             
        //AddComponent    -> guid, TComponentContent
        //UpdateComponent -> guid, TComponentContent
        //RemoveComponent -> guid, TComponentContent
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabPatch
    {   
        std::unordered_map<TPrefabPatchOperation::Operation, TPrefabPatchOperation> operations;
    };
}
