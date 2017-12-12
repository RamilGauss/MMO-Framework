/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_LightH
#define Pattern_LightH

#include "TypeDef.h"
#include "BehaviourPattern.h"

class DllExport TPattern_Light : public TBehaviourPattern
{
public:
  TPattern_Light();
  virtual ~TPattern_Light();

  virtual bool BuildByModule_Graphic(bool fast = false);

  virtual TManagerNamePattern::eBaseType GetBaseType();
protected:

  std::string GetNameLight();
  int GetType();
  bool GetIsCastShadow();
  bool GetIsVisible();
  nsMathTools::TVector3 GetDirVector();
  nsMathTools::TVector3 GetDiffuseColour();
  nsMathTools::TVector3 GetSpecularColour();

};

#endif
