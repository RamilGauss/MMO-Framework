/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ArrContainerH
#define ArrContainerH

#include <vector>
#include "Container.h"

/*
  класс работы с массивом контейнеров
  массив линейно находится памяти
  сплошь, как в std::vector
*/
class SHARE_EI TArrContainer
{

  typedef std::vector<TContainer> TVectorContainer;

  TVectorContainer mVec;

  TContainer mFC;// вся память

public:

  TArrContainer();
  ~TArrContainer();
  // доступ к элементам
  void GetElem( char*& p, int& size, int index); 
  void SetElem( char*p,   int  size, int index); 
  // кол-во элементов
  void SetCount(int v);
  int GetCount();

  // вернуть указатель на первый элемент
  char* GetPtr();
  // размер - сумма всех размеров элементов
  int GetSize();

protected:
  void Collect();
};

#endif
