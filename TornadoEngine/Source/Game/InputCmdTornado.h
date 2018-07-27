/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "InputByCmd.h"
 
class TInputCmdTornado : public TInputByCmd
{
public:

  struct TInput
  {
    std::string              libName;
    std::vector<std::string> param;
    int                      variant_use = 0;
    bool                     useConsole = false;
  };

  TInput mInput;

  void Init() override;
};
