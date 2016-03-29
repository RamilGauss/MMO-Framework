/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_OgreH
#define Builder_OgreH

#include "TypeDef.h"

class TTaskForBuilder_Ogre;

class DllExport TBuilder_Ogre
{
public:
  TBuilder_Ogre();
  virtual ~TBuilder_Ogre();

  void Work(TTaskForBuilder_Ogre* pTask);
};

#endif
