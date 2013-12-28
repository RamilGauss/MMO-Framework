/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ControlLightH
#define ControlLightH

#include "Struct3D.h"
#include <vector>

class ICamera;
class IGraphicEngine;
class IManagerObjectCommon;
class IBaseObjectCommon;

class TControlLight
{

  IGraphicEngine* pGE;
  IManagerObjectCommon* pMOC;
  ICamera* mICamera;
  
  nsStruct3D::TVector3 mPos;// центр вращения

  bool isDrag;
  int  mOldX;
  int  mOldY;

  typedef std::vector<IBaseObjectCommon*> TVectorPtr;
  TVectorPtr mVecObjLight;// указатели этих объектов содержатся в mMOC

public:

  TControlLight();
  ~TControlLight();

  void Init();

  void SetPosition(nsStruct3D::TVector3* pPos);// центр вращения

  // манипуляции с мышью
  void BeginDrag(int x, int y);// экранные координаты мыши
  void EndDrag();
  // при движении мыши вызвать
  void Drag(int iCurLight,// текущий источник
            const nsStruct3D::TMatrix16* view,// матрица ориентации камеры
            int x, int y);// экранные координаты мыши


  // дублируются здесь только для получения события
  void SetLightEnable(int index, bool v);
  bool GetLightEnable(int index);
  int  GetCountAllLight();

	const nsStruct3D::TVector3* GetLightPosition(int index);	
	void SetLightPosition(int index,nsStruct3D::TVector3* m3);
	const nsStruct3D::TVector3* GetLightColor(int index);
	void SetLightColor(int index, nsStruct3D::TVector3* color);

  void SetViewObject(bool v);

protected:

  void Done();
  void Update();


  void SetObjectPos(nsStruct3D::TVector3* m3, int i);
};


#endif

