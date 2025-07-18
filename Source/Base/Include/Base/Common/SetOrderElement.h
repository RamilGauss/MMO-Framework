/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include "Base/Common/SortedVecWithKeyMap.h"

/*
  Множество элементов, каждый из которых может определить свой индекс,
  вне зависимости сколько элементов было удалено.
  Добавление всегда происходит в конец.
  А удаление может происходить по любому ключу массива.
*/

class DllExport TSetOrderElement
{
    TSortedVecWithKeyMap mSimple;
    TSortedVecWithKeyMap mInGroup;
    unsigned int mNextAddInnerID = 0;
public:
    enum ContentType
    {
        InGroup,
        Simple
    };

    void PushBack(unsigned int key, ContentType type);

    void RemoveFirst();// неважно в группе или простой
    void RemoveByKey(unsigned int key);// удалить по ключу

    bool GetFirst(unsigned int& key, ContentType type);
    bool GetIndex(unsigned int key, int& index);

    void MoveToSimple(unsigned int key);// из группы перевести в обычные
private:
    TSortedVecWithKeyMap* GetFirstViaID();
};
