/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef BaseNode_ModelH
#define BaseNode_ModelH

#include "TypeDef.h"
#include "MathTools.h"
#include <OgreEntity.h>
#include "ModelItem.h"

class DllExport TBaseNode_Model
{
public:
  TModelItem::eType type;
  std::string namePart;
  std::string nameVariant;

public:
  TBaseNode_Model();
  virtual ~TBaseNode_Model();
};

#endif
