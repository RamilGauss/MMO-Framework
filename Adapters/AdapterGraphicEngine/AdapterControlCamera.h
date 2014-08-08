/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterControlCameraH
#define AdapterControlCameraH

#include "PrototypeControlCamera.h"

class TControlCamera;

/*
  ѕриоритет задани€ координат и ориентации
  1. Linked object (по маске)
  2. Orient
  3. Set/Add XXX
*/

class DllExport AdapterControlCamera : public PrototypeControlCamera
{
  TControlCamera* mCCamera;
public:
  void SetPtr(TControlCamera* v);

  AdapterControlCamera();
  virtual ~AdapterControlCamera();

  virtual IBaseObject* GetLinkedObject();
  // если указатель на объект существует, то берем с объекта параметры, которые указаны в маске
  // делаем SetXXX иначе SetXXX, который задан снаружи. ѕотом делаем AddXXX, который задан снаружи.
  virtual void Link(IBaseObject* pObject, TypeLinked maskUse );
  virtual void Unlink();

  // смещение от eye обзора. Ќапример, от 3 лица dist > 0
  // от 1 лица координаты равны нулю
  // вли€ет на вращение камеры (задает центр вращени€)
  virtual float GetDistObj();
  virtual void  SetDistObj(float radius);
  virtual void  AddDistObj(float dR);

  // дл€ свободной камеры, у.е./сек
  virtual void SetSpeedForward(float v);
  virtual void SetSpeedRight(float v);
  virtual void SetSpeedUp(float v);
  //-------------------------------------------------------------------------------------
  // CAMERA
  virtual void Update();
  // выдать результат манипул€ций
  virtual const nsMathTools::TMatrix16* GetView();
  virtual const nsMathTools::TVector3*  GetEyePt();
  virtual const nsMathTools::TMatrix16* GetProj();

  // базова€ настройка
  virtual void SetView(nsMathTools::TMatrix16* view);
  virtual void SetProj(nsMathTools::TMatrix16* proj);

  virtual void SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane );

  // если задано использование этого параметра, то стоит запрет на использование Roll(...),
  // этот вектор и задает Roll
  // нормаль к «емле, например, при использовании не в космосе или воздухе.
  virtual void SetOrient(nsMathTools::TVector3* up, bool use = true);

  // манипул€ции
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