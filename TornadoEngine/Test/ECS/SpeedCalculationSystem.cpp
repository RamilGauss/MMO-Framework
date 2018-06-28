#include "SpeedCalculationSystem.h"

void TSpeedCalculationSystem::Start()
{
  mStart = std::chrono::high_resolution_clock::now();
}
//------------------------------------------------------------------------
void TSpeedCalculationSystem::Stop()
{
  auto finish = std::chrono::high_resolution_clock::now();
  auto elapsed = finish - mStart;
  melapsedTime_ns = (double)elapsed.count();
}
//------------------------------------------------------------------------
std::string TSpeedCalculationSystem::SpeedToStr(size_t count)
{
  return std::to_string(Speed(count));
}
//------------------------------------------------------------------------
float TSpeedCalculationSystem::Speed(size_t count)
{
  auto speed = melapsedTime_ns / count / 1000.0f;
  return (float)speed;
}
//------------------------------------------------------------------------
