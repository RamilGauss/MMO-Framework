/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TankH
#define TankH

#include "GameObject.h"

class TTank : public TGameObject
{
public:
  TTank();
  virtual ~TTank();

  virtual std::string GetType(){return "Tank";}

  // debugging
  void SetTurretTurn(float angle_rad);// right-left
  void SetGunTurn(float angle_rad);// up-down
};


#endif
