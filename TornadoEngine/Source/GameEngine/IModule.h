/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IModuleH
#define IModuleH

#include "SrcEvent.h"

class DllExport IModule : public TSrcEvent
{
  bool flgUseInConveyer;
  int  mID;
public:
  IModule(){flgUseInConveyer=true;mID=-1;};
  virtual ~IModule(){};

  virtual bool Work() = 0;
  int  GetID(){return mID;}
  void SetID(int id){mID=id;}

  void SetUseInConveyer(bool v){flgUseInConveyer=v;}
  bool IsUseInConveyer(){return flgUseInConveyer;}
};

#endif
