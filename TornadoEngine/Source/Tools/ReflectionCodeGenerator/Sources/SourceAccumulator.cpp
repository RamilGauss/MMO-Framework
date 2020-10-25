/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "SourceAccumulator.h"
#include "SaveToFile.h"
#include "BL_Debug.h"

#include <ctime>
#include <iostream>
#include <locale>

TSourceAccumulator::TSourceAccumulator()
{
}
//---------------------------------------------------------------------------------------------
TSourceAccumulator::~TSourceAccumulator()
{
}
//---------------------------------------------------------------------------------------------
void TSourceAccumulator::Clear()
{
    mPartList.clear();
}
//---------------------------------------------------------------------------------------------
void TSourceAccumulator::Add(const char* p, bool back)
{
    auto s = (std::string)p;
    Add(s);
}
//---------------------------------------------------------------------------------------------
void TSourceAccumulator::Add(std::string& str, bool back)
{
    if ( back ) {
        mPartList.push_back(str);
    } else {
        mPartList.push_front(str);
    }
}
//---------------------------------------------------------------------------------------------
void TSourceAccumulator::Flush(std::string& absFileName)
{
    AddHeader();
    AddGeneratedInfo();

    TSaveToFile stf;
    auto openResult = stf.ReOpen(absFileName.data());
    BL_ASSERT(openResult);

    for ( auto& part : mPartList ) {
        stf.Write(part.data(), part.length());
    }
}
//---------------------------------------------------------------------------------------------
void TSourceAccumulator::AddGeneratedInfo()
{
    std::locale::global(std::locale("ru_RU.utf8"));
    std::time_t t = std::time(nullptr);
    char mbstr[100];
    if ( std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&t)) ) {
        Add(&mbstr[0], false);
    }

    Add(GENERATED_INFO, false);
}
//---------------------------------------------------------------------------------------------
void TSourceAccumulator::AddHeader()
{
    Add(HEADER, false);
}
//---------------------------------------------------------------------------------------------