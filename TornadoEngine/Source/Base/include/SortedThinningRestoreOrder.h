/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "VectorRise.h"
#include "FastUpperBound.h"

template<typename Type>
class TSortedThinningRestoreOrder
{
  // Важен порядок возникновения событий
  // после сортировки и прореживания от повторов
  TVectorRise<Type> mSortedUniqueEntities;
  // статистика по встречаемости
  TVectorRise<unsigned char> mStatistics;

  TVectorRise<Type> mResult;
public:
  void Work( TVectorRise<Type>& inOutVec )
  {
    if( inOutVec.mVec.size() > mSortedUniqueEntities.mVec.size() )
    {
      int reserveSize = inOutVec.mVec.size();

      mSortedUniqueEntities.mVec.resize( reserveSize );
      mStatistics.mVec.resize( reserveSize );
      mResult.mVec.resize( reserveSize );
    }

    mSortedUniqueEntities = inOutVec;// copy

    // сортированный и прореженный список
    mSortedUniqueEntities.Sort();
    mSortedUniqueEntities.DeleteDuplicates();
    mStatistics.Zero( mSortedUniqueEntities.mCounter );

    // восстанавливаем порядок событий
    // начинать с конца потому что:
    // в списке могут быть мертвые сущности и они могут быть
    auto uniqueCount = 0;
    for( int i = inOutVec.mCounter - 1; i >= 0; i-- )
    {
      auto entity = inOutVec.mVec[i];
      auto position = fast_upper_bound2<TEntity>( mSortedUniqueEntities.mVec, mSortedUniqueEntities.mCounter, entity );
      position--;
      if( mStatistics.mVec[position] == 0 )
      {
        mStatistics.mVec[position]++;
        mResult.mVec[uniqueCount] = entity;
        uniqueCount++;
      }
    }
    mResult.mCounter = uniqueCount;
    // инвертация списка
    mResult.ReverseVec();

    inOutVec = mResult;// copy
  }
};
