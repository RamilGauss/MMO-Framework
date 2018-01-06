/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleMMOEngineH
#define ModuleMMOEngineH

#include "ModuleComponent.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

#include "SrcEvent_ex.h"

#include "Base.h"
#include "INetTransport.h"
#include "MakerNetTransport.h"

template <typename T>
class DllExport TModuleMMOEngine : public TModuleComponent
{
  boost::scoped_ptr<TMakerNetTransport> mMakerTransport;
  boost::scoped_ptr<T>                  mPtrMMO;
public:
  TModuleMMOEngine();
  virtual void StartEvent();
  virtual bool WorkInherit();
  virtual void StopEvent();

  T* Get();
};
//--------------------------------------------------------------------------------------
template <typename T>
TModuleMMOEngine<T>::TModuleMMOEngine()
{

}
//--------------------------------------------------------------------------------------
template <typename T>
void TModuleMMOEngine<T>::StartEvent()
{
  mPtrMMO.reset(new T);
  mMakerTransport.reset(new TMakerNetTransport);

  mPtrMMO->Init(mMakerTransport.get());

  mPtrMMO->SetDstObject(this);
  mPtrMMO->SetSelfID(0);
}
//------------------------------------------------------------------------------------
template <typename T>
void TModuleMMOEngine<T>::StopEvent()
{

}
//------------------------------------------------------------------------------------
template <typename T>
bool TModuleMMOEngine<T>::WorkInherit()
{
  InputFromSynchroPoint();
  //дать квант времени и транслировать события в игровой движок
  mPtrMMO->Work();
  OutputToSynchroPoint();
  return true;// всегда возвращать true
}
//------------------------------------------------------------------------------------
template <typename T>
T* TModuleMMOEngine<T>::Get()
{
  return mPtrMMO.get();
}
//------------------------------------------------------------------------------------

#endif
