/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef Pattern_TankH
#define Pattern_TankH

#include "Pattern_Model.h"

class DllExport TPattern_Tank : public TPattern_Model
{
public:
  TPattern_Tank();
  virtual ~TPattern_Tank();

  void SetAccelerate(float power, float speedLinim);
  void SetMouseAim(nsMathTools::TOrientation& orient);

  bool GetRealMouseAim(nsMathTools::TOrientation& orient);
};

#endif

