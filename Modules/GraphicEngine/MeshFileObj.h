/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MeshFileObjH
#define MeshFileObjH

#include "IMeshFile.h"

class TMeshFileObj : public IMeshFile
{
public:
  
  TMeshFileObj();
  virtual ~TMeshFileObj();

  virtual bool Load(const char* strFilename, 
     nsMeshStruct::VERTEX*&      ppVertex, unsigned int& cntV,
                  unsigned int*& ppIndex,  unsigned int& cntI);

  virtual bool Save(const char* strFilename, 
     nsMeshStruct::VERTEX*       ppVertex, unsigned int cntV,
                    unsigned int* ppIndex, unsigned int cntI); 

protected:

  void Done();
};

#endif
