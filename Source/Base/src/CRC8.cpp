/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
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
void TCRC8::Calc(void* pIn, int sizeIn, unsigned char& crc)
{
    crc = 0;
    unsigned char* pUchar = (unsigned char*)pIn;
    for (int i = 0; i < sizeIn; i++) {
        crc += pUchar[i];
    }
}
//-------------------------------------------------------------
