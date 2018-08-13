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

void TInputCmdTestMMO_Server::Init()
{
  Add( KEY_SUB_NET, [&mInput = mInput]( std::string& sValue )
  {
    mInput.subnet = boost::lexical_cast<int>(sValue.data());
  } );
}
//-------------------------------------------------------------------------------
