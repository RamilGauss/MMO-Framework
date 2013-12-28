/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SortByAlphabetic.h"
#include <algorithm>

using namespace std;

TSortByAlphabetic::TSortByAlphabetic()
{

}
//----------------------------------------------------------------------------
TSortByAlphabetic::~TSortByAlphabetic()
{

}
//----------------------------------------------------------------------------
void TSortByAlphabetic::Sort(std::vector<T>* pVecInOut )
{
  bool SortByAlphabetic( TSortByAlphabetic::T elem1, TSortByAlphabetic::T elem2 );
  sort( pVecInOut->begin(), pVecInOut->end(), SortByAlphabetic );
}
//----------------------------------------------------------------------------
bool SortByAlphabetic( TSortByAlphabetic::T elem1, TSortByAlphabetic::T elem2 )
{
  int res = elem1.s.compare(elem2.s);
  if(res==0)
  {
    if(elem1.v<elem2.v) 
      return true;
    return false;
  }
  return (res<0);
}
//----------------------------------------------------------------------------