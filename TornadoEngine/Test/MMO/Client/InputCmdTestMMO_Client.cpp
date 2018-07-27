/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdTestMMO_Client.h"

#include <stdlib.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>

std::string KEY_COUNT( "count" );
std::string KEY_SUB_NET( "subnet" );
std::string KEY_BEGIN_ID( "begin_id" );
std::string KEY_SERVER_IP( "server_ip" );
std::string KEY_PING_TIME( "ping_time" );
std::string KEY_BEGIN_PORT( "begin_port" );

void TInputCmdTestMMO_Client::Init()
{
  Add( KEY_COUNT, [&mInput = mInput]( std::string& sValue )
  {
    mInput.count = boost::lexical_cast<int>(sValue.data());
  } );
  Add( KEY_SUB_NET, [&mInput = mInput]( std::string& sValue )
  {
    mInput.subnet = boost::lexical_cast<int>(sValue.data());
  } );
  Add( KEY_BEGIN_ID, [&mInput = mInput]( std::string& sValue )
  {
    mInput.begin_id = boost::lexical_cast<int>(sValue.data());
  } );
  Add( KEY_SERVER_IP, [&mInput = mInput]( std::string& sValue )
  {
    mInput.server_ip = sValue;
  } );
  Add( KEY_PING_TIME, [&mInput = mInput]( std::string& sValue )
  {
    mInput.ping_time = boost::lexical_cast<int>(sValue.data());
  } );
  Add( KEY_BEGIN_PORT, [&mInput = mInput]( std::string& sValue )
  {
    mInput.begin_port = boost::lexical_cast<int>(sValue.data());
  } );
}
//-------------------------------------------------------------------------------
