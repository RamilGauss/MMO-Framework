/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterCamera.h"
#include "Camera.h"



void AdapterCamera::SetPtr(TCamera* v)
{
  mCamera = v;
}
//---------------------------------------------------------------------------------------------
AdapterCamera::AdapterCamera()
{
  mCamera = NULL;
}
//---------------------------------------------------------------------------------------------
AdapterCamera::~AdapterCamera()
{

}
//---------------------------------------------------------------------------------------------
void AdapterCamera::Update()
{
  mCamera->Update();
}
//---------------------------------------------------------------------------------------------
const nsMathTools::TMatrix16* AdapterCamera::GetView()
{
  return mCamera->GetView();
}
//---------------------------------------------------------------------------------------------
const nsMathTools::TVector3*  AdapterCamera::GetEyePt()
{
  return mCamera->GetEyePt();
}
//---------------------------------------------------------------------------------------------
const nsMathTools::TMatrix16* AdapterCamera::GetProj()
{
  return mCamera->GetProj();
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetView(nsMathTools::TMatrix16* view)
{
  mCamera->SetView(view);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetProj(nsMathTools::TMatrix16* proj)
{
  mCamera->SetProj(proj);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane )
{
  mCamera->SetProjParams( fFOV, fAspect, fNearPlane, fFarPlane );
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetOrient(nsMathTools::TVector3* up, bool use )
{
  mCamera->SetOrient( up, use );
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetPositionLookAt(nsMathTools::TVector3* pPosLookAt)
{
  mCamera->SetPositionLookAt( pPosLookAt );
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetPosition(nsMathTools::TVector3* pPos)
{
  mCamera->SetPosition( pPos );
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::MoveInDirection(float dist, nsMathTools::TVector3* pDir)
{
  mCamera->MoveInDirection( dist, pDir );
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::MoveForward(float dist)
{
  mCamera->MoveForward(dist);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::MoveRight(float dist)
{
  mCamera->MoveRight(dist);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::MoveUp(float dist)
{
  mCamera->MoveUp(dist);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::ClearRotate()
{
  mCamera->ClearRotate();
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::RotateDown(float angle)
{
  mCamera->RotateDown(angle);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::RotateRight(float angle)
{
  mCamera->RotateRight(angle);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::Roll(float angle)
{
  mCamera->Roll(angle);
}
//---------------------------------------------------------------------------------------------
void AdapterCamera::SetDir(nsMathTools::TVector3* right, nsMathTools::TVector3* up, nsMathTools::TVector3* lookat)
{
  mCamera->SetDir(right, up, lookat);
}
//---------------------------------------------------------------------------------------------
