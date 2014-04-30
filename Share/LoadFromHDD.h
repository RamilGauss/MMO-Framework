/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef LoadFromHDDH
#define LoadFromHDDH


#include <stdio.h>
#include <string>

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "FileInfoHDD.h"
/*
  Загрузка из файла
*/

class SHARE_EI TLoadFromHDD : public TFileInfoHDD
{
public:
	TLoadFromHDD(char* path = NULL);
	virtual ~TLoadFromHDD();

	virtual bool ReOpen(char* path, bool append = false);

	unsigned int Size();
  unsigned int Read(void* buffer, unsigned int size, unsigned int offset = 0);
  int ReadSmall(TContainer& c);
};

#endif

