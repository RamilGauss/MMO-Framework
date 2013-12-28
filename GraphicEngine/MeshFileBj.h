/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MeshFileBjH
#define MeshFileBjH

#include "IMeshFile.h"

class TMeshFileBj : public IMeshFile
{

public:
  
  TMeshFileBj();
  virtual ~TMeshFileBj();

  virtual bool Load(const char* strFilename, 
     nsMeshStruct::VERTEX*&      ppVertex, unsigned int& cntV,
                  unsigned int*& ppIndex,  unsigned int& cntI);

  virtual bool Save(const char* strFilename, 
     nsMeshStruct::VERTEX*       ppVertex, unsigned int cntV,
                   unsigned int* ppIndex, unsigned int  cntI); 

protected:

  void Done();
  char* pReadData;
};

#endif
