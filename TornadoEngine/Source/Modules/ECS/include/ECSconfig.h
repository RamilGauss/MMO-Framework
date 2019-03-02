/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <entt/entt.hpp>

namespace nsECSFramework
{
  using THugeRegistry = entt::Registry<std::uint64_t>;
  using TEntity = THugeRegistry::entity_type;
  using TSize_type = THugeRegistry::size_type;
}
