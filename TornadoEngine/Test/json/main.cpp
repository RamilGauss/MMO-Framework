/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonManager.h"
#include "TypeDef.h"

#include "meta.hpp"
#include "factory.hpp"

#ifdef WIN32
#pragma pack(push, 1)
#endif
class TServerConfig
{
public:
  //std::string    password;
  unsigned short port = 0;
  unsigned int   id = 0;

  TServerConfig()
  {
  }
}_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif

int main( int argc, char **argv )
{
  auto factory = meta::reflect<TServerConfig>().ctor();
  auto obj = meta::resolve<TServerConfig>().ctor().invoke();
  auto data = obj.data();


  TServerConfig serverConfig;

  TJsonManager jsonMng;
  std::string path = "d:\\Projects\\MMO\\MMOFramework\\TornadoEngine\\Test\\json\\serverConfig.json";
  jsonMng.Load( path, serverConfig );
  return 0;
}