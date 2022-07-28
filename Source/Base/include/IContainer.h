/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

class DllExport IContainer
{
public:
    IContainer() {};
    virtual ~IContainer() {};

    // отдать под контроль ресурсы
    virtual void Entrust(char* p, int size) = 0;
    virtual void EntrustByCount(char* p, int count) = 0;

    // задать (копирование)
    virtual void SetData(char* p, int size) = 0;
    virtual void SetDataByCount(char* p, int count) = 0;
    // для получения доступа
    virtual char* GetPtr()const = 0;
    // полный размер хранимых ресурсов
    virtual int GetSize()const = 0;
    // кол-во элементов
    virtual int GetCount()const = 0;
    // отцепиться от ресурсов
    virtual void Unlink() = 0;
    // освободить ресурсы
    virtual void Done() = 0;
};
