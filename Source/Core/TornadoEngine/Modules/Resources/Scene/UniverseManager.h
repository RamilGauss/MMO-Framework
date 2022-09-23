/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <map>
#include <vector>

#include "TypeDef.h"
#include "ColanderVector.h"

namespace nsTornadoEngine
{
    class DllExport TUniverseManager
    {
    public:
        using IndexType = int;

        static const IndexType UNDEFINED_INDEX = std::numeric_limits<IndexType>::max();

        inline static const std::string UNDEFINED_GUID = "";

        // CRUD
        IndexType Create(const std::string& guid);

        IndexType GetIndexByGuid(const std::string& guid);
        const std::string GetGuidByIndex(IndexType index);

        void Delete(const std::string& guid);
        void Delete(IndexType index);

    private:
        using StrIndexTypeMap = std::map<std::string, IndexType>;

        StrIndexTypeMap mGuidIndexMap;

        using GuidVector = TColanderVector<std::string>;

        GuidVector mGuids;


        IndexType GetFreeIndex();
    };
}