/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGameObject_LightH
#define PreBuilderGameObject_LightH

#include "TypeDef.h"
#include "PreBuilderGameObject.h"

class DllExport TPreBuilderGameObject_Light : public TPreBuilderGameObject
{
public:
  TPreBuilderGameObject_Light();
  virtual ~TPreBuilderGameObject_Light();
 
  virtual void SetObjectItem(TMapItem::TObject* pObjectItem);

  virtual std::string GetStrDesc();
  virtual TGameObject* GetGameObject();

  virtual bool GenerateTask(TVectorTypeTask& vecTypeTask);

  virtual void TakeTask_Ogre(TListTaskOgre& listOgre);
  virtual void TakeTask_Bullet(TListTaskBullet& listBullet);
  virtual void TakeTask_OpenAL(TListTaskOpenAL& listOpenAL);
};

#endif
