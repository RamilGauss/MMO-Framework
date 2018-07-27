/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "InputByCmd.h"

class DllExport TInputCmdDevTool : public TInputByCmd
{
public:
  struct TInput
  {
    unsigned int   dst_ip;
    unsigned short dst_port;
    unsigned short self_port;
  };
  TInput mInput;

  void Init() override;
};
