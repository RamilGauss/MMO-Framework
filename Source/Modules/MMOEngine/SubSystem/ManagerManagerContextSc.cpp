/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ManagerManagerContextSc.h"

using namespace nsMMOEngine;

TManagerManagerContextSc::TManagerManagerContextSc()
{

}
//-----------------------------------------------------------------------------
TManagerManagerContextSc::~TManagerManagerContextSc()
{
    for (TScContextManager* pMSc : mSetManagerContextSc) {
        delete pMSc;
    }
    mSetManagerContextSc.clear();
}
//-----------------------------------------------------------------------------
TScContextManager* TManagerManagerContextSc::Add()
{
    TScContextManager* pMCSc = new TScContextManager();
    pMCSc->GetCallBackActivate()->Register(&TManagerManagerContextSc::ActiveEvent, this);
    pMCSc->GetCallBackDisactivate()->Register(&TManagerManagerContextSc::DisactiveEvent, this);
    mSetManagerContextSc.insert(pMCSc);
    return pMCSc;
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::Remove(TScContextManager* pMCSc)
{
    mSetManagerContextSc.erase(pMCSc);
    mSetActiveManagerContextSc.erase(pMCSc);
    delete pMCSc;
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::Work()
{
    TSetPtr copySetActiveManagerContextSc = mSetActiveManagerContextSc;
    for (TScContextManager* pMSc : copySetActiveManagerContextSc)
        pMSc->Work();// работает только активный сценарий
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::ActiveEvent(TScContextManager* pMCSc)
{
    mSetActiveManagerContextSc.insert(pMCSc);
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::DisactiveEvent(TScContextManager* pMCSc)
{
    if (pMCSc->IsActive() == false)
        mSetActiveManagerContextSc.erase(pMCSc);
}
//-----------------------------------------------------------------------------
