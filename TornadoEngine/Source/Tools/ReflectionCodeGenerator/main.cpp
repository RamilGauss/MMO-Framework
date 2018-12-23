/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
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
#include "CodeGeneratorFactory.h"
#include "fmt/time.h"
#include "fmt/color.h"
#include "MemberTypeExtendedInfoAnalyzer.h"

const std::string _VERSION = "0.2";
const int _COUNTER_BUILD = 3;

using namespace nsReflectionCodeGenerator;
using namespace boost::wave;

void DefaultConfig()
{
  auto config = SingletonManager()->Get<TConfigContainer>()->Config();
  config->targetForParsing.recursive = true;
  config->targetForParsing.directories.push_back(".");

  config->filter.attribute = "REFLECTION_ATTRIBUTE";
  config->filter.extensions.push_back( ".h" );
  config->filter.extensions.push_back( ".hpp" );

  config->targetForCodeGeneration.directory = ".";
  config->targetForCodeGeneration.includeListFileName = "IncludeList";

  config->targetForCodeGeneration.implementation.jsonSerializer.reset( new TJsonSerializerGeneratorConfig() );
  auto jsonSerializer = config->targetForCodeGeneration.implementation.jsonSerializer.get();
  jsonSerializer->className = "TJsonSerializer";
  jsonSerializer->fileName = "JsonSerializer";
  jsonSerializer->nameSpaceName = "nsJson";

  config->targetForCodeGeneration.implementation.binaryMarshaller.reset( new TBinaryMarshallerGeneratorConfig() );
  auto binaryMarshaller = config->targetForCodeGeneration.implementation.binaryMarshaller.get();
  binaryMarshaller->className = "TBinaryMarshaller";
  binaryMarshaller->fileName = "BinaryMarshaller";
  binaryMarshaller->nameSpaceName = "nsBinary";

  binaryMarshaller->deserializationHandler.className = "TDeserializationHandler";
  binaryMarshaller->deserializationHandler.fileName = "DeserializationHandler";
  binaryMarshaller->deserializationHandler.method = "Handle";
  binaryMarshaller->deserializationHandler.nameSpaceName = "nsBinary";
}
//---------------------------------------------------------------------------------------
bool CheckArgs( int argc, char *argv [] )
{
  if( argc == 1 )
    return false;
  return true;
}
//---------------------------------------------------------------------------------------
void ShowManual()
{
  for ( auto key : nsReflectionCodeGenerator::nsManual::g_Manual )
  {
    printf( "%s: \n", key.first.data() );
    for ( auto value : key.second )
    {
      printf( "\t %s\n", value.data() );
    }
  }

  printf( "Press any key for continue...\n" );
}
//---------------------------------------------------------------------------------------
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
using namespace fmt::literals;

class IStringed
{
public:
  virtual std::string ToString() = 0;
};

class TMethodBegin : public IStringed
{
public:
  std::string mReturnedType = "void";
  std::string mNameMethod;
  std::string mEndMethod = ";";

  //std::vector<T>

  virtual std::string ToString() override
  {
    return fmt::format( "{} {}({}){}", mReturnedType, mNameMethod, mEndMethod );
  }

};

void ShowTitle()
{
  fmt::print( "The world needs reflection in C++. I give it. You take it!\n" );
  fmt::print( "ReflectionCodeGenerator version {}.b{}\n", _VERSION, _COUNTER_BUILD );
}

int main( int argc, char *argv [] )
{
  ShowTitle();

  if ( CheckArgs( argc, argv ) == false )
  {
    ShowManual();
    getchar();
    return -1;
  }

  DefaultConfig();

  TParser parser;
  parser.Work();

  // дополнить расширенной информацией
  TMemberTypeExtendedInfoAnalyzer analyzer;
  analyzer.Work();

  //TCodeGeneratorFactory cgFactory;
  //cgFactory.Work();
  return 0;
}