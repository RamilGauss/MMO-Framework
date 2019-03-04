/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <vector>
#include <algorithm>
#include <cstring>
#include "TypeDef.h"

template<typename Type>
class DllExport TVectorRise
{
  void IncreaseVec();
public:
  std::vector<Type> mVec;
  size_t mCounter = 0;
  TVectorRise();

  inline void Append( Type value );
  inline void PopBack();
  inline void Shuffle();
  inline void Sort();
  inline void DeleteDuplicates();
  inline void Clear();
  inline void ReverseVec();

  inline void Zero( size_t count );

  TVectorRise<Type>& operator=( const TVectorRise<Type>& other );
  TVectorRise<Type>& operator+=( const TVectorRise<Type>& other );
};
//-----------------------------------------------------------------------------------------
template<typename Type>
TVectorRise<Type>::TVectorRise()
{
  mVec.resize( 0xFF + 1 );
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::IncreaseVec()
{
  mVec.resize( mVec.size() * 2 + 1 );
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Append( Type value )
{
  if ( mCounter == mVec.size() )
    IncreaseVec();
  mVec[mCounter] = value;
  mCounter++;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::PopBack()
{
  mCounter--;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Shuffle()
{
  std::random_shuffle( &mVec[0], &mVec[mCounter] );
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Sort()
{
  std::sort( &mVec[0], &mVec[mCounter] );
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::DeleteDuplicates()
{
  int uniqueCnt = 1;
  Type unique = mVec[0];
  for( size_t i = 0; i < mCounter; i++ )
  {
    auto& value = mVec[i];
    if( unique != value )
    {
      mVec[uniqueCnt] = value;
      unique = value;
      uniqueCnt++;
    }
  }
  mCounter = uniqueCnt;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::ReverseVec()
{
  std::reverse( mVec.begin(), mVec.begin() + mCounter );
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Clear()
{
  mCounter = 0;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
void TVectorRise<Type>::Zero( size_t count )
{
  memset( &mVec[0], 0, sizeof( Type )*count );
}
//-----------------------------------------------------------------------------------------
template<typename Type>
TVectorRise<Type>& TVectorRise<Type>::operator=( const TVectorRise<Type>& other )
{
  if( other.mVec.size() > mVec.size() )
    mVec.resize( other.mVec.size() );
  memcpy( &(mVec[0]), &(other.mVec[0]), other.mCounter * sizeof( Type ) );
  mCounter = other.mCounter;
  return *this;
}
//-----------------------------------------------------------------------------------------
template<typename Type>
TVectorRise<Type>& TVectorRise<Type>::operator+=( const TVectorRise<Type>& other )
{
  int newSize = mCounter + other.mCounter;
  if( newSize > mVec.size() )
    mVec.resize( newSize );
  memcpy( &(mVec[mCounter]), &(other.mVec[0]), other.mCounter * sizeof( Type ) );
  mCounter = newSize;
  return *this;
}
//-----------------------------------------------------------------------------------------