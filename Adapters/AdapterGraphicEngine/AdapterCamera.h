/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterCameraH
#define AdapterCameraH

#include "PrototypeCamera.h"

class TCamera;

class DllExport AdapterCamera : public PrototypeCamera
{
  TCamera* mCamera;
public:
  void SetPtr(TCamera* v);

  AdapterCamera();
  virtual ~AdapterCamera();

  virtual void Update();
  // выдать результат манипуляций
  virtual const nsMathTools::TMatrix16* GetView();
  virtual const nsMathTools::TVector3*  GetEyePt();
  virtual const nsMathTools::TMatrix16* GetProj();

  // базовая настройка
  virtual void SetView(nsMathTools::TMatrix16* view);
  virtual void SetProj(nsMathTools::TMatrix16* proj);

  virtual void SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane );

  // если задано использование этого параметра, то стоит запрет на использование Roll(...),
  // этот вектор и задает Roll
  // нормаль к Земле, например, при использовании не в космосе или воздухе.
  virtual void SetOrient(nsMathTools::TVector3* up, bool use = true);

  // манипуляции
  // положение
  virtual void SetPositionLookAt(nsMathTools::TVector3* pPosLookAt);
  virtual void SetPosition(nsMathTools::TVector3* pPos);
  virtual void MoveInDirection(float dist, nsMathTools::TVector3* pDir);
  virtual void MoveForward(float dist);// вдоль осей камеры
  virtual void MoveRight(float dist);
  virtual void MoveUp(float dist);

  // сбросить вращение
  virtual void ClearRotate();
  // вращать 
  virtual void RotateDown(float angle);
  virtual void RotateRight(float angle);
  virtual void Roll(float angle);

  virtual void SetDir(nsMathTools::TVector3* right, nsMathTools::TVector3* up, nsMathTools::TVector3* lookat);
};

#endif
