/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGameObject_ModelH
#define PreBuilderGameObject_ModelH

#include "TypeDef.h"
#include "PreBuilderGameObject.h"

class DllExport TPreBuilderGameObject_Model : public TPreBuilderGameObject
{
public:
  TPreBuilderGameObject_Model();
  virtual ~TPreBuilderGameObject_Model();

  virtual std::string GetStrDesc();
  virtual TGameObject* GetGameObject();

};

#endif
