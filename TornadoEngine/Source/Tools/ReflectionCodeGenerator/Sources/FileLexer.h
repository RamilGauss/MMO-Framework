/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "StateMachine.h"
#include "ConfigContainer.h"
#include "TokenInfoManager.h"
#include "AST_StateMachine.h"

class TTokenInfoManager;
class TTypeManager;

class TFileLexer
{
  TTokenInfoManager* mTokenMng;
  TTypeManager* mTypeMng;
  nsReflectionCodeGenerator::TConfig* mConfig;

  // поиск по файлу и связанными с ним токенами
  std::string mCurrentFile;

public:
  TFileLexer();

  void Work();
private:

  // state machine functions
  TTokenInfoManager::TTokenInfoList* SelectFile();
};
