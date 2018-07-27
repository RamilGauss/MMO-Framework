/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestMMO_ClusterMonitor.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

std::string KEY_LOGIN( "login" );
std::string KEY_SUB_NET( "subnet" );
std::string KEY_PASSWORD( "password" );
std::string KEY_SELF_PORT( "self_port" );
std::string KEY_SERVER_IP( "server_ip" );
std::string KEY_SERVER_PORT( "server_port" );

void TInputCmdTestMMO_ClusterMonitor::Init()
{
  Add( KEY_LOGIN, [&mInput = mInput]( std::string& sValue )
  {
    mInput.login = sValue;
  } );
  Add( KEY_PASSWORD, [&mInput = mInput]( std::string& sValue )
  {
    mInput.password = sValue;
  } );
  Add( KEY_SUB_NET, [&mInput = mInput]( std::string& sValue )
  {
    mInput.subnet = boost::lexical_cast<int>(sValue.data());
  } );
  Add( KEY_SERVER_PORT, [&mInput = mInput]( std::string& sValue )
  {
    mInput.server_port = boost::lexical_cast<int>(sValue.data());
  } );
  Add( KEY_SERVER_IP, [&mInput = mInput]( std::string& sValue )
  {
    mInput.server_ip = sValue;
  } );
  Add( KEY_SELF_PORT, [&mInput = mInput]( std::string& sValue )
  {
    mInput.self_port = boost::lexical_cast<int>(sValue.data());
  } );
}
//------------------------------------------------------------------------------------------------
