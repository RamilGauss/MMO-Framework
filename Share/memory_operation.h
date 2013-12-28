/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MEMORY_OPERATIONH
#define MEMORY_OPERATIONH

#include "TypeDef.h"

/*
  mo_realloc_XXX - выделить память и скопировать туда содержимое старой памяти. 
               Если размер новой памяти будет меньше чем старой, то копирование будет неполным.
  
  mo_realloc_bound_XXX - увеличение размера памяти путем вставки новой памяти в определенную 
               зону по смещению size_bound.
               Новая память(то что вставили) будет содержать мусор. В остальной памяти будет копия
               старой памяти.
*/


// через malloc и free
extern SHARE_EI void* mo_realloc(void* old_mem, int old_size, int new_size);

extern SHARE_EI char* mo_realloc_bound(char* old_mem, int old_size, int size_bound, int size_paste);

// через new и delete
extern SHARE_EI void* mo_realloc_new(void* old_mem, int old_size, int new_size);

extern SHARE_EI char* mo_realloc_bound_new(char* old_mem, int old_size, int size_bound, int size_paste);

#endif