/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerSynchroObjectH
#define ManagerSynchroObjectH

#include <list>

class ISynchroObject;

class TManagerSynchroObject
{
  typedef std::list<ISynchroObject*> TListPtr;
  
  TListPtr mListObject;

public:
  TManagerSynchroObject();
  virtual ~TManagerSynchroObject();

  void Synchro();

  void Add(ISynchroObject* pObject);
  void Clear();
  
};

#endif
