/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_TypeScenarioH
#define GP_TypeScenarioH

namespace nsGameProcess
{
  typedef enum
  {
    eUndef   = 0,
    eBuilder,
    eDestructor, 
    eSynchro, 
  }GP_TypeScenario;
}

#endif
