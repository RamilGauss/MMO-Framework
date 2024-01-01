/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <stddef.h>

#include "Base/Common/BL_Debug.h"
#include "Base/Common/DataExchange2ThreadElement.h"
#include "Base/Common/AllocatorPool.h"

using namespace DataExchange2Thread;

#ifdef _DEBUG
#define USE_COUNT_FOR_DEBUG
#endif
/*
  класс работы со списком
  Thread safe, Lock-free.

  два потока:
  один читает (Consumer), второй пишет в память(Producer). Используется либо volatile, либо atomic.

  в списке всегда существует элемент, в начале - пустой призрак,
  потом если необходимо удалить и остался один элемент, то
  он помечается как подготовленный для удаления, но удалять нельзя.
  Поток Producer удалит его когда появится еще элемент.
*/
template <typename TClass> 
class TDataExchange2Thread
{
#ifdef USE_COUNT_FOR_DEBUG
    DECLARATION_ATOMIC_INT(cnt);      // change by Producer
#endif

    TElement* pFirstConsumer = nullptr; // change by Consumer
    TElement* pFirstProducer = nullptr; // change by Producer
    TElement* pLastProducer = nullptr; // change by Producer

    TCallBackRegistrator1<void*>* mCB_DeleteData = nullptr;

    //DECLARATION_ALLOCATOR_MEMORY
    TAllocatorPool mAllocatorElement;
public:
    TDataExchange2Thread();
    ~TDataExchange2Thread();
    // удалять тем способом, которым создали, по-умолчанию new/delete
    // setup method of allocate memory, default new/delete.
    void SetCB_DeleteData(TCallBackRegistrator1<void*>* pCB) { mCB_DeleteData = pCB; }
    //==============================INTERFACE=============================
    // Consumer
    TClass** GetFirst();
    TClass** Next(TClass** d);
    void RemoveFirst();// вызывать только если нет указателей на элемент
    void UnlinkData(TClass** d);
    // Producer
    TClass** Add(TClass* d);
    void Clear();
    //==============================~INTERFACE=============================
    int GetCnt();// Debug only
protected:
    void LatencyRemove();
    TElement* GetElement(TClass** d);
#ifdef USE_COUNT_FOR_DEBUG
    void CntInc();
    void CntDecr();
#endif
};
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::Clear()
{
    while (pFirstProducer) {
        TElement* temp = pFirstProducer;
        pFirstProducer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstProducer->pNext);
        temp->Done(mCB_DeleteData);
        mAllocatorElement.Deallocate(temp);// DEALLOC_MEMORY(temp);
#ifdef USE_COUNT_FOR_DEBUG
        CntDecr();
#endif
    }
#ifdef USE_COUNT_FOR_DEBUG
    BL_ASSERT(DECLARATION_ATOMIC_INT_LOAD(cnt) == 0);
