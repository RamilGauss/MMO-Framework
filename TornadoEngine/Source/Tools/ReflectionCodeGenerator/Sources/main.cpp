/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SingletonManager.h"
#include "Config.h"
#include "TokenInfoManager.h"
#include "TokenInfo.h"
#include "Parser.h"
#include "ConfigContainer.h"
#include "Requirements.h"
#include "readerwriterqueue.h"
#include "TypeManager.h"
#include "CodeGeneratorFusion.h"
#include "fmt/core.h"
#include "MemberTypeExtendedInfoAnalyzer.h"
#include "SetupConfig.h"
#include "ProgramInfo.h"

#include "HiTimer.h"
#include "TestClass.h"

#include "DstEvent.h"


#include <iostream>
#include <string>
#include <cstdlib>
#include <fmt/core.h>
#include <fmt/format.h>
//#include <fmt/time.h>
#include <fmt/color.h>
#include <fmt/printf.h>

using namespace nsReflectionCodeGenerator;
using namespace boost::wave;

using namespace moodycamel;
void TestQueue()
{
  ReaderWriterQueue<int> q( 100 );       // Reserve space for at least 100 elements up front

  q.enqueue( 17 );                       // Will allocate memory if the queue is full
  bool succeeded = q.try_enqueue( 18 );  // Will only succeed if the queue has an empty slot (never allocates)
  assert( succeeded );

  int number;
  succeeded = q.try_dequeue( number );  // Returns false if the queue was empty

  assert( succeeded && number == 17 );

  // You can also peek at the front item of the queue (consumer only)
  int* front = q.peek();
  assert( *front == 18 );
  succeeded = q.try_dequeue( number );
  assert( succeeded && number == 18 );
  front = q.peek();
  assert( front == nullptr );           // Returns nullptr if the queue was empty
}
//---------------------------------------------------------------------------------------
void ShowTitle()
{
  fmt::print( "The world needs reflection for C++. I give it. You take it!\n" );
  fmt::print( "{} version {} build {}\n", nsProgramInfo::NAME, nsProgramInfo::VERSION, nsProgramInfo::COUNTER_BUILD );
}
//---------------------------------------------------------------------------------------
int main( int argc, char *argv[] )
{
  ShowTitle();

  TSetupConfig setupConfig;
  if ( setupConfig.Work() == false )
    return 0;

  TParser parser;
  parser.Work();

  // дополнить расширенной информацией
  TMemberTypeExtendedInfoAnalyzer analyzer;
  analyzer.Work();

  TCodeGeneratorFusion cgFusion;
  cgFusion.Work();
  return 0;
}
