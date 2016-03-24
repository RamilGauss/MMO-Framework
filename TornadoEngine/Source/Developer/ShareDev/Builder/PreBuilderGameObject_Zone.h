/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGameObject_ZoneH
#define PreBuilderGameObject_ZoneH

#include "TypeDef.h"
#include "PreBuilderGameObject.h"

class DllExport TPreBuilderGameObject_Zone : public TPreBuilderGameObject
{
public:
  TPreBuilderGameObject_Zone();
  virtual ~TPreBuilderGameObject_Zone();

  virtual std::string GetStrDesc();
  virtual TGameObject* GetGameObject();

};

#endif
