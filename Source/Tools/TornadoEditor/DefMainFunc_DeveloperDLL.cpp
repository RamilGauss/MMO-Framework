/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DeveloperTool_DLL.h"

DllExport_C IDevTool* GetDevTool()
{
    return new TDevTool_EditorMap;
}
//-------------------------------------------------------------------
DllExport_C void FreeDevTool(IDevTool* p)
{
    delete p;
}
//-------------------------------------------------------------------
