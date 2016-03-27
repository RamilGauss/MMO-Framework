/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderGravityVectorH
#define PreBuilderGravityVectorH

#include "TypeDef.h"
#include "PreBuilder.h"
#include "MathTools.h"

class DllExport TPreBuilderGravityVector : public TPreBuilder
{
public:
  TPreBuilderGravityVector();
  virtual ~TPreBuilderGravityVector();

  void Set(nsMathTools::TVector3& vGravity);

  virtual bool GenerateTask(TVectorTypeTask& vecTypeTask);

  virtual void TakeTask_Ogre(TListTaskOgre& listOgre);
  virtual void TakeTask_Bullet(TListTaskBullet& listBullet);
  virtual void TakeTask_OpenAL(TListTaskOpenAL& listOpenAL);
};

#endif
