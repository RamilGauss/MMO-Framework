/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterControlCamera.h"
#include "ControlCamera.h"
#include "IBaseObjectGE.h"
#include "AdapterGraphicEngineObject.h"

void AdapterControlCamera::SetPtr(TControlCamera* v)
{
  mCCamera = v;
}
//---------------------------------------------------------------------------------
AdapterControlCamera::AdapterControlCamera()
{
  mCCamera = NULL;
}
//---------------------------------------------------------------------------------
AdapterControlCamera::~AdapterControlCamera()
{

}
//---------------------------------------------------------------------------------
IBaseObject* AdapterControlCamera::GetLinkedObject()
{
  AdapterGraphicEngineObject* pObject = (AdapterGraphicEngineObject*)mCCamera->GetLinkedObject();
  return pObject->GetGameObject();
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::Link(IBaseObject* pObject, TypeLinked maskUse )
{
  TObjectGE* pObjectGE = (TObjectGE*)(((IBaseObjectGE*)pObject->GetPtrInherits())->GetObjectGE());
  
  TControlCamera::TypeLinked maskGE;
  switch(maskUse)
  {
    case PrototypeControlCamera::eNotLinked:
      maskGE = TControlCamera::eNotLinked;
      break;
    case PrototypeControlCamera::eCoord:
      maskGE = TControlCamera::eCoord;
      break;
    case PrototypeControlCamera::eOrientAndCoord:
      maskGE = TControlCamera::eOrientAndCoord;
      break;
  }
  mCCamera->Link(pObjectGE, maskGE);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::Unlink()
{
  mCCamera->Unlink();
}
//---------------------------------------------------------------------------------
float AdapterControlCamera::GetDistObj()
{
  return mCCamera->GetDistObj();
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetDistObj(float radius)
{
  mCCamera->SetDistObj(radius);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::AddDistObj(float dR)
{
  mCCamera->AddDistObj(dR);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetSpeedForward(float v)
{
  mCCamera->SetSpeedForward(v);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetSpeedRight(float v)
{
  mCCamera->SetSpeedRight(v);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetSpeedUp(float v)
{
  mCCamera->SetSpeedUp(v);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::Update()
{
  mCCamera->Update();
}
//---------------------------------------------------------------------------------
const nsMathTools::TMatrix16* AdapterControlCamera::GetView()
{
  return mCCamera->GetView();
}
//---------------------------------------------------------------------------------
const nsMathTools::TVector3*  AdapterControlCamera::GetEyePt()
{
  return mCCamera->GetEyePt();
}
//---------------------------------------------------------------------------------
const nsMathTools::TMatrix16* AdapterControlCamera::GetProj()
{
  return mCCamera->GetProj();
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetView(nsMathTools::TMatrix16* view)
{
  mCCamera->SetView(view);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetProj(nsMathTools::TMatrix16* proj)
{
  mCCamera->SetProj(proj);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane )
{
  mCCamera->SetProjParams( fFOV, fAspect, fNearPlane, fFarPlane);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetOrient(nsMathTools::TVector3* up, bool use )
{
  mCCamera->SetOrient(up, use);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetPositionLookAt(nsMathTools::TVector3* pPosLookAt)
{
  mCCamera->SetPositionLookAt(pPosLookAt);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetPosition(nsMathTools::TVector3* pPos)
{
  mCCamera->SetPosition(pPos);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::MoveInDirection(float dist, nsMathTools::TVector3* pDir)
{
  mCCamera->MoveInDirection(dist, pDir);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::MoveForward(float dist)
{
  mCCamera->MoveForward(dist);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::MoveRight(float dist)
{
  mCCamera->MoveRight(dist);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::MoveUp(float dist)
{
  mCCamera->MoveUp(dist);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::ClearRotate()
{
  mCCamera->ClearRotate();
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::RotateDown(float angle)
{
  mCCamera->RotateDown(angle);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::RotateRight(float angle)
{
  mCCamera->RotateRight(angle);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::Roll(float angle)
{
  mCCamera->Roll(angle);
}
//---------------------------------------------------------------------------------
void AdapterControlCamera::SetDir(nsMathTools::TVector3* right, nsMathTools::TVector3* up, nsMathTools::TVector3* lookat)
{
  mCCamera->SetDir(right, up, lookat);
}
//---------------------------------------------------------------------------------
