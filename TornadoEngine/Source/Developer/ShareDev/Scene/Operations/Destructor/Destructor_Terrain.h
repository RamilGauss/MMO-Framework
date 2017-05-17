/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DestructorGameObjectH
#define DestructorGameObjectH

#include "TypeDef.h"
#include "Operation_Terrain.h"

#include <list>

class DllExport TDestructor_Terrain : public TOperation_Terrain
{
public:
  TDestructor_Terrain();
  virtual ~TDestructor_Terrain();

private:
};

#endif
