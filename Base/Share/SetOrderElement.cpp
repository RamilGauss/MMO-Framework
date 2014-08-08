/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SetOrderElement.h"
#include "BL_Debug.h"

#include <algorithm>
#include <search.h>

using namespace std;

TSetOrderElement::TSetOrderElement()
{
  mNextAddInnerID = 0;
}
//-------------------------------------------------------------------------------------
TSetOrderElement::~TSetOrderElement()
{

}
//-------------------------------------------------------------------------------------
int compare( unsigned int* v1, unsigned int* v2 )
{
  if( *v1 > *v2 )
    return 1;
  if( *v1 == *v2 )
    return 0;
  return -1;
}
//-------------------------------------------------------------------------------------
bool TSetOrderElement::FindIndexByClientKey(unsigned int key, int& index)
{
  if(mMapKeyInnerIndex.size()==0)
    return false;

  // ищем внутренний индекс
	bmUintUint::left_iterator fmit = mMapKeyInnerIndex.left.find(key);
  if(fmit==mMapKeyInnerIndex.left.end())
  {
    BL_FIX_BUG();
    return false;
  }
  // ищем итератор по внутреннему индексу
  // т.к. массив всегда сортированный можно быстро искать дихотомией
  void* result = bsearch( &(fmit->second), 
                          &mVecSortInnerIndex[0], 
                          mVecSortInnerIndex.size(),
                          sizeof(TVectorUint::size_type),
                          (int (*)(const void*, const void*))compare);
  if(result==NULL)
  {
    BL_FIX_BUG();
    return false;
  }
  index = ((char*)result - (char*)&mVecSortInnerIndex[0])/sizeof(sizeof(TVectorUint::size_type));
  return true;
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::AddKeyAtEnd(unsigned int key)
{
  if(FindByKey(key))
  {
    BL_FIX_BUG();
    return;
  }

  mNextAddInnerID++;

  mMapKeyInnerIndex.insert(bmUintUint::value_type(key,mNextAddInnerID));
  
  ReserveForVector();
  mVecSortInnerIndex.push_back(mNextAddInnerID);
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::DeleteKey(unsigned int key)
{
  bmUintUint::left_iterator fit = mMapKeyInnerIndex.left.find(key);
  if(fit==mMapKeyInnerIndex.left.end())
    return;

  DeleteFromVectorByInnerIndex(fit->second);
  mMapKeyInnerIndex.left.erase(key);
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::Clear()
{
  mMapKeyInnerIndex.clear();
  mVecSortInnerIndex.clear();
}
//-------------------------------------------------------------------------------------
bool TSetOrderElement::FindByKey(unsigned int key)
{
	bmUintUint::left_iterator fit = mMapKeyInnerIndex.left.find(key);
  if(fit==mMapKeyInnerIndex.left.end())
    return false;
  return true;
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::ReserveForVector()
{
  int capacity = mVecSortInnerIndex.capacity();
  int size     = (mVecSortInnerIndex.size() + 1)* sizeof(TVectorUint::size_type);
  if(capacity <= size)
    mVecSortInnerIndex.reserve(3*size);
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::DeleteFromVectorByInnerIndex(unsigned int val)
{
  TVectorUint::iterator fit = find(mVecSortInnerIndex.begin(), mVecSortInnerIndex.end(), val);
  if(fit!=mVecSortInnerIndex.end())
    mVecSortInnerIndex.erase(fit);
}
//-------------------------------------------------------------------------------------
bool TSetOrderElement::DeleteFirst(unsigned int& key)
{
	if(mMapKeyInnerIndex.size()==0)
		return false;

	if(FindKeyByInnerIndex(mVecSortInnerIndex[0], key)==false)
		return false;
	DeleteKey(key);
	return true;
}
//-------------------------------------------------------------------------------------
bool TSetOrderElement::FindKeyByInnerIndex(unsigned int inner_index, unsigned int& key)
{
	bmUintUint::right_iterator fit = mMapKeyInnerIndex.right.find(inner_index);
	if(fit==mMapKeyInnerIndex.right.end())
		return false;

	key = fit->second;
	return true;
}
//-------------------------------------------------------------------------------------