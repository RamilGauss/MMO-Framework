/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreDestructorGameObjectH
#define PreDestructorGameObjectH

#include "TypeDef.h"
#include "PreDestructor.h"

class DllExport TPreDestructorGameObject : public TPreDestructor
{
public:
  TPreDestructorGameObject();
  virtual ~TPreDestructorGameObject();
};

#endif
