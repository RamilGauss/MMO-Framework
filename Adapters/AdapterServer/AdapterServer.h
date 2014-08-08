/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterServerH
#define AdapterServerH

#include "PrototypeServer.h"

class DllExport AdapterServer : public PrototypeServer
{
public:

  AdapterServer();
  virtual ~AdapterServer();

  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);

  virtual int GetVersionAdapter();

  virtual bool Work();
};

#endif
