/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PreDestructorH
#define PreDestructorH

#include "TypeDef.h"
#include <vector>

class DllExport TPreDestructor
{
public:
  typedef enum{eOgre, eBullet} eTypeTask;
  typedef std::vector<eTypeTask> TVectorTypeTask;

  TPreDestructor();
  virtual ~TPreDestructor();
};

#endif
