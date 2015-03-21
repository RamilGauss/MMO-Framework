/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleMMOEngineSlaveH
#define ModuleMMOEngineSlaveH

#include "ModuleMMOEngine.h"
#include "Slave.h"

class DllExport TModuleMMOEngineSlave : 
  public TModuleMMOEngine<nsMMOEngine::TSlave>
{
protected:
  virtual void Input(int id_sender, void* p, int size);
  virtual bool Output(void* p, int size);
};

#endif
