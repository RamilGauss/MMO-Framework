/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerArrObjH
#define ContainerArrObjH

#include "IContainer.h"
#include <memory.h>
#include <stddef.h>
#include <typeinfo>

/*
  В качестве ресурсов хранит указатель на объект, 
  позаботится об уничтожении для указателя и вызове деструктора
*/

template <typename T>
class TContainerArrObj : public IContainer
{
  T* pData;
  int mCount;
public:
  TContainerArrObj();
  virtual ~TContainerArrObj();

  virtual void Entrust(char* p, int size);
  virtual void EntrustByCount(char* p, int count = 1);
  virtual void SetData(char* p, int size);
  virtual void SetDataByCount(char* p, int count = 1);
  virtual char* GetPtr()const;
	virtual int GetSize() const;
	virtual int GetCount()const;
  virtual void Unlink();
  virtual void Done();
};
//---------------------------------------------------------------
template <typename T>
TContainerArrObj<T>::TContainerArrObj()
{
  pData = NULL;
  mCount = 0;
}
//---------------------------------------------------------------
template <typename T>
TContainerArrObj<T>::~TContainerArrObj()
{
  Done();
}
//---------------------------------------------------------------
template <typename T>
void TContainerArrObj<T>::Done()
{
	if(mCount==1)
		delete pData;
	else
		delete[] pData;
  pData  = NULL;
  mCount = 0;
}
//---------------------------------------------------------------
template <typename T>
void TContainerArrObj<T>::SetData(char* p, int size)
{
  SetDataByCount(p, size/sizeof(T));
}
//---------------------------------------------------------------
template <typename T>
void TContainerArrObj<T>::SetDataByCount(char* p, int count)
{
  if(count!=mCount)
  {
    Done();
    mCount = count;
    pData = new T[mCount];
  }
  
  if(p)
	{
		if((typeid(T)==typeid(char)          )||
			 (typeid(T)==typeid(unsigned char) )||
			 (typeid(T)==typeid(short)         )||
			 (typeid(T)==typeid(unsigned short))||
			 (typeid(T)==typeid(int)           )||
			 (typeid(T)==typeid(unsigned int)  ))
		{
			int size = GetSize();
			memcpy(pData, p, size);
		}
		else
		{
			for( int i = 0 ; i < mCount ; i++)
				pData[i] = ((T*)p)[i];
		}
	}
}
//---------------------------------------------------------------
template <typename T>
char* TContainerArrObj<T>::GetPtr() const
{
  return (char*)pData;
}
//---------------------------------------------------------------
template <typename T>
int TContainerArrObj<T>::GetCount()const
{
  return mCount;
}
//---------------------------------------------------------------
template <typename T>
int TContainerArrObj<T>::GetSize() const
{
	return mCount*sizeof(T);
}
//---------------------------------------------------------------
template <typename T>
void TContainerArrObj<T>::Unlink()
{
  pData  = NULL;
  mCount = 0;
}
//---------------------------------------------------------------
template <typename T>
void TContainerArrObj<T>::Entrust(char* p, int size)
{
  EntrustByCount(p, size/sizeof(T));
}
//---------------------------------------------------------------
template <typename T>
void TContainerArrObj<T>::EntrustByCount(char* p, int count)
{
  Done();
  pData  = (T*)p;
  mCount = count;
}
//---------------------------------------------------------------
#endif

