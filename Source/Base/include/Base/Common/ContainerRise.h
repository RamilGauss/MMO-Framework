/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/ContainerTypes.h"
#include "Base/Common/TypeDef.h"

class DllExport TContainerRise
{
    TContainer mC;
    int  mSizeUse;
public:
    TContainerRise();
    TContainerRise(const TContainerRise& c);
    TContainerRise& operator = (const TContainerRise& c);

    void Clear();
    // offset > 0
    void Shift(int offset);
    // size > 0,  p != nullptr
    // добавит к размеру и скопирует внутрь
    void Append(int size, char* p);

    char* GetPtr() const;
    int GetSize() const;

    void Alloc(int new_size);  // не копирует 
    void Realloc(int new_size);// копирует старый кусок

    bool operator == (const TContainerRise& other);
};
