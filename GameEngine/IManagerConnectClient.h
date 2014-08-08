/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IManagerConnectClientH
#define IManagerConnectClientH

#include <vector>
#include "SrcEvent.h"

#define STR_NAME_MANAGER_SCENE "MCClient"

class IConnectClient;

class IManagerConnectClient //: public TSrcEvent
{
protected:
  std::vector<IConnectClient* > mVectorScene;

public:

  IManagerConnectClient();
  virtual ~IManagerConnectClient();

  void AddObject(IConnectClient* p);
  IConnectClient* Get(int index);
  int GetCountObject();

  void Erase(int index);
};

#endif
