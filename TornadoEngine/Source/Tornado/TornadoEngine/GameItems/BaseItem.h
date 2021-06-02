/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "TypeDef.h"
#include "FactoryGameItem.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

//#pragma REFLECTION_ATTRIBUTE
struct DllExport TBaseItem
{
  std::string mName;
  int mType;

  TBaseItem( std::string& name, int type );
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif
