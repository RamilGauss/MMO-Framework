/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerObjectH
#define ManagerObjectH

#include <map>

class TManagerObject
{
  typedef std::map<unsigned int,void*> TMapUintPtr;
  typedef TMapUintPtr::iterator TMapUintPtrIt;

  TMapUintPtr mMapID_Object;

public:
  TManagerObject();
  virtual ~TManagerObject();

  void Add(unsigned int id, void* pObject);
  void Remove(unsigned int id);
  
  void* Find(unsigned int id);

  void Clear();

  int GetCount();
protected:
};


#endif