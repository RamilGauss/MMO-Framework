/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "LoadFromFile.h"
#include "SaveToFile.h"

class DllExport TTextFile
{
  std::string mPath;

  TLoadFromFile mLoader;
  TSaveToFile mSaver;
public:
  TTextFile( std::string& path );

  void Load( std::string& str );
  void Save( std::string& str, bool append = false );

  static void Load( std::string& path, std::string& str );
  static void Save( std::string& path, std::string& str, bool append = false );
};