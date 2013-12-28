/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SORTBYALPHABETICH
#define SORTBYALPHABETICH

#include <string>
#include <vector>
#include "TypeDef.h"

// дл€ согласованности пор€дка частей в графике и физике
// пока класс очень частный, требует доработки до более общего вида

class SHARE_EI TSortByAlphabetic
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
