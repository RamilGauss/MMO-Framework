/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ThreadModulesH
#define ThreadModulesH

#include "ThreadBoost.h"
#include <vector>
#include "CallBackRegistrator.h"

class IModule;

class TThreadModules : public TThreadBoost
{
  typedef std::vector<IModule*> TVecPtrModule;
  TVecPtrModule mVecModule;

  TCallBackRegistrator1<std::string>* mCB_Stop;

public:
  void AddModule(IModule* pModule);
  void SetCallbackStop(TCallBackRegistrator1<std::string>* pCB);

protected:
  virtual void Work();
};

#endif