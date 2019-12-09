/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ConfigContainer.h"

class TSetupConfig
{
  nsReflectionCodeGenerator::TConfigContainer* mConfigContainer;

  int mArgc;
  char** mArgv;

  std::string mPathToJsonFile;// abs or rel
  std::string mAbsPathDirJson;
  std::string mAbsPathJsonFile;

public:
  TSetupConfig();

  bool Work();

protected:
  bool CheckArgs();
  void ShowManual();
  void DefaultConfig();
private:
  bool TryLoadConfig();
  void ResolvePathes();

  void ResolveJsonPath();
};

