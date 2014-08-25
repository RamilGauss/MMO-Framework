/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BasePacketApplH
#define BasePacketApplH

#include "MarkUpContainer.h"
//#include "TObject.h"

// готовые макросы:
/*
    GetSet(Type,NameParam)
    GetSetCount(TypeCnt, TypeElem, NameParam )
*/
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
#define GetByPtr(Type,NameParam) \
Type* p = (Type*)mC.Get(#NameParam);

#define GetElemByPtr(Type, NameParam, index) \
Type* p = (Type*)mC.Get(#NameParam, false, index);
//----------------------------------------------------------------------------------------
#define GetSet(Type,NameParam) \
void Get##NameParam(Type& v) \
{ \
  GetByPtr(Type,NameParam) \
  v = *p; \
} \
void Set##NameParam(Type& v) \
{ \
  GetByPtr(Type,NameParam) \
  *p = v; \
}
//----------------------------------------------------------------------------------------
#define GetSetCount(TypeCnt, TypeElem, NameParam ) \
void SetCount##NameParam(TypeCnt v) \
{ \
  GetByPtr(TypeCnt,NameParam) \
  *p = v; \
  mC.Update(); \
} \
void GetCount##NameParam(TypeCnt& v) \
{ \
  GetByPtr(TypeCnt,NameParam) \
  v = *p; \
} \
void Set##NameParam(TypeElem& v, TypeCnt index) \
{ \
  GetElemByPtr(TypeElem,NameParam,index) \
  *p = v; \
} \
void Get##NameParam(TypeElem& v, TypeCnt index) \
{ \
  GetElemByPtr(TypeElem,NameParam,index) \
  v = *p; \
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
// класс служит заготовкой для упаковки в пакеты сложной структуры
// Как использовать:
// 1. Пронаследоваться.
// 2. Переопределяем GetType и Init.
// 3. Дописываем методы, с помощью которых можно получать доступ к полям пакета.
// в Init с помощью макросов и mC размечаем структуру пакета.

// наследуется от TObject для возможности использования в hArray
class DllExport TBasePacket
{
protected:

  TMarkUpContainer mC;
 
public:

	TBasePacket();
  virtual ~TBasePacket();

  virtual bool Set(void* p, int size);
  virtual void* Get(int &size);
  
  virtual int GetType(){return 0;}

	void  SetData(void* pData, int size);
	void* GetData(int& size);
	
protected:
  virtual void Init() = 0;

};

#endif

