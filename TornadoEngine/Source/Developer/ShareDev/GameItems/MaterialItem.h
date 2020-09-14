/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "BaseItem.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

//#pragma REFLECTION_ATTRIBUTE
struct DllExport TMaterialItem : public TBaseItem
{
//#pragma REFLECTION_ATTRIBUTE
  struct DllExport TVariant
  {
    std::string ogreMaterial;
    // размеры текстуры для воссоздания внешнего вида
    float width; 
    float length;

    std::string color;
    std::string normal;
  };
  typedef std::vector<TVariant> TVecVariant;

//#pragma REFLECTION_ATTRIBUTE
  struct DllExport TPhysic
  {
    float density;
    float elasticity;
    float friction;
  };
  TVecVariant mGraphic;
  TPhysic mPhysic;

  TMaterialItem(std::string& name);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

