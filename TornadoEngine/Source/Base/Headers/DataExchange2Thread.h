/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DataExchange2ThreadH
#define DataExchange2ThreadH

#include <stddef.h>

#include "BL_Debug.h"
#include "LockFreeDef.h"
#include "CallBackRegistrator.h"

//#define USE_COUNT_FOR_DEBUG
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
template <typename TClass> class TDataExchange2Thread
{
#ifdef WIN32
#pragma pack(push, 1)
#endif
  struct TElement
	{
    DECLARATION_ATOMIC_POINTER(pNext, TElement);// change by Producer
    // data и ThisPointer местами не менять!
    TClass*   data;//new/delete                 // change by Producer
    TElement* ThisPointer;                      // change by Producer

    DECLARATION_ATOMIC_CHAR(needRemove);   // change by Consumer
    DECLARATION_ATOMIC_CHAR(prepareRemove);// change by Consumer
    DECLARATION_ATOMIC_CHAR(dummy);        // change by Consumer

    void Init();
    void Done(TCallBackRegistrator1<TClass*>* pCB);
  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif
#ifdef USE_COUNT_FOR_DEBUG
  DECLARATION_ATOMIC_INT(cnt);                  // change by Producer
#endif

	TElement* pFirstConsumer; // change by Consumer
	TElement* pFirstProducer; // change by Producer
  TElement* pLastProducer;  // change by Producer

  TCallBackRegistrator1<TClass*>* mCB_DeleteData;
  
  DECLARATION_ALLOCATOR_MEMORY
public:
  TDataExchange2Thread();
	~TDataExchange2Thread();
  // удалять тем способом, которым создали, или по-умолчанию new/delete
  // setup method of allocate memory, default new/delete.
  void SetCB_DeleteData(TCallBackRegistrator1<TClass*>* pCB){mCB_DeleteData=pCB;}
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
  TElement* GetElement(TClass**d);
#ifdef USE_COUNT_FOR_DEBUG
  void CntInc();
  void CntDecr();
#endif
};
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
template<typename TClass> 
void TDataExchange2Thread<TClass>::TElement::Init()
{
  ThisPointer   = this;
  data          = NULL;
  DECLARATION_ATOMIC_POINTER_STORE(pNext, NULL, TElement);

  DECLARATION_ATOMIC_CHAR_STORE(needRemove, false);
  DECLARATION_ATOMIC_CHAR_STORE(prepareRemove, false);
  DECLARATION_ATOMIC_CHAR_STORE(dummy, false);
}
//--------------------------------------------------------------------------------------
template<typename TClass> 
void TDataExchange2Thread<TClass>::TElement::Done(TCallBackRegistrator1<TClass*>* pCB)
{
  if( data==NULL )
    return;
  if( pCB )
    pCB->Notify(data);
  else
    delete data;// don't touch! pair new/delete
}
//--------------------------------------------------------------------------------------
template<typename TClass> 
void TDataExchange2Thread<TClass>::Clear()
{
  while( pFirstProducer )
  {
    TElement* temp = pFirstProducer;
    pFirstProducer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstProducer->pNext);
    temp->Done(mCB_DeleteData);
    DEALLOC_MEMORY(temp);
#ifdef USE_COUNT_FOR_DEBUG
    CntDecr();
#endif
  }
#ifdef USE_COUNT_FOR_DEBUG
  BL_ASSERT( DECLARATION_ATOMIC_INT_LOAD(cnt)==0 );
#endif
}
//--------------------------------------------------------------------------------------
template<typename TClass> 
typename TDataExchange2Thread<TClass>::TElement* TDataExchange2Thread<TClass>::GetElement(TClass** d)
{
  char* pAddress  = ((char*)d+sizeof(TClass*));
  TElement** ppEl = (TElement**)pAddress;
  TElement* pEl   = *ppEl;
  return pEl;
}
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::UnlinkData(TClass**d)
{
  TElement* pEl = GetElement(d);
  pEl->data = NULL;// отцепиться
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
:CONSTRUCTOR_ALLOCATOR_MEMORY(TElement)
{
  mCB_DeleteData = NULL;

  pFirstConsumer = ALLOC_MEMORY(TElement);
  pFirstConsumer->Init();
  pFirstProducer = pFirstConsumer;
  pLastProducer  = pFirstConsumer;
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
  BL_ASSERT( pFirstConsumer );
  if( DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext)==NULL )
  {
    if( DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->dummy)        || 
        DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->prepareRemove) )
      return NULL;

    return &(pFirstConsumer->data);
  }
  // cnt > 1
  if( DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->dummy)        || 
      DECLARATION_ATOMIC_CHAR_LOAD(pFirstConsumer->prepareRemove) )
  {
    TElement* temp = pFirstConsumer;
    pFirstConsumer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext);// pNext != NULL
    DECLARATION_ATOMIC_CHAR_STORE(temp->needRemove, true);
  }
  return &(pFirstConsumer->data);
}
//--------------------------------------------------------------------------------------
template<typename TClass>
TClass** TDataExchange2Thread<TClass>::Next(TClass** d)// Consumer
{
  TElement* pEl   = GetElement(d);
  TElement* pNext = DECLARATION_ATOMIC_POINTER_LOAD(pEl->pNext);
  if( pNext==NULL ) return NULL;
  return &(pNext->data);
}
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::RemoveFirst()// Consumer
{
  if( pFirstConsumer==NULL )
  {
    BL_FIX_BUG();
    return;
  }
  if( DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext) )
  {
    TElement* temp = pFirstConsumer;
    pFirstConsumer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstConsumer->pNext);
    DECLARATION_ATOMIC_CHAR_STORE(temp->needRemove, true);// помечаем для удаления
  }
  else
    DECLARATION_ATOMIC_CHAR_STORE(pFirstConsumer->prepareRemove, true);// удалять нельзя, pNext всегда должен куда-то указывать
}
//--------------------------------------------------------------------------------------
template<typename TClass>
TClass** TDataExchange2Thread<TClass>::Add(TClass* d)// Producer
{
  if( d==NULL ) {BL_FIX_BUG();return NULL;}

  TElement* pEl = ALLOC_MEMORY(TElement);
  pEl->Init();

  pEl->data = d;
  DECLARATION_ATOMIC_POINTER_STORE(pLastProducer->pNext, pEl, TElement);
  pLastProducer = pEl;

#ifdef USE_COUNT_FOR_DEBUG
  CntInc();
#endif

  LatencyRemove();
  return &(pEl->data);
}
//--------------------------------------------------------------------------------------
template<typename TClass>
void TDataExchange2Thread<TClass>::LatencyRemove()// Producer
{
  while( pFirstProducer )
  {
    if( DECLARATION_ATOMIC_CHAR_LOAD(pFirstProducer->needRemove)==false )
      return;
    
    TElement* pEl = pFirstProducer;
    pFirstProducer = DECLARATION_ATOMIC_POINTER_LOAD(pFirstProducer->pNext);
    pEl->Done(mCB_DeleteData);
    DEALLOC_MEMORY(pEl);

#ifdef USE_COUNT_FOR_DEBUG
    CntDecr();
#endif
  }
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
#endif // List2ThreadH
