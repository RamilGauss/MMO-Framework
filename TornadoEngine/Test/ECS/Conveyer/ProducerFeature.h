#pragma once
#include "Feature.h"
#include "ProducerSystem.h"

class TProducerFeature : public MWorks::ECS::TFeature
{
public:
  virtual void PrepareFeature()
  {
    AddToConveyer<TProducerSystem>();
  }
};