/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <mutex>
#include <condition_variable>
#include <functional>
#include "DataExchange2Thread.h"
#include "ThreadBoost.h"

class DllExport TExecuteInstructionEngine : public TThreadBoost
{
    std::mutex mMutex;
    std::condition_variable mCondVar;
public:
    typedef std::function <void()> InstructionResult;
    typedef std::function <InstructionResult* ()> Instruction;
protected:
    TDataExchange2Thread<Instruction> mConcurrentInstruction;
    TDataExchange2Thread<InstructionResult> mConcurrentInstructionResult;
public:
    void Push(Instruction& instruction);
    void Pop();
protected:
    void Work() override;

    void TrySleep();
    void WakeUp();
};
