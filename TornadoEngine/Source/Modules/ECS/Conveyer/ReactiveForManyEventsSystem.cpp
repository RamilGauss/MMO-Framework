#include "ReactiveForManyEventsSystem.h"
#include "FastUpperBound.h"

using namespace MWorks::ECS;

TReactiveForManyEventsSystem::TReactiveForManyEventsSystem() : TBaseReactiveSystem(true)
{
}
//-------------------------------------------------------------------
//#define SHUFFLE
void TReactiveForManyEventsSystem::Update()
{
#ifdef SHUFFLE
  mReactionEntities.Shuffle();
  mSortedUniqueEntities.mVec = mReactionEntities.mVec;
#endif
  // entity
  mSortedUniqueEntities.Sort();
  mSortedUniqueEntities.DeleteDuplicates();
  mStatistics.Zero(mSortedUniqueEntities.mCounter);

  //
  auto uniqueCount = 0;
  for (size_t i = 0; i < mReactionEntities.mCounter; i++)
  {
    auto entity = mReactionEntities.mVec[i];
    auto position = fast_upper_bound2<TEntity>(mSortedUniqueEntities.mVec, mSortedUniqueEntities.mCounter, entity);
    position--;
    mStatistics.mVec[position]++;
    if (mStatistics.mVec[position] == 1)//
    {
      mReactionEntities.mVec[uniqueCount] = entity;
      uniqueCount++;
    }
  }
  mReactionEntities.mCounter = uniqueCount;
  // entity
  for (size_t i = 0; i < mReactionEntities.mCounter; i++)
  {
    auto& entity = mReactionEntities.mVec[i];
    if (Filter(entity))
      mFilteredEntities.Append(entity);
  }

  Reactive(mFilteredEntities.mVec, mFilteredEntities.mCounter);

  mReactionEntities.Clear();
  mSortedUniqueEntities.Clear();
  mFilteredEntities.Clear();
}
//-------------------------------------------------------------------
void TReactiveForManyEventsSystem::Reaction(THugeRegistry& /*registry*/, const TEntity entity)
{
  if (mReactionEntities.mCounter >= mReactionEntities.mVec.size())
  {
    mReactionEntities.IncreaseVec();
    mSortedUniqueEntities.IncreaseVec();
    mFilteredEntities.IncreaseVec();
    mStatistics.IncreaseVec();
  }
  mReactionEntities.Append(entity);
  mSortedUniqueEntities.Append(entity);
}
//-------------------------------------------------------------------
