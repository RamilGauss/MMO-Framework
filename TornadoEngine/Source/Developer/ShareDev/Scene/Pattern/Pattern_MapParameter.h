/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_MapParameterH
#define Pattern_MapParameterH

#include "TypeDef.h"
#include "BehaviourPattern.h"

// "вечный объект"
// в сцене он есть всегда, нельзя удалять, при создании карты добавляется сразу

class DllExport TPattern_MapParameter : public TBehaviourPattern
{
public:
  TPattern_MapParameter();
  virtual ~TPattern_MapParameter();

  virtual bool BuildByModule_Graphic(bool fast = false);
  virtual bool BuildByModule_Physic( bool fast = false);
  virtual bool BuildByModule_Sound(  bool fast = false);

  virtual TManagerNamePattern::eBaseType GetBaseType();
protected:

};

#endif
