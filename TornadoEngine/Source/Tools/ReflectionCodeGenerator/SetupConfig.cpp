/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Requirements.h"
#include "SetupConfig.h"
#include "SingletonManager.h"
#include "Config.h"
#include "fmt/time.h"
#include "fmt/color.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

TSetupConfig::TSetupConfig()
{
  // dirty, but simple
  mArgc = __argc;
  mArgv = __argv;
  mConfigContainer = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>();
}
//---------------------------------------------------------------------------------------------
bool TSetupConfig::Work()
{
  if ( CheckArgs() == false )
  {
    ShowManual();
    return false;
  }

  auto loadResult = TryLoadConfig();
  // debug only
  if ( loadResult == false )
#ifdef _DEBUG
    DefaultConfig();
#else
    return false;
#endif
  ResolvePathes();
  return true;
}
//---------------------------------------------------------------------------------------------
bool TSetupConfig::CheckArgs()
{
  if ( mArgc == 1 )
    return false;
  return true;
}
//---------------------------------------------------------------------------------------
void TSetupConfig::ShowManual()
{
  for ( auto key : nsReflectionCodeGenerator::nsManual::g_Manual )
  {
    fmt::print( "{}:\n", key.first.data() );
    for ( auto value : key.second )
      fmt::print( "\t {}\n", value.data() );
  }

  fmt::print( "Press any key for continue...\n" );
}
//---------------------------------------------------------------------------------------
void TSetupConfig::DefaultConfig()
{
  auto config = mConfigContainer->Config();
  config->targetForParsing.recursive = true;
  config->targetForParsing.directories.push_back( "." );

  config->filter.attribute = "REFLECTION_ATTRIBUTE";
  config->filter.extensions.push_back( ".h" );
  config->filter.extensions.push_back( ".hpp" );

  config->targetForCodeGeneration.directory = ".";
  config->targetForCodeGeneration.includeListFileName = "IncludeList";

  config->targetForCodeGeneration.implementation.jsonSerializer.reset( new nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig() );
  auto jsonSerializer = config->targetForCodeGeneration.implementation.jsonSerializer.get();
  jsonSerializer->className = "TJsonSerializer";
  jsonSerializer->fileName = "JsonSerializer";
  jsonSerializer->nameSpaceName = "nsJson";

  config->targetForCodeGeneration.implementation.binaryMarshaller.reset( new nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig() );
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
bool TSetupConfig::TryLoadConfig()
{
  //TODO: load from json
// TJsonSerializer jsonSerializer;
//jsonSerializer.Load(  );

  return false;
}
//---------------------------------------------------------------------------------------
void TSetupConfig::ResolvePathes()
{
  // save
  auto oldCurrentPath = fs::current_path().string();

  fs::path p( mArgv [0] );
  auto absPathExeDir = p.parent_path();
  fs::current_path( absPathExeDir );

  mPathToJsonFile = fs::path( mArgv [1] ).parent_path().string();
  mAbsPathDirJson = fs::absolute( mPathToJsonFile ).string();

  // all relative config file
  fs::current_path( mAbsPathDirJson );

  auto pConfig = mConfigContainer->Config();
  
  // input
  for( auto& dir : pConfig->targetForParsing.directories )
    dir = fs::absolute( dir ).string();

  // output
  auto& dir = pConfig->targetForCodeGeneration.directory;
  dir = fs::absolute( dir ).string();// i'am lazy :)

  // restore
  fs::current_path( oldCurrentPath );
}
//---------------------------------------------------------------------------------------