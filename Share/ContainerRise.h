/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerRiseH
#define ContainerRiseH

#include "Container.h"
#include "TypeDef.h"

class SHARE_EI TContainerRise
{

	TContainer mC;
	int  mSizeUse;

public:
	TContainerRise();
	
	void SetData(char* p, int size);// установит размер и скопирует внутрь
	// для частичного копирования используй memcpy

  void AddData(char*p, int size);

	char* GetPtr();
	int GetSize();

	void Alloc(int new_size);   // не копирует 
	void Realloc( int new_size);// копирует старый кусок
};


#endif
