/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IContainerH
#define IContainerH

#include "TypeDef.h"

class DllExport IContainer
{
public:
  IContainer(){};
  virtual ~IContainer(){};
  
  // отдать под контроль ресурсы, типа, "на, это теперь твое"
  virtual void Entrust(char* p, int size) = 0;
  virtual void EntrustByCount(char* p, int count) = 0;

  // задать, "получи, попользуйся, но отдай мне обратно" (копирование)
  virtual void SetData(char* p, int size) = 0;
  virtual void SetDataByCount(char* p, int count) = 0;
  // для получения доступа, "чем владеешь?"
  virtual char* GetPtr()const = 0;
	// полный размер хранимых ресурсов
	virtual int GetSize()const = 0;
	// "сколько элементов у тебя?"
  virtual int GetCount()const = 0;
  // отцепиться от ресурсов, "забудь, что у тебя есть"
  virtual void Unlink() = 0;
  // освободить ресурсы, "приберись за собой"
  virtual void Done() = 0;
};


#endif

