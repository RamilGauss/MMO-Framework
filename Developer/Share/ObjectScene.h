/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ObjectSceneH
#define ObjectSceneH

#include "../GameLib/IBaseObjectCommon.h"


class TObjectScene : public IBaseObjectCommon
{
public:
  TObjectScene();
  virtual ~TObjectScene();

  virtual bool GetMirror(char ** pData,int &size);
  virtual void SetMirror(char *pData,int size);
  virtual void SetHuman(char* pData, int size);
  virtual bool Animate(unsigned int time_ms);

protected:
  virtual void SetupShaderStackModelGE();
  virtual void EventSetModelGE();

};


#endif