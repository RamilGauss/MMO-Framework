/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestMMO_Server.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

using namespace std;

string KEY_SUB_NET( "subnet" );

TInputCmdTestMMO_Server::TInputCmdTestMMO_Server()
{
  mVecDefKey.push_back( KEY_SUB_NET );

  mCmdParam.SetDefKey( mVecDefKey );
}
//-------------------------------------------------------------------------------
TInputCmdTestMMO_Server::~TInputCmdTestMMO_Server()
{

}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO_Server::SetArg( int argc, char** argv )
{
  vector<string> vecArgv;
  for( int i = 1; i < argc; i++ )
    vecArgv.push_back( argv[i] );
  return SetArg( vecArgv );
}
//-------------------------------------------------------------------------------
bool TInputCmdTestMMO_Server::SetArg( vector<string>& vecArgv )
{
  mCmdParam.SetArg( vecArgv );

  int cSN = mCmdParam.GetCountValueByKey( KEY_SUB_NET );
  if( cSN == 1 )
  {
    string sSubnet;
    mCmdParam.GetByKey( KEY_SUB_NET, 0, sSubnet );
    mInput.subnet = boost::lexical_cast<int>(sSubnet.data());
  }
  return true;
}
//-------------------------------------------------------------------------------
void TInputCmdTestMMO_Server::Get( TInputCmdTestMMO_Server::TInput& v_out )
{
  v_out = mInput;
}
//-------------------------------------------------------------------------------
