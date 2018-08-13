/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <functional>
#include "DataExchange2Thread.h"
#include "ThreadBoost.h"

class DllExport TExecuteInstructionEngine : public TThreadBoost
{
  typedef std::function<void()> TInstruction;

  TDataExchange2Thread<TInstruction> mConcurrentInstruction;

  bool mOtherThread;
public:
  TExecuteInstructionEngine( bool otherThread = true );
  void Execute( TInstruction& instruction );
protected:
  void Work() override;
};
