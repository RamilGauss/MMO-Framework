/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ExecuteInstructionEngine.h"

TExecuteInstructionEngine::TExecuteInstructionEngine( bool otherThread )
{
  mOtherThread = otherThread;
  if( mOtherThread )
    Start();
}
//------------------------------------------------------------------------------------------------------
void TExecuteInstructionEngine::Execute( TInstruction& instruction )
{
  if( mOtherThread )
    mConcurrentInstruction.Add( &instruction );
  else
    instruction();
}
//------------------------------------------------------------------------------------------------------
void TExecuteInstructionEngine::Work()
{
  auto pp = mConcurrentInstruction.GetFirst();
  while( pp )
  {
    auto p = *pp;
    (*p)();
    mConcurrentInstruction.RemoveFirst();

    pp = mConcurrentInstruction.GetFirst();
  }
}
//------------------------------------------------------------------------------------------------------
