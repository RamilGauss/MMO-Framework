#pragma once

namespace MWorks
{
  namespace ECS
  {
    template <typename Component>
    Component* SingleComponent( MWorks::ECS::THugeRegistry* registry )// когда точно есть одна сущность с данным компонентом
    {
      auto ent = SingleEntity<Component>( registry );
      if( ent == entt::null )
        return nullptr;
      return &(registry->get<Component>( ent ));
    }

    template <typename Component>
    MWorks::ECS::TEntity SingleEntity( MWorks::ECS::THugeRegistry* registry )// когда точно есть одна сущность с данным компонентом
    {
      auto view = registry->view<Component>();
      if( view.size() == 0 )
        entt::null;
      return view[0];
    }
  }
}