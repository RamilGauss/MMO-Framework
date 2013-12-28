/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>

#include "TankTower.h"
#include "HiTimer.h"
#include "BL_Debug.h"
#include "Struct3D.h"

#pragma warning(disable: 4305)

using namespace std;
using namespace nsStruct3D;

const char* NameTrackR = "TrackR";
const char* NameTrackL = "TrackL";

const char* ParamTime = "Time";
const char* ParamaVelocity = "Velocity";

TTankTower::TTankTower()
{
  mIndexTrackR = 0;
  mIndexTrackL = 0;
  mIndexTime = 0;
  mIndexVelocity = 0;

  //------------------------------------------------
  // свойства по-умолчанию, временно, пока нет Ѕƒ
  mProperty.mID_tank = 0;

  mTower = 0; // номер, 0 - базова€ (сток)
  mGun = 0;

  mProperty.mSpeedRotateTower  = 0.2f;
  mProperty.mSpeedReductionGun = 0.1f;

  mProperty.mVMaxGunUgol = 15.0f/180.0f*M_PI;  // вверх, рад
  mProperty.mVMinGunUgol = -5.0f/180.0f*M_PI;  // вниз, рад
  mProperty.mHMaxGunUgol = 0.0f;  // по часовой стрелке, рад
  mProperty.mHMinGunUgol = 0.0f;  // против часовой стрелке, рад
}
//------------------------------------------------------------------------
TTankTower::~TTankTower()
{

}
//------------------------------------------------------------------------
bool TTankTower::GetMirror(char ** pData,int &size)
{

  return false;
}
//------------------------------------------------------------------------
void TTankTower::SetMirror(char *pData,int size)
{

}
//-----------------------------------------------------------------------
bool TTankTower::Animate(unsigned int time_ms)
{
  //RotateTurret(M_PI/4.1f);
  //RotateVerticalGun(-0.2f);

  return true;
}
//------------------------------------------------------------------------
void TTankTower::RotateTurret(float ugol)
{
  // вращаем башню
  TMatrix16 matrix;
  SetMatrixIdentity(&matrix);
  SetMatrixRotateZ(&matrix,ugol);

  mTree.ChangeMatrix(string("Turret"),&matrix);
  mTree.GetMatrix(&mVectorMatrix);
}
//------------------------------------------------------------------------
void TTankTower::RotateVerticalGun(float ugol)
{
  // двигаем пушкой
  TMatrix16 matrix;
  SetMatrixIdentity(&matrix);
  SetMatrixRotateX(&matrix,ugol);

  mTree.ChangeMatrix(string("Gun"),&matrix);
  mTree.GetMatrix(&mVectorMatrix);
}
//------------------------------------------------------------------------
void TTankTower::SetHuman(char* pData, int size)
{
  
}
//------------------------------------------------------------------------
void TTankTower::SetupShaderStackModelGE()
{
  float time_ms = (float)ht_GetMSCount(); 
  time_ms /= 1000.0f;

  SetShaderStackMask(&mShaderStackMask);// настроить маску
  // настроить сам шейдерный стек

  mV *= -1; //###
  SetupShaderStack(mIndexTrackL,mIndexTime,    &time_ms,sizeof(time_ms));
  SetupShaderStack(mIndexTrackL,mIndexVelocity,&mV,     sizeof(mV));
  
  mV *= -1; //###
  SetupShaderStack(mIndexTrackR,mIndexTime,    &time_ms,sizeof(time_ms));
  SetupShaderStack(mIndexTrackR,mIndexVelocity,&mV,     sizeof(mV));
}
//------------------------------------------------------------------------------------------------
void TTankTower::EventSetModelGE()
{
  int cnt = mVectorNamePart.size();
  for(int i = 0 ; i < cnt ; i++)
  {
    if(mVectorNamePart.at(i).name.compare(NameTrackR)==0)
      mIndexTrackR = i;
    if(mVectorNamePart.at(i).name.compare(NameTrackL)==0)
      mIndexTrackL = i;
  }
  //-----------------------------------------------------
  mIndexTime        = GetShaderStackIndexByName(mIndexTrackR,ParamTime);
  mIndexVelocity    = GetShaderStackIndexByName(mIndexTrackR,ParamaVelocity);

  cnt  = mVectorNamePart.size();
  for( int i = 0 ; i < cnt ; i++)
    mShaderStackMask.push_back(0);
  mShaderStackMask.at(mIndexTrackR) = 1;
  mShaderStackMask.at(mIndexTrackL) = 1;
}
//------------------------------------------------------------------------------------------------
const nsStruct3D::TMatrix16* TTankTower::GetMatrixForCamera()
{
  mMatrixForCamera = mWorld;
  mMatrixForCamera._43 += 2.0f;
  return &mMatrixForCamera;
}
//------------------------------------------------------------------------------------------------
