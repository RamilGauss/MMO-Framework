/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SortedVecWithKeyMap.h"
#include "BL_Debug.h"

#include <algorithm>
#include <search.h>
#include "FastUpperBound.h"

using namespace std;

//-------------------------------------------------------------------------------------
int compare( unsigned int* v1, unsigned int* v2 )
{
  if ( *v1 > *v2 )
    return 1;
  if ( *v1 == *v2 )
    return 0;
  return -1;
}
//-------------------------------------------------------------------------------------
int TSortedVecWithKeyMap::GetSize()
{
  return mIDVec.mCounter;
}
//-------------------------------------------------------------------------------------
unsigned int TSortedVecWithKeyMap::GetFirstID()
{
  return mIDVec.mVec[0];
}
//-------------------------------------------------------------------------------------
bool TSortedVecWithKeyMap::FindKeyByID( unsigned int ID, unsigned int& key )
{
  auto fit = mKeyIDMap.right.find( ID );
  if ( fit == mKeyIDMap.right.end() )
    return false;

  key = fit->second;
  return true;
}
//---------------------------------------------------------------------------------------
void TSortedVecWithKeyMap::PushBack( unsigned int key, unsigned int ID )
{
  mKeyIDMap.insert( {key, ID} );
  mIDVec.Append( ID );
}
//-------------------------------------------------------------------------------------
void TSortedVecWithKeyMap::Insert( unsigned int key, unsigned int ID )
{
  int index = fast_upper_bound2<unsigned int>( mIDVec.mVec, mIDVec.mCounter, ID );
  auto beginPtr = &mIDVec.mVec[0];
  int size = mIDVec.mCounter - index;

  memmove( beginPtr + index + 1, beginPtr + index, size * sizeof( unsigned int ) );
  mIDVec.mCounter++;
  mIDVec.mVec[index] = ID;

  mKeyIDMap.insert( {key, ID} );
}
//-------------------------------------------------------------------------------------
void TSortedVecWithKeyMap::RemoveFirst()
{
  if ( mIDVec.mCounter == 0 )
    return;
  unsigned int ID = mIDVec.mVec[0];
  unsigned int key;
  if ( FindKeyByID( ID, key ) == false )
    return;
  RemoveByKey( key );
}
//-------------------------------------------------------------------------------------
void TSortedVecWithKeyMap::RemoveByKey( unsigned int key )
{
  unsigned int ID;
  if ( FindIDByKey( key, ID ) == false )
    return;
  mKeyIDMap.left.erase( key );

  DeleteFromVectorByID( ID );
}
//-------------------------------------------------------------------------------------
bool TSortedVecWithKeyMap::GetFirst( unsigned int& key )
{
  if ( mIDVec.mCounter == 0 )
    return false;
  auto ID = mIDVec.mVec[0];
  return FindKeyByID( ID, key );
}
//-------------------------------------------------------------------------------------
bool TSortedVecWithKeyMap::Get( int index, unsigned int& key )
{
  if ( mIDVec.mCounter == 0 )
    return false;
  auto ID = mIDVec.mVec[index];
  return FindKeyByID( ID, key );
}
//-------------------------------------------------------------------------------------
bool TSortedVecWithKeyMap::GetIndex( unsigned int key, int& index )
{
  unsigned int ID;
  if ( FindIDByKey( key, ID ) == false )
    return false;
  return FindIndexByID( ID, index );
}
//-------------------------------------------------------------------------------------
bool TSortedVecWithKeyMap::FindIDByKey( unsigned int key, unsigned int& ID )
{
  auto fit = mKeyIDMap.left.find( key );
  if ( fit == mKeyIDMap.left.end() )
    return false;

  ID = fit->second;
  return true;
}
//-------------------------------------------------------------------------------------
bool TSortedVecWithKeyMap::FindIndexByID( unsigned int ID, int& index )
{
  // ищем итератор по внутреннему индексу
  // т.к. массив всегда сортированный можно быстро искать дихотомией
  void* result = bsearch( &ID, &mIDVec.mVec[0], mIDVec.mCounter,
    sizeof( unsigned int ), ( int( *)( const void*, const void* ) )compare );

  if ( result == nullptr )
  {
    BL_FIX_BUG();
    return false;
  }
  index = ( (char*) result - (char*) &mIDVec.mVec[0] ) / sizeof( unsigned int );
  return true;
}
//-------------------------------------------------------------------------------------
void TSortedVecWithKeyMap::DeleteFromVectorByID( unsigned int ID )
{
  int index;
  if ( FindIndexByID( ID, index ) == false )
    return;

  auto beginPtr = &mIDVec.mVec[0];
  int size = mIDVec.mCounter - index - 1;
  memmove( beginPtr + index, beginPtr + index + 1, size * sizeof( unsigned int ) );
  mIDVec.mCounter--;
}
//-------------------------------------------------------------------------------------
