/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef BuilderShapeH
#define BuilderShapeH

#include "TypeDef.h"

#include "ParamBuilderShape.h"
#include <OgrePrerequisites.h>

class DllExport TBuilderShape
{
public:
  TBuilderShape();
  ~TBuilderShape();

  Ogre::MeshPtr Build(nsParamBuilderShape::TBaseParam* pParam);
};

#endif
