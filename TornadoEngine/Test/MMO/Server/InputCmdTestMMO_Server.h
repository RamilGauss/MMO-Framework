/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "InputByCmd.h"

class TInputCmdTestMMO_Server : public TInputByCmd
{
public:

  struct TInput
  {
    unsigned char subnet = 0;
  };

  TInput mInput;

  void Init() override;
};
