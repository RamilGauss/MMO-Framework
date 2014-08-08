/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CameraH
#define CameraH

//#include "ICamera.h"
#include <list>
#include "MathTools.h"
#include "TypeDef.h"

// Not Thread Safe!

class DllExport TCamera
{
  bool flgUseOrient;
  nsMathTools::TVector3 mNormal2Earth;

  nsMathTools::TMatrix16 mView;
  nsMathTools::TMatrix16 mProj;

  nsMathTools::TVector3  mPosition;
  nsMathTools::TVector3  mLookAt;
  nsMathTools::TVector3  mRight;
  nsMathTools::TVector3  mUp;

  bool mChangedView;

  float mRotateUp;
  float mRotateRight;
  float mRotateLookAt;

  // для матрицы проекции
  float mfFOV;
  float mfAspect;
  float mfNearPlane;
  float mfFarPlane;

  const float defFOV;
  const float defAspect;
  const float defNearPlan;
  const float defFarPlan;
  const float defDotProductMin;
public:
  TCamera();
  virtual ~TCamera();

  virtual void Update();
  // выдать результат манипуляций
  virtual const nsMathTools::TMatrix16* GetView();
  virtual const nsMathTools::TMatrix16* GetProj();
  virtual const nsMathTools::TVector3*  GetEyePt();

  // базовая настройка
  virtual void SetView(nsMathTools::TMatrix16* view);
  virtual void SetProj(nsMathTools::TMatrix16* proj);

  virtual void SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane );
  virtual void SetOrient(nsMathTools::TVector3* up, bool use = true);
  //-------------------------------------------
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
protected:
  void UpdateView();

  void InitVector();

  void NormalByEarth();
};

#endif
