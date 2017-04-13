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
  bool flgMovedCamera;

  bool flgMoveForward;
  bool flgMoveBackward;
  bool flgMoveRight;
  bool flgMoveLeft;
  bool flgMoveUp;
  bool flgMoveDown;

	bool flgFastMove;

public:
  TControlCamera();
  
  void SetMoveForward(bool v);
  void SetMoveBackward(bool v);
  void SetMoveRight(bool v);
  void SetMoveLeft(bool v);
  void SetMoveUp(bool v);
  void SetMoveDown(bool v);

	void SetFast(bool v);

  void CameraTryMove();

  void MoveMouse(int dX, int dY);
protected:
	float GetMove();

	float GetMoveForward();
	float GetMoveBackward();
	float GetMoveRight();
	float GetMoveLeft();
	float GetMoveUp();
	float GetMoveDown();

};

#endif
