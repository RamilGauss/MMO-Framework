#include "ReactiveForOneEventSystem.h"

using namespace MWorks::ECS;

TReactiveForOneEventSystem::TReactiveForOneEventSystem() : TBaseReactiveSystem(false)
{
}
//-------------------------------------------------------------------
void TReactiveForOneEventSystem::Update()
{
  // entity
  int filtered = 0;
  for (size_t i = 0; i < mReactionEntities.mCounter; i++)
  {
    auto& entity = mReactionEntities.mVec[i];
    if (Filter(entity))
    {
      mReactionEntities.mVec[filtered] = entity;
      filtered++;
    }
  }

  mReactionEntities.mCounter = filtered;

  Reactive(mReactionEntities.mVec, mReactionEntities.mCounter);
  mReactionEntities.Clear();
}
//-------------------------------------------------------------------
void TReactiveForOneEventSystem::Reaction(THugeRegistry& /*registry*/, const TEntity entity)
{
  if (mReactionEntities.mCounter >= mReactionEntities.mVec.size())
    mReactionEntities.IncreaseVec();
  mReactionEntities.Append(entity);
}
//-------------------------------------------------------------------
