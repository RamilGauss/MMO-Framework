/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IClientDeveloperTool.h"
#include "BL_Debug.h"
#include "NameSrcEventID.h"

using namespace nsEvent;

static IClientDeveloperTool* g_ClientDeveloperTool = NULL;

IClientDeveloperTool::IClientDeveloperTool()
{
  BL_ASSERT(g_ClientDeveloperTool==NULL);// только один объект
  g_ClientDeveloperTool = this;
}
//-----------------------------------------------------------------------
IClientDeveloperTool::~IClientDeveloperTool()
{
  g_ClientDeveloperTool = NULL;
}
//-----------------------------------------------------------------------
IClientDeveloperTool* IClientDeveloperTool::Singleton()
{
  return g_ClientDeveloperTool;
}
//-----------------------------------------------------------------------
