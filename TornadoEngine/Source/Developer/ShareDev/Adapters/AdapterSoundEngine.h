/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterSoundEngineH
#define AdapterSoundEngineH

#include "PrototypeDev.h"

class DllExport AdapterSoundEngine : public PrototypeDev
{
public:
  AdapterSoundEngine();
  virtual ~AdapterSoundEngine();

  virtual bool Work();
};

#endif
