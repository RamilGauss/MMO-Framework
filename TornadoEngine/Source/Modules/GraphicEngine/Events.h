/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EventsH
#define EventsH

#include "TypeDef.h"
#include <OISMouse.h>
#include <OISKeyboard.h>

namespace nsGraphicEngine
{
#ifdef WIN32
#pragma pack(push, 1)
#endif

//---------------------------------------------------------------------
typedef enum
{
  eMouse    = 0,
  eKeyBoard = 1,
}tTypeEvent;
typedef enum
{
  eButtonDown,
  eButtonUp,
  eButtonDblClick,
  eWheel,
  eMove,
}tTypeMouseEvent;
//---------------------------------------------------------------------------------
struct DllExport TBaseEvent
{
  tTypeEvent type;
}_PACKED;
//---------------------------------------------------------------------------------
struct DllExport TKeyEvent : public TBaseEvent
{
  OIS::KeyCode key;
  bool pressed/*or released*/;
  int modifier;// OIS::KeyBoard::Modifier
  TKeyEvent(){type=eKeyBoard;pressed=false;modifier=0;}
}_PACKED;
//---------------------------------------------------------------------------------
// курсор мыши всегда находится внутри области окна (clipping), в случае попытки выйти за границу
// курсор вернётся в область окна, то есть x и y останутся теми же, а dx и dy изменятся.
struct DllExport TMouseEvent : public TBaseEvent
{
  tTypeMouseEvent typeEvent;// что произошло
  // Press, Release or DblClick
  OIS::MouseButtonID button;
  // wheel
  int delta_wheel;
  // for All events
  int pressedButtons;// bit position indicates button down OIS::MouseButtonID, e.g. (1<<OIS::MB_Right)
  int x;
  int y;
  int dx;
  int dy;
  TMouseEvent(){type=eMouse;x=0;y=0;dx=0;dy=0;delta_wheel=0;pressedButtons=0;button=OIS::MB_Left ;}
}_PACKED;
//---------------------------------------------------------------------------------
#ifdef WIN32
#pragma pack(pop)
#endif
}

#endif