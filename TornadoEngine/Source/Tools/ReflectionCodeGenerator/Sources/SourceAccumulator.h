/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <list>

class TSourceAccumulator
{
  const char* HEADER =
    "/*"
    "Author: Gudakov Ramil Sergeevich a.k.a.Gauss"
    "Гудаков Рамиль Сергеевич"
    "Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]"
    "See for more information License.h."
    "*/";

  const char* GENERATED_INFO = "Reflection code generator\n Generated file at:";

  std::list<std::string> mPartList;

public:
  TSourceAccumulator();
  ~TSourceAccumulator();

  // чистка перед использованием
  void Clear();

  // вставка
  void Add( const char* p, bool back = true );
  void Add( std::string& str, bool back = true );

  // слить на жесктий
  void Flush( std::string& absFileName );
private:
  void AddGeneratedInfo();
  void AddHeader();
};

