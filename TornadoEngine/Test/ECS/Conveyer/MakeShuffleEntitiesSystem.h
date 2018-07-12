#pragma once
#include "InitSystem.h"
#include "ShuffledComponents.h"

#include <ctime>

class TMakeShuffleEntitiesSystem : public MWorks::ECS::TInitSystem
{
#ifdef _DEBUG
  const int COUNT = 20000;
#else
  const int COUNT = 20000000;
#endif

public:

  virtual void Init() override
  {
    std::srand( (unsigned int) std::time( nullptr ) );

    auto registry = GetRegistry();
    for( int i = 0; i < COUNT; i++ )
    {
      auto entity = registry->create();
      auto typeCount = 1 + std::rand() % 6;
      for( int c = 0; c < typeCount; c++ )// комбинировать компоненты
      {
        switch( c )
        {
          case 0:
            registry->assign<ShuffledComponents::A>( entity, i );
            break;
          case 1:
            registry->assign<ShuffledComponents::B>( entity, i );
            break;
          case 2:
            registry->assign<ShuffledComponents::C>( entity, i );
            break;
          case 3:
            registry->assign<ShuffledComponents::D>( entity, i );
            break;
          case 4:
            registry->assign<ShuffledComponents::E>( entity, i );
            break;
          case 5:
            registry->assign<ShuffledComponents::F>( entity, i );
            break;
          default:;
        }
      }
    }
  }
};