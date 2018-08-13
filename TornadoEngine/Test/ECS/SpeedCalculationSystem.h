/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <chrono>
#include <string>

class TSpeedCalculationSystem
{
  unsigned int mStart;

  unsigned int mElapsedTime_ms;
public:
  void Start();
  void Stop();

  // us
  std::string SpeedToStr(size_t count);
  // ns
  float Speed(size_t count);
};
