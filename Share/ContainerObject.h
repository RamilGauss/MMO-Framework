/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerObjectH
#define ContainerObjectH

#include "Container.h"
#include <memory.h>
#include <stddef.h>

template <typename T>
class TContainerObject : public TContainer
{
  T* pData;
public:
  TContainerObject();
  virtual ~TContainerObject();
  // освободить пам€ть
  virtual void Done();
  // отдать под контроль кусок пам€ти, пам€ть должна быть выделена new char[N]
  virtual void Entrust(char* p, int s);
  // копировать внутрь данные
  virtual void SetData(char* p, int s);
  // получить доступ к данным
  virtual char* GetData(int &s);
  // более коротка€ верси€ дл€ получени€ доступа
  virtual void* GetPtr()const;
  virtual int GetSize()const;
  // что бы не освобождать пам€ть с помощью Done()
  virtual void Unlink();

  //static void Free(char* p){delete[]p;}
};
//---------------------------------------------------------------
template <typename T>
TContainerObject<T>::TContainerObject():
TContainer()
{
  pData = NULL;
}
//---------------------------------------------------------------
template <typename T>
TContainerObject<T>::~TContainerObject()
{
  Done();
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::Done()
{
  delete pData;
  pData = NULL;
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::SetData(char* p, int s)
{
  Done();
  pData = new T;
  if(p)
    *pData = *((T*)p);
}
//---------------------------------------------------------------
template <typename T>
char* TContainerObject<T>::GetData(int &s)
{
  s = sizeof(T);
  return (char*)pData;
}
//---------------------------------------------------------------
template <typename T>
void* TContainerObject<T>::GetPtr()const
{
  return pData;
}
//---------------------------------------------------------------
template <typename T>
int TContainerObject<T>::GetSize()const
{
  return sizeof(T);
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::Unlink()
{
  pData = NULL;
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::Entrust(char* p, int s)
{
  Done();
  pData = (T*)p;
}
//---------------------------------------------------------------
#endif

