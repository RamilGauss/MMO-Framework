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

#include "Base/Common/DataExchange2Thread.h"
#include "Base/Common/FramedThread.h"

namespace nsBase::nsCommon
{
    class DllExport TExecuteInstructionEngine
    {
        TFramedThread mThread;// TODO: доделать класс для использования. Пока не продуман механизм. Нет идеалогии.
        // В каком потоке будет вызвано возврат результатов.

        std::mutex mMutex;
        std::condition_variable mCondVar;
    public:
        using InstructionResult = std::function<void()>;
        using Instruction = std::function<InstructionResult* ()>;
    protected:
        TDataExchange2Thread<Instruction> mConcurrentInstruction;
        TDataExchange2Thread<InstructionResult> mConcurrentInstructionResult;
    public:
        void Push(Instruction& instruction);
        void Pop();
    protected:
        void Work();

        void TrySleep();
        void WakeUp();
    };
}
