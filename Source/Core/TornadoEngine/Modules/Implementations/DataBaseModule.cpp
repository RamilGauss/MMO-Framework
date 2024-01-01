/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DataBaseModule.h"
#include "Base/Common/HiTimer.h"

using namespace nsTornadoEngine;

TDataBaseModule::TDataBaseModule()
{

}
//----------------------------------------------------------------------
TDataBaseModule::~TDataBaseModule()
{

}
//----------------------------------------------------------------------
void TDataBaseModule::ModuleWork()
{
    //ht_msleep(20);//###
}
//----------------------------------------------------------------------
bool TDataBaseModule::ModuleStartEvent()
{
    return true;
}
//----------------------------------------------------------------------
void TDataBaseModule::StopEvent()
{
}
//----------------------------------------------------------------------
