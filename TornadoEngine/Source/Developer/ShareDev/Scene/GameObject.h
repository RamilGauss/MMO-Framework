/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameObjectH
#define GameObjectH

#include "TypeDef.h"
#include "MathTools.h"
#include <string>
#include <map>

/*
  Базовый тип игрового объекта для карты.
*/

class DllExport TGameObject
{
  std::string mType;// для поиска деструктора
  
  int mID;

  nsMathTools::TVector3 mPosition;
  nsMathTools::TVector3 mRotation;

public:
  //TGraphicComponent* mPtrGraphic;
  //TPhysicComponent*  mPtrPhysic;
  //TSoundComponent*   mPtrSound;
public:
  TGameObject(std::string type);
  virtual ~TGameObject();

  std::string GetSelfType();

  int GetID() const;
  void SetID( int id );

  typedef std::map<std::string,std::string> TMapStrStr;

  virtual void SetInternalState(TMapStrStr& mapStrStr) = 0;
  virtual bool GetInternalState(TMapStrStr& mapStrStr) = 0;
};

#endif
