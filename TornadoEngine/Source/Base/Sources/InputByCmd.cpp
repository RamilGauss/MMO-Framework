#include "InputByCmd.h"

void TInputByCmd::Add( std::string& sKey, ParseFunc func )
{
  mKeyFuncMap.insert( TStrParseFuncMap::value_type( sKey, func ) );

  mCmdParam.AddDefKey( sKey );
}
//---------------------------------------------------------------------------------------
void TInputByCmd::SetArg( int argc, char** argv )
{
  std::vector<std::string> vecArgv;
  for( int i = 1; i < argc; i++ )
    vecArgv.push_back( argv[i] );
  SetArg( vecArgv );
}
//---------------------------------------------------------------------------------------
void TInputByCmd::SetArg( std::vector<std::string>& vecArgv )
{
  int count = 0;
  mCmdParam.SetArg( vecArgv );
  for( auto keyFuncPair : mKeyFuncMap )
  {
    auto sKey = keyFuncPair.first;
    if( mCmdParam.GetCountValueByKey( sKey ) == 1 )
    {
      std::string sValue;
      mCmdParam.GetByKey( sKey, 0, sValue );
      keyFuncPair.second( sValue );
    }
  }
}
//---------------------------------------------------------------------------------------
