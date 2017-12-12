/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_ChassisH
#define Pattern_ChassisH

#include "Pattern_Model.h"

class DllExport TPattern_Chassis : public TPattern_Model
{
public:
  TPattern_Chassis();
  virtual ~TPattern_Chassis();

  // side = 0..1
  void SetTorque(float torque, int side);

  // side = 0..1
  float GetAngleVelosity(int side);
  float GetLinearVelosity(int side);
};

#endif

