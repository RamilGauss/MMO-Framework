/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputCmdDevTool.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include <boost/lexical_cast.hpp>

std::string KEY_DST_IP( "dst_ip" );
std::string KEY_DST_PORT( "dst_port" );
std::string KEY_SELF_PORT( "self_port" );

void TInputCmdDevTool::Init()
{
  Add( KEY_DST_IP, [&mInput = mInput]( std::string& sValue )
  {
    mInput.dst_ip = boost::asio::ip::address_v4::from_string( sValue.data() ).to_ulong();
  } );

  Add( KEY_DST_PORT, [&mInput = mInput]( std::string& sValue )
  {
    mInput.dst_port = boost::lexical_cast<int>( sValue.data() );
  } );

  Add( KEY_SELF_PORT, [&mInput = mInput]( std::string& sValue )
  {
    mInput.self_port = boost::lexical_cast<int>(sValue.data());
  } );
}
//-------------------------------------------------------------------------------
