/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ConverterErrorH
#define ConverterErrorH

#include "PrototypeMMOEnum.h"
#include "EnumMMO.h"

class TConverterError
{
public:
  TConverterError();
  virtual ~TConverterError();

  tPrototypeMMOErrorCode Work(nsMMOEngine::ErrorCode error);
};

#endif
