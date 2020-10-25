/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <type_traits>

#include "TypeDef.h"

#include "IComponent.h"
#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "TypeIdentifier.h"
#include "ColanderVector.h"

namespace nsECSFramework
{
    class DllExport TComplexType
    {
    public:
        TColanderVector<IComponent*> parts;
        std::list<unsigned char> mComponentTypeIdentifierList;

        bool operator < (const TComplexType& other) const
        {
            auto pThisParts = this->parts.Begin();
            auto pOtherParts = other.parts.Begin();

            for ( auto& index : mComponentTypeIdentifierList ) {
                auto pCThis = pThisParts[index];
                auto pCOther = pOtherParts[index];
                if ( pCThis->IsEqual(pCOther) ) {
                    continue;
                }
                return pCThis->IsLess(pCOther);
            }
            return false;
        }

        void Done()
        {
            for ( auto& index : mComponentTypeIdentifierList ) {
                parts[index] = nullptr;
            }
            mComponentTypeIdentifierList.clear();
        }
    };
}