/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetWorkThreadH
#define NetWorkThreadH

#include <boost/asio/io_service.hpp>
#include "ThreadBoost.h"

class TNetWorkThread : public TThreadBoost
{
  boost::asio::io_service mIO_Service;

public:
  TNetWorkThread();
  virtual ~TNetWorkThread();

  boost::asio::io_service* GetIO_Service(){return &mIO_Service;}

  virtual void Stop();
protected:
  virtual void Work();
};


#endif