/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterMMOH
#define AdapterMMOH

#include "PrototypeDev.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include "DstEvent.h"

#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"


#include "Base.h"
#include "INetTransport.h"

class TWrapperMakerTransport;

template <typename T>
class AdapterMMO : public PrototypeDev, public TDstEvent
{
  boost::scoped_ptr<TWrapperMakerTransport> mMakerTransport;
  boost::scoped_ptr<T>                      mPtrMMO;
public:
  AdapterMMO();
  virtual bool Work();
  T* Get();
};
//--------------------------------------------------------------------------------------
template <typename T>
AdapterMMO<T>::AdapterMMO()
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);

  mPtrMMO.reset(new T);
  mMakerTransport.reset(new TWrapperMakerTransport);

  mPtrMMO->Init(mMakerTransport.get());

  mPtrMMO->SetDstObject(this);
  mPtrMMO->SetSelfID(0);
}
//------------------------------------------------------------------------------------
template <typename T>
bool AdapterMMO<T>::Work()
{
  //дать квант времени и транслировать события в игровой движок
  mPtrMMO->Work();
  nsEvent::TEvent* pEvent = GetEvent();
  while(pEvent)
  {
    // трансляция события
    GetSrcEvent()->Translate(pEvent);// полностью доверять это событие дальше
    pEvent = GetEvent();
  }
  return true;
}
//------------------------------------------------------------------------------------
template <typename T>
T* AdapterMMO<T>::Get()
{
  return mPtrMMO.get();
}
//------------------------------------------------------------------------------------

#endif
