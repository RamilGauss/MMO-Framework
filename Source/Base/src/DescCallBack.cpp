/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/DescCallBack.h"

TDescCallBack::TDescCallBack()
{
    mPtrCallBack = nullptr;
}
//-------------------------------------------------------------------------
TDescCallBack::~TDescCallBack()
{

}
//-------------------------------------------------------------------------
void TDescCallBack::Notify()
{
    ((TCallBackRegistrator0*)mPtrCallBack)->Notify();
}
//-------------------------------------------------------------------------
void TDescCallBack::Set(void* pCB)
{
    mPtrCallBack = pCB;
}
//-------------------------------------------------------------------------
