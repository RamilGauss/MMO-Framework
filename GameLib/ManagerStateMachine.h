/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerStateMachine_H
#define ManagerStateMachine_H

#include "IManagerStateMachine.h"
#include "StateMachine.h"
#include <vector>

class IXML;

class TManagerStateMachine : public IManagerStateMachine
{
  struct TDesc
  {
    unsigned int v;
    std::string  comment;
    TDesc(unsigned int _v,std::string& _comment)
    {
      v = _v;
      comment = _comment;
    }
  };

  typedef std::map<unsigned int, TDesc> TMapUintPtr;

  typedef TStateMachine<unsigned int, TMapUintPtr> TSM_UintUint;

  typedef std::vector<TSM_UintUint*> TVectorPtr;

  TVectorPtr mVecSM;

  IXML* pXML;

public:

  TManagerStateMachine();
  virtual ~TManagerStateMachine();

  virtual bool Load(const char* sPath, unsigned int &id);
  virtual bool SetState(const char* sNewStateName, unsigned int id = eAll);
  virtual bool GetValue(unsigned int id, unsigned int k, unsigned int& v);
  virtual bool GetComment(unsigned int id, unsigned int k, std::string&  comment);

protected:

  void Done();

};


#endif