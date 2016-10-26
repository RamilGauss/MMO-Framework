/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ControlCamera.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

#include <OgreVector3.h>

#define MOUSE_X_AMP 0.004f
#define MOUSE_Y_AMP 0.004f

#define DELTA_MOVE_CAMERA 3.5f

#define DELTA_CAMERA_FORWARD  DELTA_MOVE_CAMERA
#define DELTA_CAMERA_BACKWARD DELTA_MOVE_CAMERA
#define DELTA_CAMERA_LEFT     DELTA_MOVE_CAMERA
#define DELTA_CAMERA_RIGHT    DELTA_MOVE_CAMERA
#define DELTA_CAMERA_DOWN     DELTA_MOVE_CAMERA
#define DELTA_CAMERA_UP       DELTA_MOVE_CAMERA

TControlCamera::TControlCamera()
{
  flgMovedCamera  = false;
  flgMoveForward  = false;
  flgMoveBackward = false;
  flgMoveRight    = false;
  flgMoveLeft     = false;
  flgMoveUp       = false;
  flgMoveDown     = false;
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
    v.z = -DELTA_CAMERA_FORWARD;
  if( flgMoveBackward )
    v.z = DELTA_CAMERA_BACKWARD;
  if( flgMoveLeft )
    v.x = -DELTA_CAMERA_LEFT;
  if( flgMoveRight )
    v.x = DELTA_CAMERA_RIGHT;
  if( flgMoveDown )
    v.y = -DELTA_CAMERA_DOWN;
  if( flgMoveUp )
    v.y = DELTA_CAMERA_UP;

  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
  pCamera->moveRelative(v);
}
//---------------------------------------------------------------------------------------------
//void TControlCamera::MouseLeftButtonDown( int x, int y)
//{
  //mOldX = x;
  //mOldY = y;
//}
//---------------------------------------------------------------------------------------------
//void TControlCamera::MouseLeftButtonUp()
//{
  //flgMovedCamera = false;
//}
//---------------------------------------------------------------------------------------------
// передавать разницу в координатах! а не сами координаты
//void TControlCamera::MoveMouse(int new_x, int new_y)
//{
//  flgMovedCamera = true;
//
//  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
//
//  Ogre::Radian angle;
//  angle = mOldY - new_y;
//  pCamera->pitch(MOUSE_Y_AMP*angle);
//
//  angle = mOldX - new_x;
//  pCamera->yaw(MOUSE_X_AMP*angle);
//
//  mOldX = new_x;
//  mOldY = new_y;
//}
//---------------------------------------------------------------------------------------------
void TControlCamera::MoveMouse(int dX, int dY)
{
  //flgMovedCamera = true;

  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();

  Ogre::Radian angle;
  angle = -dY;
  pCamera->pitch(MOUSE_Y_AMP*angle);

  angle = -dX;
  pCamera->yaw(MOUSE_X_AMP*angle);
}
//---------------------------------------------------------------------------------------------
