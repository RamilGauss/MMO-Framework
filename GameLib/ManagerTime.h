/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IManagerTime.h"


#ifndef ManagerTimeH
#define ManagerTimeH

class TManagerTime : public IManagerTime
{
protected:
  

public:
  TManagerTime();
  virtual ~TManagerTime();

  // управление игровым временем
  virtual void SetTimeSpeed(float relative = 1.0f);// отношение реального к игровому
  virtual void SetTimeToBegin();
  virtual void SetTimeToEnd();
  virtual int  GetCountTimeStamp();
  virtual void SetTimeStamp(int stamp);
  virtual unsigned int GetTime();

};

#endif
