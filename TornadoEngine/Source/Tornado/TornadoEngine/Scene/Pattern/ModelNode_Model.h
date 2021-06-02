/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef ModelNode_ModelH
#define ModelNode_ModelH

#include "TypeDef.h"
#include "BaseNode_Model.h"

class TPattern_Model;

class DllExport TModelNode_Model : public TBaseNode_Model
{
public:
    TPattern_Model* mPtrModel;
public:
  TModelNode_Model();
  virtual ~TModelNode_Model();

};

#endif
