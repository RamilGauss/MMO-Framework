/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "VectorRise.h"
#include "FastUpperBound.h"
#include "BL_Debug.h"

// Warning! in future must remove it

// deprecated!!!
template<typename Type>
class DllExport TSortedVector
{
    TVectorRise<Type> mVec;// сортированный
public:
    void Insert(Type& v);
    void Erase(Type& v);
    void EraseByIndex(int index);

    int GetSize();
    Type Get(int index);
private:
    bool FindIndexByValue(Type& v, int& index);
};
//-------------------------------------------------------------------------------
template<typename Type>
void TSortedVector<Type>::Insert(Type& v)
{
    int index = fast_upper_bound2<Type>(mVec.mVec, mVec.mCounter, v);
    auto beginPtr = &mVec.mVec[0];
    int size = mVec.mCounter - index;

    memmove(beginPtr + index + 1, beginPtr + index, size * sizeof(unsigned int));
    mVec.mCounter++;
    mVec.mVec[index] = v;
}
//-------------------------------------------------------------------------------
template<typename Type>
void TSortedVector<Type>::Erase(Type& v)
{
    int index;
    if (FindIndexByValue(v, index) == false)
        return;
    EraseByIndex(index);
}
//-------------------------------------------------------------------------------
template<typename Type>
void TSortedVector<Type>::EraseByIndex(int index)
{
    auto beginPtr = &mVec.mVec[0];
    int size = mVec.mCounter - index - 1;
    memmove(beginPtr + index, beginPtr + index + 1, size * sizeof(Type));
    mVec.mCounter--;
}
//-------------------------------------------------------------------------------
int compare(unsigned int* v1, unsigned int* v2)
{
    if (*v1 > *v2)
        return 1;
    if (*v1 == *v2)
        return 0;
    return -1;
}
//-------------------------------------------------------------------------------
template<typename Type>
bool TSortedVector<Type>::FindIndexByValue(Type& v, int& index)
{
    // ищем итератор по внутреннему индексу
    // т.к. массив всегда сортированный можно быстро искать дихотомией
    void* result = std::bsearch(&v, &mVec.mVec[0], mVec.mCounter,
        sizeof(Type), (int(*)(const void*, const void*))compare);

    if (result == nullptr) {
        BL_FIX_BUG();
        return false;
    }
    index = ((char*)result - (char*)&mVec.mVec[0]) / sizeof(Type);
    return true;
}
//-------------------------------------------------------------------------------
template<typename Type>
int TSortedVector<Type>::GetSize()
{
    return mVec.mCounter;
}
//-------------------------------------------------------------------------------
template<typename Type>
Type TSortedVector<Type>::Get(int index)
{
    return mVec.mVec[index];
}
//-------------------------------------------------------------------------------
