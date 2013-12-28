/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ObjectLightH
#define ObjectLightH

#include "../GameLib/IBaseObjectCommon.h"


class TObjectLight : public IBaseObjectCommon
{
public:
  TObjectLight();
  virtual ~TObjectLight();

  virtual bool GetMirror(char ** pData,int &size);
  virtual void SetMirror(char *pData,int size);
  virtual void SetHuman(char* pData, int size);
  virtual bool Animate(unsigned int time_ms);

  virtual bool IsGlowEffect(){return true;};
  virtual bool IsGlowable(){return true;};

protected:
  virtual void SetupShaderStackModelGE();
  virtual void EventSetModelGE();

};


#endif