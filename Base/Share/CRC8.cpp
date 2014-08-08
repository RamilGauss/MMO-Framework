/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CRC8.h"

TCRC8::TCRC8()
{

}
//-------------------------------------------------------------
TCRC8::~TCRC8()
{

}
//-------------------------------------------------------------
unsigned char TCRC8::Calc(void* pIn, int sizeIn)
{
  mReadyCRC = 0;
  unsigned char* pUchar = (unsigned char*)pIn;
  for( int i = 0 ; i < sizeIn ; i++)
    mReadyCRC += pUchar[i];
  return mReadyCRC;
}
//-------------------------------------------------------------
