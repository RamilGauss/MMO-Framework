/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameObjectH
#define GameObjectH

#include <string>

class TGameObject
{
public:
  TGameObject();
  virtual ~TGameObject();
  
  virtual std::string GetType() = 0;
};


#endif
