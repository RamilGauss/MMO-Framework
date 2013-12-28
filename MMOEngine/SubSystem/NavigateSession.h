/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NAVIGATE_SESSION_H
#define NAVIGATE_SESSION_H

#include <map>
#include <set>

#include "ShareMisc.h"

namespace nsMMOEngine
{
	class TSession;
  class TNavigateSession
  {
    typedef std::map<unsigned int,TSession*> TMapUintPtr;
    typedef TMapUintPtr::iterator TMapUintPtrIt;
    typedef TMapUintPtr::value_type TMapUintPtrVT;
    
    typedef std::map<TIP_Port,TSession*> TMapIP_Ptr;
    typedef TMapIP_Ptr::iterator TMapIP_PtrIt;
    typedef TMapIP_Ptr::value_type TMapIP_PtrItVT;

    typedef std::set<TSession*> TSetPtr;
    typedef TSetPtr::iterator TSetPtrIt;

    TMapUintPtr mMapID_Session;
    TMapIP_Ptr  mMapIP_Session;
    TSetPtr     mSetSession;

  public:
    TNavigateSession();
    ~TNavigateSession();
		
    void Add(TSession* pSession);
    void Delete(TSession* pSession);
		TSession* FindSessionByIP(TIP_Port& ip_port);
		TSession* FindSessionByID(unsigned int id);

		bool IsExist(TSession* pSession);

    std::set<TSession*>::iterator Begin();
    std::set<TSession*>::iterator End();

    void Work();

    void Clear();
  protected:
  };
}

#endif