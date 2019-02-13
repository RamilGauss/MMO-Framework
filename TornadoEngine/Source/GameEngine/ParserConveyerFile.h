/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include "ConveyerConfig.h"

class TParserConveyerFile
{
  std::string strError;

  TConveyerConfig mConveyerConfig;
public:
  bool Work( std::string& fileDescConveyer );
  std::string GetStrError();
  std::vector<std::string> GetResult( std::string& variantConveyer );
};
