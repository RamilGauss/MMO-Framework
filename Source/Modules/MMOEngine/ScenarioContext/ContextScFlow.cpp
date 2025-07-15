/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/BL_Debug.h"
#include "MMOEngine/ScenarioContext/ContextScFlow.h"
#include "MMOEngine/SubSystem/SessionManager.h"

using namespace nsMMOEngine;

void TContextScFlow::Send(TBreakPacket& bp, bool check)
{
    GetMS()->Send(GetSessionID(), bp, check);
}
//------------------------------------------------------------
void TContextScFlow::SaveBreakPacket(TBreakPacket& bp, bool check)
{
    auto pDescSP = mSavePacketMemoryPool->Pop(1);
    auto pSP = pDescSP->p;

    // собрать пакет
    bp.CopyInBuffer(pSP->c);
    pSP->check = check;
    mListSave.push_back(pDescSP);
}
//-------------------------------------------------------------------------
void TContextScFlow::SendAndRemoveFirst()
{
    if (mListSave.size() == 0) {
        // не ожидали
        BL_FIX_BUG();
        return;
    }

    auto pDescSP = mListSave.front();
    mListSave.pop_front();

    mBP.Reset();
    auto pSP = pDescSP->p;
    mBP.PushFront(pSP->c.GetPtr(), pSP->c.GetSize());
    Send(mBP, pSP->check);

    mSavePacketMemoryPool->Push(pDescSP);
}
//-------------------------------------------------------------------------
