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

string KEY_SUB_NET( "subnet" );
string CLIENT_COUNT( "client_count" );
string PACKET_SIZE( "packet_size" );

TInputCmdTestTransport::TInputCmdTestTransport()
{
  mVecDefKey.push_back( KEY_SUB_NET );
  mVecDefKey.push_back( CLIENT_COUNT );
  mVecDefKey.push_back( PACKET_SIZE );

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
  for ( int i = 1; i < argc; i++ )
    vecArgv.push_back( argv[i] );
  return SetArg( vecArgv );
}
//-------------------------------------------------------------------------------
bool TInputCmdTestTransport::SetArg( vector<string>& vecArgv )
{
  mCmdParam.SetArg( vecArgv );

  if ( mCmdParam.GetCountValueByKey( KEY_SUB_NET ) == 1 )
  {
    string sSubNet;
    mCmdParam.GetByKey( KEY_SUB_NET, 0, sSubNet );
    mInput.sub_net = boost::lexical_cast<int>( sSubNet.data() );
  }
  if ( mCmdParam.GetCountValueByKey( CLIENT_COUNT ) == 1 )
  {
    string sClientCount;
    mCmdParam.GetByKey( CLIENT_COUNT, 0, sClientCount );
    mInput.client_count = boost::lexical_cast<int>( sClientCount.data() );
  }
  if ( mCmdParam.GetCountValueByKey( PACKET_SIZE ) == 1 )
  {
    string sPacketSize;
    mCmdParam.GetByKey( PACKET_SIZE, 0, sPacketSize );
    mInput.packet_size = boost::lexical_cast<int>( sPacketSize.data() );
  }
  return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestTransport::Get( TInputCmdTestTransport::TInput& v_out )
{
  v_out = mInput;
}
//-------------------------------------------------------------------------------
