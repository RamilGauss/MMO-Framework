/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DeveloperTool_DLL.h"

#include "DevTool_ViewerModel.h"
#include "DevTool_ClientTank.h"

#include "DevTool_SlaveTank.h"
#include "DevTool_MasterTank.h"
#include "DevTool_SuperServerTank.h"

DllExport_C IDevTool* GetDevTool(int variant_use)
{
  switch(variant_use)
  {
    case 0:
      return new TDevTool_ViewerModel;
    case 1:
      return new TDevTool_ClientTank;
    case 2:
      return new TDevTool_SlaveTank;
    case 3:
      return new TDevTool_MasterTank;
    case 4:
      return new TDevTool_SuperServerTank;
  }
  return NULL;
}
//-------------------------------------------------------------------
DllExport_C void FreeDevTool(IDevTool* p)
{
  delete p;
}
//-------------------------------------------------------------------
