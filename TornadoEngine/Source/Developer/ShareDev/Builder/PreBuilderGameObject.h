/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGameObjectH
#define PreBuilderGameObjectH

#include "TypeDef.h"
#include <string>

class TGameObject;

class DllExport TPreBuilderGameObject
{
public:
  TPreBuilderGameObject();
  virtual ~TPreBuilderGameObject();

  virtual std::string GetStrDesc() = 0;
  virtual TGameObject* GetGameObject() = 0;
};

#endif
