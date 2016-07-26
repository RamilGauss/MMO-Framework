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
#include "PreBuilder.h"
#include "MapItem.h"

class TGameObject;

class DllExport TPreBuilderGameObject : public TPreBuilder
{
public:
  TPreBuilderGameObject();
  virtual ~TPreBuilderGameObject();

  virtual void SetObjectItem(TMapItem::TObject* pObjectItem) = 0;

  //virtual std::string GetStrDesc() = 0;
  //virtual TGameObject* GetGameObject() = 0;
};

#endif
