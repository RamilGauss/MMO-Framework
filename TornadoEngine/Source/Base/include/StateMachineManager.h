/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "StateMachine.h"
#include <vector>
#include <string>
#include "TypeDef.h"

class IXML;

class DllExport TStateMachineManager
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

  TStateMachineManager();
  virtual ~TStateMachineManager();
  enum{eAll=-1};
  // загрузить и вернуть id для доступа
  virtual bool Load(const char* sPath, unsigned int &id);
  // по id поменять состояние с текущего на новое
  virtual bool SetState(const char* sNewStateName, unsigned int id = eAll);
  // по id получить мэппинг от k (состояние не меняется), сделано в угоду скорости работы
  virtual bool GetValue(unsigned int id, unsigned int k, unsigned int& v);
  virtual bool GetComment(unsigned int id, unsigned int k, std::string&  comment);

protected:
  void Done();
};
