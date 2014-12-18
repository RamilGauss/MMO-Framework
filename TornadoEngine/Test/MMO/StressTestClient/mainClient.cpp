/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScenarioStressTestClient.h"

int main(int argc, char** argv)
{
  TScenarioStressTestClient scTest;
  scTest.Init(argc, argv);
  scTest.Work();
  return 0;
}
//-----------------------------------------------------------------------
