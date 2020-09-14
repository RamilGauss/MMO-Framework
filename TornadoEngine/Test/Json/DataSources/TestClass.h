/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TestStruct.h"
#include "VectorStatic.h"

struct TestClass
{
    int8_t i8;
    uint8_t ui8;
    int16_t i16;
    uint16_t ui16;
    int32_t i32;
    uint32_t ui32;

    char c;
    unsigned char uc;
    short s;
    unsigned short us;
    int i;
    unsigned int ui;

    float f;
    double d;

    VectorStatic<int, 10> myarray;

    bool operator == (const TestClass& other)
    {
        return myarray == other.myarray;
    }
};
