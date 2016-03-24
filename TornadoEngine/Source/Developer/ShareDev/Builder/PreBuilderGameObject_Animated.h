/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGameObject_AnimatedH
#define PreBuilderGameObject_AnimatedH

#include "TypeDef.h"
#include "PreBuilderGameObject.h"

class DllExport TPreBuilderGameObject_Animated : public TPreBuilderGameObject
{
public:
  TPreBuilderGameObject_Animated();
  virtual ~TPreBuilderGameObject_Animated();

  virtual std::string GetStrDesc();
  virtual TGameObject* GetGameObject();
};

#endif
