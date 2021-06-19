/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef Synchronizer_Model_LogicH
#define Synchronizer_Model_LogicH

#include "TypeDef.h"

#include "Synchronizer_Model.h"

class DllExport TSynchronizer_Model_Logic : public TSynchronizer_Model
{
public:
  TSynchronizer_Model_Logic();

  virtual void Synchro();
private:
};

#endif
