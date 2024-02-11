/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/ExecuteInstructionEngine.h"

namespace nsBase::nsCommon
{
    void TExecuteInstructionEngine::Push(Instruction& instruction)
    {
        Instruction* pInstruction = new Instruction();
        *pInstruction = instruction;

        mConcurrentInstruction.Add(pInstruction);
        // try wake up thread
        WakeUp();
    }
    //------------------------------------------------------------------------------------------------------
    void TExecuteInstructionEngine::Pop()
    {
        auto pp = mConcurrentInstructionResult.GetFirst();
        while (pp) {
            auto p = *pp;
            (*p)();
            //delete p;
            // next
            mConcurrentInstructionResult.RemoveFirst();
            pp = mConcurrentInstructionResult.GetFirst();
        }
    }
    //------------------------------------------------------------------------------------------------------
    void TExecuteInstructionEngine::Work()
    {
        auto pp = mConcurrentInstruction.GetFirst();
        while (pp) {
            auto p = *pp;
            if (p) {
                auto result = (*p)();
                if (result)
                    mConcurrentInstructionResult.Add(result);
            }
            // next
            mConcurrentInstruction.RemoveFirst();
            pp = mConcurrentInstruction.GetFirst();
        }

        // try sleep thread
        TrySleep();
    }
    //------------------------------------------------------------------------------------------------------
    void TExecuteInstructionEngine::TrySleep()
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mCondVar.wait(lock);
    }
    //------------------------------------------------------------------------------------------------------
    void TExecuteInstructionEngine::WakeUp()
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mCondVar.notify_all();
    }
    //------------------------------------------------------------------------------------------------------
}