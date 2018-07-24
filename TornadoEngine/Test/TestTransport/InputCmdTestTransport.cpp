/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestTransport.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

using namespace std;

string KEY_SUB_NET( "sub_net" );
string KEY_SELF_PORT( "self_port" );
string KEY_PING_DATA( "ping_data" );
string KEY_PING_TIME( "ping_time" );
string KEY_SERVER_IP( "server_ip" );
string KEY_SERVER_PORT( "server_port" );

TInputCmdTestTransport::TInputCmdTestTransport()
{
  mVecDefKey.push_back( KEY_SUB_NET );
  mVecDefKey.push_back( KEY_SELF_PORT );
  mVecDefKey.push_back( KEY_PING_DATA );
  mVecDefKey.push_back( KEY_PING_TIME );
  mVecDefKey.push_back( KEY_SERVER_IP );
  mVecDefKey.push_back( KEY_SERVER_PORT );

  mCmdParam.SetDefKey( mVecDefKey );
}
//-------------------------------------------------------------------------------
TInputCmdTestTransport::~TInputCmdTestTransport()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdTestTransport::SetArg( int argc, char** argv )
{
  vector<string> vecArgv;
  for( int i = 1; i < argc; i++ )
    vecArgv.push_back( argv[i] );
  return SetArg( vecArgv );
}
//-------------------------------------------------------------------------------
bool TInputCmdTestTransport::SetArg( vector<string>& vecArgv )
{
  mCmdParam.SetArg( vecArgv );

   if( mCmdParam.GetCountValueByKey( KEY_SUB_NET ) == 1 )
    {
      string sSubNet;
      mCmdParam.GetByKey( KEY_SUB_NET, 0, sSubNet );
      mInput.sub_net = boost::lexical_cast<int>(sSubNet.data());
    }
  if( mCmdParam.GetCountValueByKey( KEY_SELF_PORT ) == 1 )
  {
    string sSelfPort;
    mCmdParam.GetByKey( KEY_SELF_PORT, 0, sSelfPort );
    mInput.self_port = boost::lexical_cast<int>(sSelfPort.data());
  }
  if( mCmdParam.GetCountValueByKey( KEY_SERVER_PORT ) == 1 )
  {
    string sServerPort;
    mCmdParam.GetByKey( KEY_SERVER_PORT, 0, sServerPort );
    mInput.server_port = boost::lexical_cast<int>(sServerPort.data());
  }
  if( mCmdParam.GetCountValueByKey( KEY_PING_TIME ) == 1 )
  {
    string sPingTime;
    mCmdParam.GetByKey( KEY_PING_TIME, 0, sPingTime );
    mInput.ping_time = boost::lexical_cast<int>(sPingTime.data());
  }
  if( mCmdParam.GetCountValueByKey( KEY_PING_DATA ) == 1 )
  {
    string sPingData;
    mCmdParam.GetByKey( KEY_PING_DATA, 0, sPingData );
    mInput.ping_data = sPingData;
  }
  if( mCmdParam.GetCountValueByKey( KEY_SERVER_IP ) == 1 )
  {
    string sServerIP;
    mCmdParam.GetByKey( KEY_SERVER_IP, 0, sServerIP );
    mInput.server_ip = boost::asio::ip::address_v4::from_string( sServerIP ).to_ulong();
  }
  return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestTransport::Get( TInputCmdTestTransport::TInput& v_out )
{
  v_out = mInput;
}
//-------------------------------------------------------------------------------
