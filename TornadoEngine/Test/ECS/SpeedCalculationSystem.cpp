/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SpeedCalculationSystem.h"
#include "HiTimer.h"

void TSpeedCalculationSystem::Start()
{
  mStart = ht_GetMSCount();
}
//------------------------------------------------------------------------
void TSpeedCalculationSystem::Stop()
{
  auto finish = ht_GetMSCount();
  mElapsedTime_ms = finish - mStart;
}
//------------------------------------------------------------------------
std::string TSpeedCalculationSystem::SpeedToStr( size_t count )
{
  return std::to_string( Speed( count ) );
}
//------------------------------------------------------------------------
float TSpeedCalculationSystem::Speed( size_t count )
{
  auto speed = mElapsedTime_ms * 1000.0f / count ;
  return (float) speed;
}
//------------------------------------------------------------------------
