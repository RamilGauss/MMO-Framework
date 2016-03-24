/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGameObject_SoundH
#define PreBuilderGameObject_SoundH

#include "TypeDef.h"
#include "PreBuilderGameObject.h"

class DllExport TPreBuilderGameObject_Sound : public TPreBuilderGameObject
{
public:
  TPreBuilderGameObject_Sound();
  virtual ~TPreBuilderGameObject_Sound();

  virtual std::string GetStrDesc();
  virtual TGameObject* GetGameObject();

};

#endif
