/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScSynchroSlave.h"

using namespace nsMMOEngine;

TContextScSynchroSlave::TContextScSynchroSlave()
{
  mLoadProcent = 0;
}
//------------------------------------------------------------------
TContextScSynchroSlave::~TContextScSynchroSlave()
{

}
//------------------------------------------------------------------    
void TContextScSynchroSlave::SetLoadProcent(unsigned char v)
{
  mLoadProcent = v;
}
//------------------------------------------------------------------    
unsigned char TContextScSynchroSlave::GetLoadProcent()
{
  return mLoadProcent;
}
//------------------------------------------------------------------    
