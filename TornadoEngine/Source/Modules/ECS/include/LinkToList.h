/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

template<typename Type>
class TLinkToList
{
public:
    typedef std::list<Type> List;
    typedef typename List::iterator Iterator;
private:
    List* mList;
    Iterator mIt;
public:
    TLinkToList()
    {
    }
    TLinkToList(List& tl, Iterator it)
    {
        Set(tl, it);
    }
    inline void Set(List& tl, Iterator it)
    {
        mList = &tl;
        mIt = it;
    }
    void Update(Type& v)
    {
        *mIt = v;
    }
    void Erase()
    {
        mList->erase(mIt);
    }
    List* GetList()
    {
        return mList;
    }
};
