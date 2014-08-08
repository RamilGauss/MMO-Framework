/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ListPtrH
#define ListPtrH

#include <list>
#include <boost/foreach.hpp>
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
  T* Get(){return &mList;}
  T* operator ->(){return Get();}
  void Clear()
  {
    BOOST_FOREACH(TClass* p, mList)
      delete p;
    mList.clear();
  }
protected:
  T mList;
};

#endif


