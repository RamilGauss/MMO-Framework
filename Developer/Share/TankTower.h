/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TankTowerH
#define TankTowerH

#include "ISynchroObject.h"

class TTankTower : public ISynchroObject
{
public:
  TTankTower();
  virtual ~TTankTower();

  virtual void Synchro();

  //###
  // debug only
  void RotateTurret(float ugol);
  void RotateVerticalGun(float ugol);
  //###
protected:
};


#endif