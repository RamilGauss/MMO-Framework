/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PCS_IHandlerH
#define PCS_IHandlerH

class PCS_IHandler
{
public:
  PCS_IHandler();
  virtual ~PCS_IHandler() = 0;

  virtual void Recv(TBasePacket_PCS* p);
  void Send(TBasePacket_PCS* p);
};
#endif