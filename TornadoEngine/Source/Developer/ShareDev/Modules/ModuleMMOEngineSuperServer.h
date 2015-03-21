/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleMMOEngineSuperServerH
#define ModuleMMOEngineSuperServerH

#include "ModuleMMOEngine.h"
#include "SuperServer.h"

class DllExport TModuleMMOEngineSuperServer : 
  public TModuleMMOEngine<nsMMOEngine::TSuperServer>
{
protected:
  virtual void Input(int id_sender, void* p, int size);
  virtual bool Output(void* p, int size);
};

#endif
