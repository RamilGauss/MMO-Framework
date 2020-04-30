/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITable.h"
#include <string>

#pragma REFLECTION_ATTRIBUTE
#pragma Table
class Channel : public ITable
{
public:
#pragma Index
  std::string dog_link;
};