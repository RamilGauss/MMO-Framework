/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CRC8_H
#define CRC8_H

#include "TypeDef.h"

class SHARE_EI TCRC8
{
  unsigned char mReadyCRC;

public:
  TCRC8();
  ~TCRC8();
  
  unsigned char Calc(void* pIn, int sizeIn);
};


#endif