#endif
}
//--------------------------------------------------------------------------------------
template<typename TClass>
TElement* TDataExchange2Thread<TClass>::GetElement(TClass** d)
{
    char* pAddress = ((char*)d + sizeof(TClass*));
    TElement** ppEl = (TElement**)pAddress;
    TElement* pEl = *ppEl;
    return pEl;
}
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::UnlinkData(TClass** d)
{
    TElement* pEl = GetElement(d);
    pEl->data = nullptr;// отцепиться
}
//--------------------------------------------------------------------------------------
template<typename TClass>
int TDataExchange2Thread<TClass>::GetCnt()
{
#ifdef USE_COUNT_FOR_DEBUG
    return DECLARATION_ATOMIC_INT_LOAD(cnt);
#else
    return 0;
#endif
}
//--------------------------------------------------------------------------------------
#ifdef USE_COUNT_FOR_DEBUG
template<typename TClass>
void TDataExchange2Thread<TClass>::CntInc()
{
    int c = GetCnt();
    DECLARATION_ATOMIC_INT_STORE(cnt, c + 1);
}
//--------------------------------------------------------------------------------------
static int _debug = 0;
template<typename TClass>
void TDataExchange2Thread<TClass>::CntDecr()
{
    int c = GetCnt();
    DECLARATION_ATOMIC_INT_STORE(cnt, c - 1);
}
#endif
//--------------------------------------------------------------------------------------
template<typename TClass>
TDataExchange2Thread<TClass>::TDataExchange2Thread()// Producer/Consumer
{
    mCB_DeleteData = nullptr;

    pFirstConsumer = mAllocatorElement.Allocate();//(TElement);
    pFirstConsumer->Init();
    pFirstProducer = pFirstConsumer;
    pLastProducer = pFirstConsumer;
    DECLARATION_ATOMIC_CHAR_STORE(pFirstProducer->dummy, true);

#ifdef USE_COUNT_FOR_DEBUG
    DECLARATION_ATOMIC_INT_STORE(cnt, 1);
#endif
}
//----------------------------------------------
template<typename TClass>
TDataExchange2Thread<TClass>::~TDataExchange2Thread()// Producer
{
    Clear();
}
//----------------------------------------------
template<typename TClass>
TClass** TDataExchange2Thread<TClass>::GetFirst()// Consumer
{
    BL_ASSERT(pFirstConsumer);
    if (DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext) == nullptr) {
        if (DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->dummy) ||
            DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->prepareRemove)) {
            return nullptr;
        }

        return (TClass**)&(pFirstConsumer->data);
    }
    // cnt > 1
    if (DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->dummy) ||
        DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->prepareRemove)) {
        TElement* temp = pFirstConsumer;
        pFirstConsumer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext);// pNext != NULL
        DECLARATION_ATOMIC_CHAR_STORE(temp->needRemove, true);
    }
    return (TClass**)&(pFirstConsumer->data);
}
//--------------------------------------------------------------------------------------
template<typename TClass>
TClass** TDataExchange2Thread<TClass>::Next(TClass** d)// Consumer
{
    TElement* pEl = GetElement(d);
    TElement* pNext = DECLARATION_ATOMIC_POINTER_LOAD(pEl->pNext);
    if (pNext == nullptr) {
        return nullptr;
    }
    return &(pNext->data);
}
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::RemoveFirst()// Consumer
{
    if (pFirstConsumer == nullptr) {
        BL_FIX_BUG();
        return;
    }
    if (DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext)) {
        TElement* temp = pFirstConsumer;
        pFirstConsumer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext);
        DECLARATION_ATOMIC_CHAR_STORE(temp->needRemove, true);// помечаем для удаления
    } else {
        DECLARATION_ATOMIC_CHAR_STORE(pFirstConsumer->prepareRemove, true);// удалять нельзя, pNext всегда должен куда-то указывать
    }
}
//--------------------------------------------------------------------------------------
template<typename TClass>
TClass** TDataExchange2Thread<TClass>::Add(TClass* d)// Producer
{
    if (d == nullptr) {
        BL_FIX_BUG(); 
        return nullptr; 
    }

    TElement* pEl = mAllocatorElement.Allocate();// ALLOC_MEMORY(TElement);
    pEl->Init();

    pEl->data = d;
    DECLARATION_ATOMIC_POINTER_STORE(pLastProducer->pNext, pEl, TElement);
    pLastProducer = pEl;

#ifdef USE_COUNT_FOR_DEBUG
    CntInc();
#endif

    LatencyRemove();
    return (TClass**)&(pEl->data);
}
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::LatencyRemove()// Producer
{
    while (pFirstProducer) {
        if (DECLARATION_ATOMIC_CHAR_LOAD(pFirstProducer->needRemove) == false) {
            return;
        }

        TElement* pEl = pFirstProducer;
        pFirstProducer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstProducer->pNext);
        pEl->Done(mCB_DeleteData);
        mAllocatorElement.Deallocate(pEl);

#ifdef USE_COUNT_FOR_DEBUG
        CntDecr();
#endif
    }
}
//--------------------------------------------------------------------------------------
