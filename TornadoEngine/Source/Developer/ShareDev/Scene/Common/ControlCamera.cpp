/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ControlCamera.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

#include <OgreVector3.h>

#define MOUSE_X_AMP 0.004f
#define MOUSE_Y_AMP 0.004f

#define DELTA_MOVE_CAMERA      0.05f
#define DELTA_FAST_MOVE_CAMERA 2.0f

TControlCamera::TControlCamera()
{
  flgMovedCamera  = false;
  flgMoveForward  = false;
  flgMoveBackward = false;
  flgMoveRight    = false;
  flgMoveLeft     = false;
  flgMoveUp       = false;
  flgMoveDown     = false;

  flgFastMove     = false;
}
//-------------------------------------------------------------------
void TControlCamera::SetMoveForward(bool v)
{
  flgMoveForward = v;
}
//-------------------------------------------------------------------
void TControlCamera::SetMoveBackward(bool v)
{
  flgMoveBackward = v;
}
//-------------------------------------------------------------------
void TControlCamera::SetMoveRight(bool v)
{
  flgMoveRight = v;
}
//-------------------------------------------------------------------
void TControlCamera::SetMoveLeft(bool v)
{
  flgMoveLeft = v;
}
//-------------------------------------------------------------------
void TControlCamera::SetMoveUp(bool v)
{
  flgMoveUp = v;
}
//-------------------------------------------------------------------
void TControlCamera::SetMoveDown(bool v)
{
  flgMoveDown = v;
}
//-------------------------------------------------------------------
void TControlCamera::SetFast(bool v)
{
  flgFastMove = v;
}
//-------------------------------------------------------------------
void TControlCamera::CameraTryMove()
{
  if( flgMoveForward==false )
  if( flgMoveBackward==false )
  if( flgMoveLeft==false )
  if( flgMoveRight==false )
  if( flgMoveDown==false )
  if( flgMoveUp==false )
    return;

  Ogre::Vector3 v(0,0,0);
  if( flgMoveForward )
    v.z = GetMoveForward();
  if( flgMoveBackward )
    v.z = GetMoveBackward();
  if( flgMoveLeft )
    v.x = GetMoveLeft();
  if( flgMoveRight )
    v.x = GetMoveRight();
  if( flgMoveDown )
    v.y = GetMoveDown();
  if( flgMoveUp )
    v.y = GetMoveUp();

  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
  pCamera->moveRelative(v);
}
//---------------------------------------------------------------------------------------------
void TControlCamera::MoveMouse(int dX, int dY)
{
  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();

  Ogre::Radian angle;
  angle = -dY;
  pCamera->pitch(MOUSE_Y_AMP*angle);

  angle = -dX;
  pCamera->yaw(MOUSE_X_AMP*angle);
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMove()
{
  return flgFastMove ? DELTA_FAST_MOVE_CAMERA : DELTA_MOVE_CAMERA;
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMoveForward()
{
  return -GetMove();
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMoveBackward()
{
  return GetMove();
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMoveRight()
{
  return GetMove();
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMoveLeft()
{
  return -GetMove();
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMoveUp()
{
  return GetMove();
}
//---------------------------------------------------------------------------------------------
float TControlCamera::GetMoveDown()
{
  return -GetMove();
}
//---------------------------------------------------------------------------------------------
