/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "memory_operation.h"
#include <malloc.h>
#include <memory.h>
#include "BL_Debug.h"


void* mo_realloc(void* old_mem, int old_size, int new_size)
{
	BL_ASSERT(new_size>=0);
  if(old_size)
  {
    void* volatileBuffer = malloc(old_size);
    memcpy(volatileBuffer,old_mem,old_size);
    free(old_mem);
    old_mem = malloc( new_size);
    memcpy(old_mem,volatileBuffer,old_size);
    free(volatileBuffer);
  }
  else
    old_mem = malloc(new_size);

  return old_mem;
}
//--------------------------------------------------------------------------
char* mo_realloc_bound(char* old_mem, int old_size, int size_bound, int size_paste)
{
  BL_ASSERT(old_size!=0);

  char* new_mem = (char*)malloc(old_size+size_paste);
  memcpy(new_mem, old_mem,size_bound);
  memcpy(new_mem+size_bound+size_paste,old_mem+size_bound,old_size-size_bound);
  free(old_mem);
  return new_mem;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void* mo_realloc_new(void* old_mem, int old_size, int new_size)
{
	BL_ASSERT(new_size>=0);

  if(old_size)
  {
    void* volatileBuffer = new char[old_size];
    memcpy(volatileBuffer,old_mem,old_size);
    delete[](char*)old_mem;
    old_mem = new char[new_size];
    memcpy(old_mem,volatileBuffer,old_size);
    delete[](char*)volatileBuffer;
  }
  else
    old_mem = new char[new_size];

  return old_mem;
}
//--------------------------------------------------------------------------
char* mo_realloc_bound_new(char* old_mem, int old_size, int size_bound, int size_paste)
{
  BL_ASSERT(old_size!=0);

  char* new_mem = new char[old_size+size_paste];
  memcpy(new_mem, old_mem,size_bound);
  memcpy(new_mem+size_bound+size_paste,old_mem+size_bound,old_size-size_bound);
  delete[]old_mem;
  return new_mem;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
