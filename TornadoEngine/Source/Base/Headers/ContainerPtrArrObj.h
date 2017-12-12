/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerPtrArrObjH
#define ContainerPtrArrObjH

#include "IContainer.h"
#include <memory.h>
#include <stddef.h>

/*
  В качестве ресурсов хранит указатель на объект, 
  НЕ позаботится об освобождении ресурсов
*/

template <typename T>
class TContainerPtrArrObj : public IContainer
{
  T*  pData;
  int mCount;
public:
  TContainerPtrArrObj();
  virtual ~TContainerPtrArrObj();

  virtual void Entrust(char* p, int size);
  virtual void EntrustByCount(char* p, int count = 1);
  virtual void SetData(char* p, int size);
  virtual void SetDataByCount(char* p, int count = 1);
  virtual char* GetPtr()const;
  virtual int GetCount()const;
  virtual int GetSize()const;
  virtual void Unlink();
  virtual void Done();
};
//---------------------------------------------------------------
template <typename T>
TContainerPtrArrObj<T>::TContainerPtrArrObj()
{
  pData  = NULL;
  mCount = 0;
}
//---------------------------------------------------------------
template <typename T>
TContainerPtrArrObj<T>::~TContainerPtrArrObj()
{
  Done();
}
//---------------------------------------------------------------
template <typename T>
void TContainerPtrArrObj<T>::Done()
{
  pData  = NULL;
  mCount = 0;
}
//---------------------------------------------------------------
template <typename T>
void TContainerPtrArrObj<T>::SetData(char* p, int size)
{
  SetDataByCount(p, size/sizeof(T));
}
//---------------------------------------------------------------
template <typename T>
void TContainerPtrArrObj<T>::SetDataByCount(char* p, int count)
{
  pData  = (T*)p;
  mCount = count;
}
//---------------------------------------------------------------
template <typename T>
char* TContainerPtrArrObj<T>::GetPtr() const
{
  return (char*)pData;
}
//---------------------------------------------------------------
template <typename T>
int TContainerPtrArrObj<T>::GetCount() const
{
  return mCount;
}
//---------------------------------------------------------------
template <typename T>
int TContainerPtrArrObj<T>::GetSize() const
{
  return mCount*sizeof(T);
}
//---------------------------------------------------------------
template <typename T>
void TContainerPtrArrObj<T>::Unlink()
{
  pData  = NULL;
  mCount = 0;
}
//---------------------------------------------------------------
template <typename T>
void TContainerPtrArrObj<T>::Entrust(char* p, int size)
{
  EntrustByCount(p, size/sizeof(T));
}
//---------------------------------------------------------------
template <typename T>
void TContainerPtrArrObj<T>::EntrustByCount(char* p, int count)
{
  pData  = (char*)p;
  mCount = count;
}
//---------------------------------------------------------------
#endif

