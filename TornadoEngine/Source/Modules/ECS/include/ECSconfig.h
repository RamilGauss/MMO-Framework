#pragma once
#include <entt/entt.hpp>

namespace MWorks
{
  namespace ECS
  {
    using THugeRegistry = entt::Registry<std::uint64_t>;
    using TEntity = THugeRegistry::entity_type;
    using TSize_type = THugeRegistry::size_type;
  }
}