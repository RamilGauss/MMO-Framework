/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterGraphicEngineObjectH
#define AdapterGraphicEngineObjectH

#include "ObjectGE.h"

class IBaseObjectGE;
class PrototypeObject;

class AdapterGraphicEngineObject : public TObjectGE
{
  IBaseObjectGE* mGameObject;
public:
  AdapterGraphicEngineObject(int typeDX = eDirtyAnimate);
  virtual ~AdapterGraphicEngineObject();

  virtual bool Animate(unsigned int time_ms/*dirty animate ignore this parameter*/);
  virtual bool IsGlowEffect();
  virtual bool IsGlowable();
  virtual void SetupShaderStackModelGE();// для более тонкой настройки шейдера
  virtual void EventSetModelGE();

  void SetGameObject(IBaseObjectGE* pObject);
  IBaseObjectGE* GetGameObject();

protected:
  void UpdateObject( PrototypeObject* p, int type_event);
};
//-----------------------------------------------------------------

#endif
