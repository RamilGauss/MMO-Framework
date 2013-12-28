/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IServerDeveloperTool.h"
#include "BL_Debug.h"
#include "NameSrcEventID.h"

using namespace nsEvent;

static IServerDeveloperTool* g_ServerDeveloperTool = NULL;

IServerDeveloperTool::IServerDeveloperTool()
{
  BL_ASSERT(g_ServerDeveloperTool==NULL);// только один объект
  g_ServerDeveloperTool = this;
}
//-----------------------------------------------------------------------
IServerDeveloperTool::~IServerDeveloperTool()
{
  g_ServerDeveloperTool = NULL;
}
//-----------------------------------------------------------------------
IServerDeveloperTool* IServerDeveloperTool::Singleton()
{
  return g_ServerDeveloperTool;
}
//-----------------------------------------------------------------------
