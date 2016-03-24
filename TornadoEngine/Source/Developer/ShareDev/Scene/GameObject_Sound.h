/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameObject_SoundH
#define GameObject_SoundH

#include "TypeDef.h"
#include "GameObject.h"

class DllExport TGameObject_Sound : public TGameObject
{
public:
  static std::string GetType();

  TGameObject_Sound();
  virtual ~TGameObject_Sound();

  virtual void SetInternalState(TMapStrStr& mapStrStr);
  virtual bool GetInternalState(TMapStrStr& mapStrStr);
};

#endif
