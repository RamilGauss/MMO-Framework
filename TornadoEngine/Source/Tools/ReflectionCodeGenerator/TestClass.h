#pragma once

#include "ReflectionMacro.h"

namespace nsTest0
{
  namespace nsTest1
  {
    /*comments*/
    REFLECTION_ATTRIBUTE
      struct TestClass
    {
      int mA;// other comment
      int mB;
    };
  }
}