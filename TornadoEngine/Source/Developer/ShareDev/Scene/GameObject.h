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

public:
  // отправлять по трубе Графике и Звуку + InternalState by ID's game object
  //nsMathTools::TVector3 mPosition; - применять в физике, графике и звуке
  //nsMathTools::TVector3 mRotation; - применять в физике, графике и звуке

  //TGraphicComponent* mPtrGraphic;
  //TPhysicComponent*  mPtrPhysic;
  //TSoundComponent*   mPtrSound;

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  typedef enum{eMovable, eUnmovable}TypeMobility;
  TypeMobility mMobility;
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
