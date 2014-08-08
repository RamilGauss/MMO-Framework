/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IMeshFileH
#define IMeshFileH

#include "MeshStruct.h"

class IMeshFile
{

public:
  
  IMeshFile(){};
  virtual ~IMeshFile(){};

  virtual bool Load(const char* strFilename, 
     nsMeshStruct::VERTEX*&      ppVertex, unsigned int& cntV,
                  unsigned int*& ppIndex,  unsigned int& cntI) = 0;

  virtual bool Save(const char* strFilename, 
     nsMeshStruct::VERTEX*       ppVertex, unsigned int cntV,
                    unsigned int* ppIndex, unsigned int cntI) = 0;

};

#endif
