/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

struct TMemeberTypeExtendedInfo
{
  enum TypeCategory
  {
    BuiltIn, Vector, List, Set, Map, String, Reflection
  };

  TypeCategory mCategory;

  enum AccessMethod
  {
    Object, 
    Pointer, 
    SmartPointer// std::auto_ptr, std::shared_ptr, std::weak_ptr, std::unique
  };

  AccessMethod mAccessMethod;

  std::vector<std::string> mSubtypeArr;// std::vector<subtype>

};