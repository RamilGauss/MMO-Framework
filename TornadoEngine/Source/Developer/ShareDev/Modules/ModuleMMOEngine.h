/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleMMOEngineH
#define ModuleMMOEngineH

#include "ModuleDev.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"

#include "Base.h"
#include "INetTransport.h"

class TWrapperMakerTransport;

template <typename T>
class DllExport TModuleMMOEngine : public TModuleDev
{
  boost::scoped_ptr<TWrapperMakerTransport> mMakerTransport;
  boost::scoped_ptr<T>                      mPtrMMO;
public:
  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();

  T* Get();
};
//--------------------------------------------------------------------------------------
template <typename T>
void TModuleMMOEngine<T>::StartEvent()
{
  mPtrMMO.reset(new T);
  mMakerTransport.reset(new TWrapperMakerTransport);

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
bool TModuleMMOEngine<T>::Work()
{
  InputFromModules();
  //дать квант времени и транслировать события в игровой движок
  mPtrMMO->Work();
  OutputToModules();
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
