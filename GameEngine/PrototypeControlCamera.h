/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeControlCameraH
#define PrototypeControlCameraH

#include "PrototypeCamera.h"

class IBaseObject;

/*
  Приоритет задания координат и ориентации
  1. Linked object (по маске)
  2. Orient
  3. Set/Add XXX
*/

class DllExport PrototypeControlCamera : public PrototypeCamera
{
public:
  typedef enum
  {
    eNotLinked, 
    eCoord,
    eOrientAndCoord,
  }TypeLinked;


  PrototypeControlCamera();
  virtual ~PrototypeControlCamera();

  virtual IBaseObject* GetLinkedObject() = 0;
  // если указатель на объект существует, то берем с объекта параметры, которые указаны в маске
  // делаем SetXXX иначе SetXXX, который задан снаружи. Потом делаем AddXXX, который задан снаружи.
  virtual void Link(IBaseObject* pObject, TypeLinked maskUse ) = 0;
  virtual void Unlink() = 0;

  //virtual ICamera* GetCamera() = 0;// debug only

  // смещение от eye обзора. Например, от 3 лица dist > 0
  // от 1 лица координаты равны нулю
  // влияет на вращение камеры (задает центр вращения)
  virtual float GetDistObj()             = 0;
  virtual void  SetDistObj(float radius) = 0;
  virtual void  AddDistObj(float dR)     = 0;

  // для свободной камеры, у.е./сек
  virtual void SetSpeedForward(float v) = 0;
  virtual void SetSpeedRight(float v) = 0;
  virtual void SetSpeedUp(float v) = 0;
};

#endif