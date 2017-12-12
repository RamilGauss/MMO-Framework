/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Synchronizer_ModelH
#define Synchronizer_ModelH

#include "TypeDef.h"

#include "Operation_Model.h"

class DllExport TSynchronizer_Model : public TOperation_Model
{
public:
  TSynchronizer_Model();

  virtual void Synchro();
private:
};

#endif
