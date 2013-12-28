/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerH
#define ContainerH

#include "TypeDef.h"

/*
   лассический - CharPtr

   опирующий или берущий под контроль пам€ть контейнер
  копировать внутрь контейнера данные,
  объект сам освободит
*/

class SHARE_EI TContainer
{
  char* pData;
  int size;

public:
  TContainer(const TContainer&);
  TContainer& operator=(const TContainer&);
public:
  TContainer();
  virtual ~TContainer();
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

  static void Free(char* p){delete[]p;}
};

#endif

