/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>
#include <functional>
#include "LoadFromFile.h"
#include "json11.h"
#include "SingletonManager.h"

class DllExport TJsonManager
{
  TLoadFromFile mLoader;

  typedef std::map<std::string, std::function<void( double /*num*/, char*/*pObj*/, int&/*offset*/ )>> TStrFuncMap;
  static inline TStrFuncMap* g_TypeNameFuncMap = nullptr;
public:
  TJsonManager();

  template<typename Type>
  bool Load( std::string& jsonPath, Type& obj )
  {
    char* pObj = (char*) &obj;
    if( mLoader.ReOpen( (char*) jsonPath.data() ) == false )
      return false;

    TContainer c;
    mLoader.ReadSmall( c );
    std::string jsonData( c.GetPtr(), c.GetSize() );

    std::string err;
    auto json = json11::Json::parse( jsonData, err );
    if( err.size() > 0 )
      return false;

    int offset = 0;
    Push( json, pObj, offset );
    return true;
  }
private:
  void Push( json11::Json& json, char* pObj, int& offset );
};
