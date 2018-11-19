/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputCmdReflectionCodeGenerator.h"
#include <boost/lexical_cast.hpp>

std::string KEY_SOURCE( "src" );
std::string KEY_DESTINATION( "dst" );
//std::string KEY_SOURCE( "dstClassName" );

void TInputCmdReflectionCodeGenerator::Init()
{
  //Add( KEY_LIB, [&mInput = mInput]( std::string& sValue )
  //{
  //  mInput.libName = sValue.data();
  //} );

  //Add( KEY_VARIANT, [&mInput = mInput]( std::string& sValue )
  //{
  //  mInput.variant_use = boost::lexical_cast<int>(sValue.data());
  //} );

  //Add( KEY_PARAM, [&mInput = mInput, &mCmdParam = mCmdParam]( std::string& sValue )
  //{
  //  int cP = mCmdParam.GetCountValueByKey( KEY_PARAM );
  //  for( int i = 0; i < cP; i++ )
  //  {
  //    std::string sParam;
  //    mCmdParam.GetByKey( KEY_PARAM, i, sParam );
  //    mInput.param.push_back( sParam );
  //  }
  //} );

  //Add( KEY_CONSOLE, [&mInput = mInput]( std::string& sValue )
  //{
  //  mInput.useConsole = true;
  //} );
}
//-------------------------------------------------------------------------------
