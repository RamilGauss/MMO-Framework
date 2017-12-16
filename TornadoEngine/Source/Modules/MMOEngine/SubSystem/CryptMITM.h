/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CryptMITM_H
#define CryptMITM_H

#include "ContainerTypes.h"
#include "BreakPacket.h"

class TCryptMITM
{
  TBreakPacket mResultBP;
public:
  bool Calc(void* rsa, int size_rsa, 
            void* pLogin, int sizeLogin,        
            void* pPassword, int sizePassword, 
            TContainer& c_result);
};

#endif