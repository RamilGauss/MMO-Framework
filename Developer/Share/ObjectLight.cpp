/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ObjectLight.h"

TObjectLight::TObjectLight()
{
}
//------------------------------------------------------------------------
TObjectLight::~TObjectLight()
{

}
//------------------------------------------------------------------------
bool TObjectLight::GetMirror(char ** pData,int &size)
{
  return false;
}
//------------------------------------------------------------------------
void TObjectLight::SetMirror(char *pData,int size)
{
}
//-----------------------------------------------------------------------
bool TObjectLight::Animate(unsigned int time_ms)
{
  return true;
}
//------------------------------------------------------------------------
void TObjectLight::SetHuman(char* pData, int size)
{
  
}
//------------------------------------------------------------------------
void TObjectLight::SetupShaderStackModelGE()
{
}
//------------------------------------------------------------------------------------------------
void TObjectLight::EventSetModelGE()
{
}
//------------------------------------------------------------------------------------------------
