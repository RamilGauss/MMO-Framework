/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DeveloperTool_DLL.h"

#include "DevTool_Client.h"
#include "DevTool_Slave.h"
#include "DevTool_Master.h"
#include "DevTool_SuperServer.h"

DllExport_C IDevTool* GetDevTool(int variant_use)
{
  switch(variant_use)
  {
    case 0:
      return new TDevTool_Client;
    case 1:
      return new TDevTool_Slave;
    case 2:
      return new TDevTool_Master;
    case 3:
      return new TDevTool_SuperServer;
  }
  return NULL;
}
//-------------------------------------------------------------------
DllExport_C void FreeDevTool(IDevTool* p)
{
  delete p;
}
//-------------------------------------------------------------------
