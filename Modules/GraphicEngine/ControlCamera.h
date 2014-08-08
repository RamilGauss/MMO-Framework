/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ControlCameraH
#define ControlCameraH

#include "Camera.h"

class TBaseObjectGE;
// Not Thread Safe!

class DllExport TControlCamera : public TCamera
{
  TCamera* mCamera;

  TBaseObjectGE* mLinkObj;

  float mDist;
public:
  typedef enum
  {
    eNotLinked, 
    eCoord,
    eOrientAndCoord,
  }TypeLinked;
private:  
  TypeLinked mMask;

  // при изменении скорости
  nsMathTools::TVector3 mSpeedShift;// x - forward, y - right, z - up
  unsigned int         mLastTime;// время изменения, мс

public:
  TControlCamera();
  virtual ~TControlCamera();

  virtual TBaseObjectGE* GetLinkedObject();
  virtual void Link(TBaseObjectGE* pObject, TypeLinked mask);
  virtual void Unlink();

  // смещение от eye обзора. Например, от 3 лица вид координаты точка больше 0
  // от 1 лица координаты равны нулю
  // влияет на вращение камеры (задает центр вращения)
  virtual float GetDistObj();
  virtual void  SetDistObj(float v);
  virtual void  AddDistObj(float dV);

  // для свободной камеры
  virtual void SetSpeedForward(float v);
  virtual void SetSpeedRight(float v);
  virtual void SetSpeedUp(float v);
  //---------------------------------------------------
  // интерфейс камеры
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
  void ApplySpeed();
  void InitLastTime();
  void GetFromLinkObj();
};

#endif