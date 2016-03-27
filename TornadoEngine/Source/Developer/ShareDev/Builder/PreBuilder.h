/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreBuilderH
#define PreBuilderH

#include "TypeDef.h"
#include <vector>
#include <list>

class TTaskForBuilder_Ogre;
class TTaskForBuilder_Bullet;
class TTaskForBuilder_OpenAL;

class DllExport TPreBuilder
{
public:
  typedef enum{eOgre, eBullet, eOpenAL} eTypeTask;
  typedef std::vector<eTypeTask> TVectorTypeTask;

  TPreBuilder();
  virtual ~TPreBuilder();

  virtual bool GenerateTask(TVectorTypeTask& vecTypeTask) = 0;
  
  typedef std::list<TTaskForBuilder_Ogre*>   TListTaskOgre;
  typedef std::list<TTaskForBuilder_Bullet*> TListTaskBullet;
  typedef std::list<TTaskForBuilder_OpenAL*> TListTaskOpenAL;
    
  virtual void TakeTask_Ogre(TListTaskOgre& listOgre) = 0;
  virtual void TakeTask_Bullet(TListTaskBullet& listBullet) = 0;
  virtual void TakeTask_OpenAL(TListTaskOpenAL& listOpenAL) = 0;

};

#endif
