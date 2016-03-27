/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderTableSoundH
#define PreBuilderTableSoundH

#include "TypeDef.h"
#include "PreBuilder.h"

struct TTableSoundItem;

class DllExport TPreBuilderTableSound : public TPreBuilder
{
public:
  TPreBuilderTableSound();
  virtual ~TPreBuilderTableSound();

  void Set(TTableSoundItem* pTableSoundItem);

  virtual bool GenerateTask(TVectorTypeTask& vecTypeTask);

  virtual void TakeTask_Ogre(TListTaskOgre& listOgre);
  virtual void TakeTask_Bullet(TListTaskBullet& listBullet);
  virtual void TakeTask_OpenAL(TListTaskOpenAL& listOpenAL);
};

#endif
