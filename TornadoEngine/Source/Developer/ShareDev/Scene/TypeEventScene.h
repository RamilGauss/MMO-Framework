/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef TypeEventSceneH
#define TypeEventSceneH

#include "MathTools.h"
#include "TypeDef.h"

#include "ContainerTypes.h"

namespace nsTypeEventScene
{
#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

  struct TEvent
  {
    typedef enum{Add,Delete,Update}eTypeEvent;// операции над объектами

    unsigned int typeEvent : 2;
    unsigned int idObject  : 30;
  }_PACKED;
  struct TDeleteEvent : TEvent
  {
    TDeleteEvent(){typeEvent = Delete;}
  }_PACKED;
  struct TPropertyEvent : TEvent // not use!
  {
    nsMathTools::TVector3 position;
    nsMathTools::TVector3 rotate;
    TContainer internalState;
  }_PACKED;
  struct TAddEvent : TPropertyEvent
  {
    TAddEvent(){typeEvent = Add;}
  }_PACKED;
  struct TUpdateEvent : TPropertyEvent
  {
    TUpdateEvent(){typeEvent = Update;}
  }_PACKED;

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif
}

#endif
