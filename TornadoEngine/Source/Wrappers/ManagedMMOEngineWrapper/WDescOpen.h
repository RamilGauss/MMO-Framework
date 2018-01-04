/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WrapperMMOEngineDescOpenH
#define WrapperMMOEngineDescOpenH

namespace WrapperMMOEngine
{
  public ref class WDescOpen
  {
  public:
    unsigned short port;
    unsigned char  subNet;
    WDescOpen();
    WDescOpen(unsigned short p, unsigned char  sN );
  };
}

#endif
