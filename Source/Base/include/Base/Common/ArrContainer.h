/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "Base/Common/ContainerTypes.h"

/*
  класс работы с массивом контейнеров
  массив линейно находится памяти
  сплошь, как в std::vector
*/
class DllExport TArrContainer
{

    typedef std::vector<TContainer> TVectorContainer;

    TVectorContainer mVec;

    TContainer mFC;// вся память

public:
    TArrContainer();
    ~TArrContainer();
    // доступ к элементам
    void GetElem(char*& p, int& size, int index);
    void SetElem(char* p, int  size, int index);
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