/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleMMOH
#define ModuleMMOH

#include "ModuleDev.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"

#include "Base.h"
#include "INetTransport.h"

class TWrapperMakerTransport;

template <typename T>
class TModuleMMO : public TModuleDev
{
  boost::scoped_ptr<TWrapperMakerTransport> mMakerTransport;
  boost::scoped_ptr<T>                      mPtrMMO;
public:
  TModuleMMO();
  virtual bool Work();
  T* Get();
};
//--------------------------------------------------------------------------------------
template <typename T>
TModuleMMO<T>::TModuleMMO()
{
  mPtrMMO.reset(new T);
  mMakerTransport.reset(new TWrapperMakerTransport);

  mPtrMMO->Init(mMakerTransport.get());

  mPtrMMO->SetDstObject(this);
  mPtrMMO->SetSelfID(0);
}
//------------------------------------------------------------------------------------
template <typename T>
bool TModuleMMO<T>::Work()
{
  InputFromModules();
  //дать квант времени и транслировать события в игровой движок
  mPtrMMO->Work();
  OutputFromModules();
  return true;// всегда возвращать true
}
//------------------------------------------------------------------------------------
template <typename T>
T* TModuleMMO<T>::Get()
{
  return mPtrMMO.get();
}
//------------------------------------------------------------------------------------

#endif
