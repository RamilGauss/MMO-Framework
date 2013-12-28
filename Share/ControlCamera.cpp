/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ControlCamera.h"
#include "MakerCamera.h"
#include "IBaseObject.h"
#include "HiTimer.h"
#include "Logger.h"

using namespace nsStruct3D;

TControlCamera::TControlCamera()
{
  TMakerCamera makerCamera;
  mCamera  = makerCamera.New();
  mLinkObj = NULL;
  mDist    = 0.0f;
  mMask    = eNotLinked;
}
//---------------------------------------------------------------------------------------
TControlCamera::~TControlCamera()
{
  TMakerCamera makerCamera;
  makerCamera.Delete(mCamera);
}
//---------------------------------------------------------------------------------------
IBaseObject* TControlCamera::GetLinkedObject()
{
  return mLinkObj;
}
//---------------------------------------------------------------------------------------
void TControlCamera::Link(IBaseObject* pObject, TypeLinked mask)
{
  mLinkObj = pObject;
  if(pObject)
    mMask    = mask;
}
//---------------------------------------------------------------------------------------
void TControlCamera::Unlink()
{
  Link(NULL,eNotLinked);
}
//---------------------------------------------------------------------------------------
//ICamera* TControlCamera::GetCamera()
//{
  //return mCamera;
//}
//---------------------------------------------------------------------------------------
void TControlCamera::SetView(TMatrix16* view)
{
  mCamera->SetView(view);
}
////---------------------------------------------------------------------------------------
void TControlCamera::SetProj(TMatrix16* proj)
{
  mCamera->SetProj(proj);
}
//---------------------------------------------------------------------------------------
const TMatrix16* TControlCamera::GetView()
{
  return mCamera->GetView();
}
//---------------------------------------------------------------------------------------
const TMatrix16* TControlCamera::GetProj()
{
  return mCamera->GetProj();
}
//---------------------------------------------------------------------------------------
const TVector3*  TControlCamera::GetEyePt()
{
  return mCamera->GetEyePt();
}
//---------------------------------------------------------------------------------------
float TControlCamera::GetDistObj()
{
  return mDist;
}
//---------------------------------------------------------------------------------------
void TControlCamera::SetDistObj(float v)
{
  mDist = v;
}
//---------------------------------------------------------------------------------------
void TControlCamera::AddDistObj(float dV)
{
  mDist += dV;
}
//---------------------------------------------------------------------------------------
void TControlCamera::SetPosition(TVector3* pPos)
{
  mCamera->SetPosition(pPos);
}
//---------------------------------------------------------------------------------------
void TControlCamera::MoveInDirection(float dist, TVector3* pDir)
{
  mCamera->MoveInDirection(dist,pDir);
}
//---------------------------------------------------------------------------------------
void TControlCamera::MoveForward(float dist)// вдоль осей камеры
{
  mCamera->MoveForward(dist);
}
//---------------------------------------------------------------------------------------
void TControlCamera::MoveRight(float dist)
{
  mCamera->MoveRight(dist);
}
//---------------------------------------------------------------------------------------
void TControlCamera::MoveUp(float dist)
{
  mCamera->MoveUp(dist);
}
//---------------------------------------------------------------------------------------
void TControlCamera::RotateDown(float angle)
{
  mCamera->RotateDown(angle);
}
//---------------------------------------------------------------------------------------
void TControlCamera::RotateRight(float angle)
{
  mCamera->RotateRight(angle);
}
//---------------------------------------------------------------------------------------
void TControlCamera::Roll(float angle)
{
  mCamera->Roll(angle);
}
//---------------------------------------------------------------------------------------
void TControlCamera::SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane )
{
  mCamera->SetProjParams(fFOV, fAspect, fNearPlane, fFarPlane);
}
//----------------------------------------------------------------------------------------
void TControlCamera::SetOrient(TVector3* up, bool use)
{
  mCamera->SetOrient(up,use);
}
//----------------------------------------------------------------------------------------
void TControlCamera::ClearRotate()
{
  mCamera->ClearRotate();
}
//----------------------------------------------------------------------------------------
void TControlCamera::SetPositionLookAt(TVector3* pPosLookAt)
{
  mCamera->SetPositionLookAt(pPosLookAt);
}
//----------------------------------------------------------------------------------------
void TControlCamera::SetSpeedForward(float v)
{
  InitLastTime();
  mSpeedShift.x = v;
}
//----------------------------------------------------------------------------------------
void TControlCamera::SetSpeedRight(float v)
{
  InitLastTime();
  mSpeedShift.y = v;
}
//----------------------------------------------------------------------------------------
void TControlCamera::SetSpeedUp(float v)
{
  InitLastTime();
  mSpeedShift.z = v;
}
//----------------------------------------------------------------------------------------
void TControlCamera::ApplySpeed()
{
  if(mSpeedShift==TVector3()) 
    return;

  unsigned int now = ht_GetMSCount();
  unsigned int dt = now - mLastTime; // сколько прошло времени
  if(dt==0) 
    return;
  // новая позиция
  TVector3 v = mSpeedShift*float(dt)/1000.0f;//у.е./с * мс/1000
  MoveForward(mSpeedShift.x);
  MoveRight(mSpeedShift.y);
  MoveUp(mSpeedShift.z);
  mLastTime = now;
}
//----------------------------------------------------------------------------------------
void TControlCamera::InitLastTime()
{
  if(mSpeedShift==TVector3()) mLastTime = ht_GetMSCount();
}
//----------------------------------------------------------------------------------------
void TControlCamera::GetFromLinkObj()
{
  if(mLinkObj==NULL||mMask==eNotLinked) return;

  // прежде чем менять позицию применить все операции вращения 
  // (что бы не было подергивания. т.к. камера работает по принципу микро изменений)
  mCamera->Update();

  // взять данные с объекта координаты и ориентацию по маске
  const TMatrix16* pM_Obj = mLinkObj->GetMatrixForCamera();

  const TMatrix16* pMCam = mCamera->GetView();

  TVector3 v;
  v.x = pM_Obj->_41;
  v.y = pM_Obj->_42;
  v.z = pM_Obj->_43;
  SetPosition(&v);

  if(mMask==eOrientAndCoord)
  {
    TMatrix16 m;
    SetMatrixInverse(&m,NULL,pM_Obj);
    
    TVector3 r = *((TVector3*)pM_Obj->m[0]);
    TVector3 l = *((TVector3*)pM_Obj->m[1]);
    TVector3 u = *((TVector3*)pM_Obj->m[2]);

    r *= -1;// 
    l *= -1;// 
    mCamera->SetDir(&r,&u,&l);
  }
  // отодвинуться от объекта
  MoveForward(mDist);
}
//----------------------------------------------------------------------------------------
void TControlCamera::SetDir(TVector3* right, TVector3* up, TVector3* lookat)
{
  mCamera->SetDir(lookat, up, right);
}
//----------------------------------------------------------------------------------------
void TControlCamera::Update()
{
  // применить изменения координат с учетом времени и скорости 
  ApplySpeed();
  GetFromLinkObj();

  mCamera->Update();
}
//----------------------------------------------------------------------------------------
