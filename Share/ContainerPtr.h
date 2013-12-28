/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerPtrH
#define ContainerPtrH

#include "TypeDef.h"

/*
  Ќе копирующий контейнер
  хранит указатель на пам€ть и размер
  не освободит пам€ть
*/

class SHARE_EI TContainerPtr
{
protected:
  char* pData;
  int size;
public:
  TContainerPtr();
  virtual ~TContainerPtr();
  // обнулить указатель
  virtual void Unlink();

  virtual void SetData(char* p, int s);
  // получить доступ к данным
  virtual char* GetData(int &s);
  // более коротка€ верси€ дл€ получени€ доступа
  virtual void* GetPtr()const;
  virtual int GetSize()const;
};


#endif

