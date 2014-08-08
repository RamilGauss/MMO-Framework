/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetWorkThreadH
#define NetWorkThreadH

#include <boost/asio/io_service.hpp>

class TNetWorkThread
{
  volatile bool flgActive;
  volatile bool flgNeedStop;

  enum
  {
    eWaitFeedBack = 50, // ждать пока активизируется двигатель, мс
  };

  boost::asio::io_service mIO_Service;

public:
	TNetWorkThread();
	virtual ~TNetWorkThread();

  void Start(); // blocking
  void Stop();  // blocking
  bool IsActive(){return flgActive;}

  boost::asio::io_service* GetIO_Service(){return &mIO_Service;}

protected:
  void Engine();
  void Done();
};


#endif