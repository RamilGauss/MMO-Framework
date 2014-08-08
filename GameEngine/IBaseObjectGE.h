/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBaseObjectGEH
#define IBaseObjectGEH

#include "IBaseObject.h"
#include <vector>
#include "TypeDef.h"

class PrototypeModelGE;
class PrototypeGraphicEngine;

class DllExport IBaseObjectGE : virtual public IBaseObject
{
  friend class PrototypeGraphicEngine;
  void* mObjectGE;
protected:

  bool flgShow;// показан ли объект на сцене
  float mAlphaTransparency;// прозрачность всего объекта, нельзя задать прозрачность части модели
  
public:
  typedef enum
  {
    eShow = IBaseObject::cntUpdateBase,
    eAlphaTransparency,
  }TypeUpdateBaseGE;

  IBaseObjectGE(int typeDX = eDirtyAnimate);
  virtual ~IBaseObjectGE();

  void SetModel(PrototypeModelGE* pModel);
  PrototypeModelGE* GetModel();

  //void Draw(const nsMathTools::TMatrix16* mView, void* pEffect = NULL);
  void* GetObjectGE();
  void  SetObjectGE(void* pObjectGE);

  void SetShow(bool show);
  bool IsShow();

  // вернет true - объект жив, false - закончил жить
  // должно быть задано время начало жизни, см. IBaseObject::mTimeCreation - хрень хрень
  // только для полностью анимированных объектов!!!
  // данная функция подготавливает данные для стека шейдера для данного момента времени
  // окончательная реализация стека должна быть в методе SetupShaderStackModelGE
  virtual bool Animate(unsigned int time_ms/*dirty animate ignore this parameter*/) = 0;//{return true;};

  enum{eDirtyAnimate = 0,
       ePureAnimate  = 1,// см. mTypeGE
  };
  int GetTypeGE(){return mTypeGE;}
  void SetTimeCreation(unsigned int t){mTimeCreation=t;};

  float GetAlphaTransparency();
  void  SetAlphaTransparency(float val);

	int GetCountPartForCubeMap();

	void* GetTextureForCubeMap(int i);

  // пока так, в будущем должно быть const char* GetPostEffect();
  virtual bool IsGlowEffect(){return false;};
  virtual bool IsGlowable(){return false;};

protected:
  PrototypeModelGE* mModel;// внешний вид 

  int mTypeGE;

  // время создания, необходимо для расчета анимации
  unsigned int mTimeCreation;// мс

	std::vector<void*> mVectorUseCubeMap;//вектор IDirect3DCubeTexture9**
protected:

  void Done();

  // такие же функции должны быть и в Prediction
  void SetupVectorNamePart();
  void SetupVectorOrderPart();
	void SetupVectorForCubeMap();

  void SetShaderStackMask(std::vector<int>* shaderStackMask);// настроить маску
  void SetupShaderStack(int indexSS, int index, void* data,int size);
  int  GetShaderStackIndexByName(int index, const char* nameParam);
  
public:
  virtual void SetupShaderStackModelGE(){};// для более тонкой настройки шейдера
  virtual void EventSetModelGE(){};
};
//-----------------------------------------------------------------

#endif
