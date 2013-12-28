/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ICameraH
#define ICameraH

#include "Struct3D.h"
#include "TypeDef.h"

// абстрагирование здесь с целью отв€зки от компил€ции во внешних модул€х.

// —уществует всего 3 варианта использовани€ камеры:
// 1. —вободна€ камера (управление через мышь и клавиатуру, миникамера)."—вободный полет"
// бывает 2 типов: 1 - без Roll, 2 - с Roll
//    обеспечивает  ICamera 
// 2. ѕрив€зка к ќбъекту (данные частично или полностью идут от ќбъекта)."Linked Object"
// бывает 2 типов: 1 - с прив€зкой только по координатам, 2 - и координаты и ориентаци€
//    обеспечивает  IControlCamera 
// 3. Ѕез прив€зки, но с заданием точного местоположени€ и ориентации (макрокамера)."Ќаблюдатель"
//    обеспечивает  ICamera 

// миникамера - очень малые изменени€ параметров матрицы. Ќе критична последовательность изменений
// не важно в каком пор€дке идут вращение, перемещение.
// макрокамера - важен пор€док манипул€ций
class SHARE_EI ICamera
{
public:
  virtual ~ICamera(){};

  virtual void Update() = 0;
  // выдать результат манипул€ций
  virtual const nsStruct3D::TMatrix16* GetView() = 0;
  virtual const nsStruct3D::TVector3*  GetEyePt()= 0;
  virtual const nsStruct3D::TMatrix16* GetProj() = 0;

  // базова€ настройка
  virtual void SetView(nsStruct3D::TMatrix16* view) = 0;
  virtual void SetProj(nsStruct3D::TMatrix16* proj) = 0;

  virtual void SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane ) = 0;

  // если задано использование этого параметра, то стоит запрет на использование Roll(...),
  // этот вектор и задает Roll
  // нормаль к «емле, например, при использовании не в космосе или воздухе.
  virtual void SetOrient(nsStruct3D::TVector3* up, bool use = true) = 0;

  // манипул€ции
  // положение
  virtual void SetPositionLookAt(nsStruct3D::TVector3* pPosLookAt)     = 0;
  virtual void SetPosition(nsStruct3D::TVector3* pPos)                 = 0;
  virtual void MoveInDirection(float dist, nsStruct3D::TVector3* pDir) = 0;
  virtual void MoveForward(float dist)                                 = 0;// вдоль осей камеры
  virtual void MoveRight(float dist)                                   = 0;
  virtual void MoveUp(float dist)                                      = 0;

  // сбросить вращение
  virtual void ClearRotate()            = 0;
  // вращать 
  virtual void RotateDown(float angle)  = 0;
  virtual void RotateRight(float angle) = 0;
  virtual void Roll(float angle)        = 0;

  virtual void SetDir(nsStruct3D::TVector3* right, nsStruct3D::TVector3* up, nsStruct3D::TVector3* lookat) = 0;
};

#endif
