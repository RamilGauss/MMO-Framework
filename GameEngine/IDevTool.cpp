/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IDevTool.h"

IDevTool::IDevTool()
{
  flgExit = false;
}
//-----------------------------------------------------------------------
IDevTool::~IDevTool()
{

}
//-----------------------------------------------------------------------
bool IDevTool::NeedExit()
{
  return flgExit;
}
//-----------------------------------------------------------------------
void IDevTool::Exit()
{
  flgExit = true;
}
//-----------------------------------------------------------------------
void IDevTool::SetLoadConveyer(int procent)
{

}
//-----------------------------------------------------------------------
int IDevTool::GetTimeRefresh_ms()
{
  return 0;
}
//-----------------------------------------------------------------------
