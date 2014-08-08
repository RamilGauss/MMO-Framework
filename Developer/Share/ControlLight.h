/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ControlLightH
#define ControlLightH

#include "MathTools.h"
#include <vector>

class PrototypeMOG;
class PrototypeGraphicEngine;
class IBaseObjectGeneral;

class TControlLight
{
  PrototypeGraphicEngine* pGE;
  PrototypeMOG* pMOC;
  
  nsMathTools::TVector3 mPos;// центр вращения

  bool isDrag;
  int  mOldX;
  int  mOldY;

  typedef std::vector<IBaseObjectGeneral*> TVectorPtr;
  TVectorPtr mVecObjLight;// указатели этих объектов содержатся в mMOC

public:

  TControlLight();
  ~TControlLight();

  void Init();

  void SetPosition(nsMathTools::TVector3* pPos);// центр вращения

  // манипуляции с мышью
  void BeginDrag(int x, int y);// экранные координаты мыши
  void EndDrag();
  // при движении мыши вызвать
  void Drag(int iCurLight,// текущий источник
            const nsMathTools::TMatrix16* view,// матрица ориентации камеры
            int x, int y);// экранные координаты мыши


  // дублируются здесь только для получения события
  void SetLightEnable(int index, bool v);
  bool GetLightEnable(int index);
  int  GetCountAllLight();

	const nsMathTools::TVector3* GetLightPosition(int index);	
	void SetLightPosition(int index,nsMathTools::TVector3* m3);
	const nsMathTools::TVector3* GetLightColor(int index);
	void SetLightColor(int index, nsMathTools::TVector3* color);

  void SetViewObject(bool v);

protected:

  void Done();
  void Update();


  void SetObjectPos(nsMathTools::TVector3* m3, int i);
};


#endif

