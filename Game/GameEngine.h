/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameEngineH
#define GameEngineH

#include "IGameEngine.h"

class TGameEngine : public IGameEngine
{
public:
  TGameEngine();
  virtual ~TGameEngine();
	virtual int GetVersionRelease();
protected:
  virtual void SetupDevModule();
  virtual void FreeDevModule();
private:
  IModule* NewModule(int id_module, bool flgUseInConveyer);
  void DeleteModule(IModule* pModule);
};

#endif
