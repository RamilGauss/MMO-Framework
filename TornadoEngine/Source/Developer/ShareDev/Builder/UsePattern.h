/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef UsePatternH
#define UsePatternH

#include "TypeDef.h"
#include <string>

class DllExport TUsePattern
{
public:
  TUsePattern();
  virtual ~TUsePattern();

  virtual bool UseByBullet(std::string& namePattern);
  virtual bool UseByOgre(std::string& namePattern);
  virtual bool UseByOpenAL(std::string& namePattern);
};

#endif
