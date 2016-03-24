/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameObject_ModelH
#define GameObject_ModelH

#include "TypeDef.h"
#include "GameObject.h"

class DllExport TGameObject_Model : public TGameObject
{
public:
  static std::string GetType();

  TGameObject_Model();
  virtual ~TGameObject_Model();

  virtual void SetInternalState(TMapStrStr& mapStrStr);
  virtual bool GetInternalState(TMapStrStr& mapStrStr);
};

#endif
