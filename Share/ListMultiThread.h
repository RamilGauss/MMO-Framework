/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ListMultiThreadH
#define ListMultiThreadH
#include "GCS.h"
#include "BL_Debug.h"

/*
  класс работы со списком
  Thread safe

*/
#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

template <class TClass> class TListMultiThread
{
  GCS       gcs;

  void      begin() {gcs.lock();  }
  void      end()   {gcs.unlock();}

protected:
	struct TElement
	{
    struct TDefElement
    {
      TElement* pBelow;
      TElement* pNext;
		  TClass*   data; // new
      TElement* ThisPointer;
    };
    TDefElement mDefElement;

    TElement()
		{
      mDefElement.ThisPointer = this;
			mDefElement.data   = NULL;
			mDefElement.pNext  = NULL;
			mDefElement.pBelow = NULL;
		}
		~TElement(){delete mDefElement.data;}
  };

protected:
  int cnt;
	TElement* pFirst;
	TElement* pLast;
public:
  void Clear()
  {
    begin();
    TClass** data = GetFirst(); 
    while(data)
    {
      Remove(data);// удаляем
      data = GetFirst();        
    }
    if(cnt!=0) BL_FIX_BUG();
    end();
  }

protected:
  //----------------------------------------------
  TElement* GetElement(TClass**d)
	{
		char* pAddress = ((char*)d+sizeof(TClass*));
		TElement** ppEl = (TElement**)pAddress;
		TElement* pEl = *ppEl;
		return pEl;
	}

public:

  void ZeroPointerElement(TClass**d)
  {
    TElement* pEl = GetElement(d);
    pEl->mDefElement.data = NULL;// отцепиться
  }
  //---------------------------------------------
  int GetCnt(){return cnt;};
  TListMultiThread()
	{
		pFirst = NULL;
		pLast  = NULL;
    cnt    = 0;
	}
	//----------------------------------------------
	~TListMultiThread()
	{
		Clear();
	}
	//----------------------------------------------
	// чтение/запись
  // функции Remove, Add, GetFirst, GetLast, Next и Below обрамлять Begin()/End()
  //++++++++++++++++++++++++++++++++++++++++++++
  // если в одном потоке используется Add
  // то во втором можно спокойно использовать Remove, GetFirst,Below, Next и GetLast.
  //++++++++++++++++++++++++++++++++++++++++++++
  // список запретных комбинаций (используй мьютекс для избежания коллизий)
  // Add    - Add
  // Remove - Remove
  // Remove - ( GetFirst,Below, Next и GetLast ) (операции чтения/запись R/W)
  // ( GetFirst,Below, Next и GetLast ) - ( GetFirst,Below, Next и GetLast )
  TClass** GetFirst()
  {
    if(pFirst==NULL)
      return NULL;
    
    return &(pFirst->mDefElement.data);
  }
  //----------------------------------------------
	TClass** GetLast()
  {
    if(pLast==NULL)
      return NULL;

    return &(pLast->mDefElement.data);
  }
  //----------------------------------------------
	TClass** Next(TClass** d)
  {
    TElement* pEl   = GetElement(d);
    TElement* pNext = pEl->mDefElement.pNext;
    if(pNext==NULL) return NULL;
    return &(pNext->mDefElement.data);
  }
  //----------------------------------------------
	TClass** Below(TClass** d)
  {
    TElement* pEl    = GetElement(d);
    TElement* pBelow = pEl->mDefElement.pBelow;
    if(pBelow==NULL) return NULL;
    return &(pBelow->mDefElement.data);
  }
  //----------------------------------------------
	TClass** Remove(TClass** d)
  {
		//--------------------------------------
    TElement* pEl = GetElement(d);
    begin();

    TElement* pNext = pEl->mDefElement.pNext;
    TClass** dNext = NULL;
    if(pNext)
      dNext = &(pEl->mDefElement.data);


    if((pFirst==pEl)&&
       (pLast ==pEl))
    {
      pFirst = NULL;
      pLast  = NULL;
    }
    else
    if(pFirst==pEl)
    {
      pFirst = pEl->mDefElement.pNext;
      pFirst->mDefElement.pBelow = NULL;
    }
    else
    if(pLast==pEl)
    {
      pLast = pEl->mDefElement.pBelow;
      pLast->mDefElement.pNext = NULL;
    }
    else
    {
      pEl->mDefElement.pNext->mDefElement.pBelow = pEl->mDefElement.pBelow;
      pEl->mDefElement.pBelow->mDefElement.pNext = pEl->mDefElement.pNext;
    }
    cnt--;

		end();
		//--------------------------------------
		delete pEl;
    return dNext;
  }
  //----------------------------------------------
  // копирует внутрь
  TClass** Add(TClass* d)
  {
    if(d==NULL) {BL_FIX_BUG();return NULL;}

		//--------------------------------------
    TElement* pEl = new TElement;
    begin();

    pEl->mDefElement.data = d;
    if(pFirst==NULL)
    {
      pFirst = pEl;
      pLast  = pEl;
    }
    else
    {
      pLast->mDefElement.pNext = pEl;
      pEl->mDefElement.pBelow  = pLast;
      pLast = pEl;
    }
    cnt++;

		end();
		//--------------------------------------
    return &(pEl->mDefElement.data);
  }
  //----------------------------------------------

};

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif


#endif // ListMultiThreadH


