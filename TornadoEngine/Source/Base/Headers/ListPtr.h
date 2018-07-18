/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ListPtrH
#define ListPtrH

#include <list>
/*
  список указателей
  Not Thread safe
*/
template <class TClass>
class TListPtr
{
public:
  typedef std::list<TClass*> T;
  ~TListPtr()
  {
    Clear();
  }
  T* Get()
  {
    return &mList;
  }
  T* operator ->()
  {
    return Get();
  }
  void Clear()
  {
    typename T::iterator bit = mList.begin();
    typename T::iterator eit = mList.end();
    while( bit != eit )
    {
      delete *bit;
      bit++;
    }
    mList.clear();
  }
protected:
  T mList;
};

#endif


