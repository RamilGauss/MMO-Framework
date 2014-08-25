/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SORTBYALPHABETICH
#define SORTBYALPHABETICH

#include <string>
#include <vector>
#include "TypeDef.h"

// для согласованности порядка частей в графике и физике
// пока класс очень частный, требует доработки до более общего вида

class DllExport TSortByAlphabetic
{

public:
  struct T
  {
    std::string s;
    int         v;
    int         index;
  };
  
  TSortByAlphabetic();
  virtual ~TSortByAlphabetic();

  void Sort(std::vector<T>* pVecInOut );

};


#endif
