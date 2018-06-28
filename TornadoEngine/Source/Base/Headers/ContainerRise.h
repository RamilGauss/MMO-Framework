/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerRiseH
#define ContainerRiseH

#include "ContainerTypes.h"
#include "TypeDef.h"

class DllExport TContainerRise
{
  TContainer mC;
  int  mSizeUse;
public:
  TContainerRise();
  TContainerRise( const TContainerRise& c );
  TContainerRise& operator = ( const TContainerRise& c );

  inline void Clear();
  // offset > 0
  inline void Shift( int offset );
  // size > 0,  p != nullptr
  // добавит к размеру и скопирует внутрь
  inline void Append( int size, char* p );

  inline char* GetPtr();
  inline int GetSize();

  inline void Alloc( int new_size );  // не копирует 
  inline void Realloc( int new_size );// копирует старый кусок
};


#endif
