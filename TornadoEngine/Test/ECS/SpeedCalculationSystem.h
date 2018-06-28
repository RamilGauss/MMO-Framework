#pragma once

#include <chrono>
#include <string>

class TSpeedCalculationSystem
{
  std::chrono::high_resolution_clock::time_point mStart;
  double melapsedTime_ns;
public:
  void Start();
  void Stop();

  // us
  std::string SpeedToStr(size_t count);
  // ns
  float Speed(size_t count);
};
