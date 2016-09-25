/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ControlCameraH
#define ControlCameraH

#include "TypeDef.h"

class DllExport TControlCamera
{
  int mOldX;
  int mOldY;

  volatile bool flgMovedCamera;

  volatile bool flgMoveForward;
  volatile bool flgMoveBackward;
  volatile bool flgMoveRight;
  volatile bool flgMoveLeft;
  volatile bool flgMoveUp;
  volatile bool flgMoveDown;

public:
  TControlCamera();
  
  void SetMoveForward(bool v);
  void SetMoveBackward(bool v);
  void SetMoveRight(bool v);
  void SetMoveLeft(bool v);
  void SetMoveUp(bool v);
  void SetMoveDown(bool v);

  void CameraTryMove();

  void MouseLeftButtonDown( int x, int y);
  void MouseLeftButtonUp();
  void MoveMouse(int new_x, int new_y);
protected:

};

#endif
