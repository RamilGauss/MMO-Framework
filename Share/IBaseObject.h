/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseObjectH
#define BaseObjectH

#include <map>
#include <vector>

//#include "TObject.h"
#include "Struct3D.h"
#include "TreeJoint.h"
#include "CallBackRegistrator.h"

// базовый класс объектов сцены, физики

class SHARE_EI IBaseObject// : public TObject Gauss comment 09.07.2013
{
protected:
  TCallBackRegistrator1<int> mCallBackEvent;
  // свойства, характерные для физики и графики
  // ориентация, координаты, состояние
public:
  enum{
    eWorld = 0, // значение мировой матрицы
    eState,
    eMapUse,
  };

  IBaseObject();
  virtual ~IBaseObject();

  void SetWorld(nsStruct3D::TMatrix16* world);
  const nsStruct3D::TMatrix16* GetWorld()const {return &mWorld;}

  void SetID_Model(unsigned int id);
  void SetID_Map(unsigned int id){ID_map = id;}

  unsigned int GetID_Model(){return ID_model;}
  unsigned int GetID_Map(){return ID_map;}
  std::vector<unsigned char>* GetState(){return &mState;}

  virtual const nsStruct3D::TMatrix16* GetMatrixForCamera(){return GetWorld();}

  void SetVelocity(float v){mV=v;}// м/с - скаляр скорости
  float GetVelocity(){return mV;}

  void SetTree(TTreeJoint::TLoadedJoint* pTree);
  void SetMapUse(std::map<std::string,int>* mapUse = NULL);// использовать при смене используемых частей и при (собственно) начальном задании
  void SetState(std::vector<unsigned char>* state);
  
  void GetDefaultMapUse(std::map<std::string,int>* mapUse);
  
  void* GetPtrInherits(){return mPtrInherits;}

  // регистрация на получение событий объекта
  template<typename F, class A1>
  void RegisterOnEvent(F pFunc, A1 pObject){mCallBackEvent.Register(pFunc,pObject);}
  template<typename F, class A1>
  void UnregisterOnEvent(F pFunc, A1 pObject){mCallBackEvent.Unregister(pFunc,pObject);}

protected:
  
  float mV;// скорость, м/с
  float mA;// ускорение, м/с^2

  TTreeJoint::TLoadedJoint* pLoadedTree;
  TTreeJoint mTree;

  unsigned int ID_map;  // идентификатор на карте
  unsigned int ID_model;// идентификатор модели

  nsStruct3D::TMatrix16 mWorld; // здесь вся инфа по ориентации и координатам объекта

  std::vector<unsigned char> mState;// графика, говорит движку какую из частей рисовать, для физики определяет поведение объекта
  std::vector<unsigned char> mMask; // и физика и графика какие части рисовать и использовать
  std::vector<nsStruct3D::TMatrix16*> mVectorMatrix;// и физика и графика, cnt=cntAllJoint

  // size = sizeAllPart
  struct TPart 
  {
    std::string name;
    int use;
  };
  std::vector<TPart> mVectorNamePart;// перечислены имена частей моделей. графический вектор должен точно совпадать.
  // этот вектор используется для заполнения маски частей
  //size = sizeAllJoint
  std::vector<std::string> mVectorOrderPart;// порядок названий частей, без повторений, cnt=cntJoint
  std::map<std::string, int>  mMapUse;// 

  // настроить матрицу расположения и ориентации локальных видимых частей
  void SetDefaultMatrix();//### эксперимент
  void SetupState();
  void SetupMask();

  void SetupDefaultMapUse();

  // маска отрисовки частей модели
  // например, нарисовать Пушку1, а не Пушку0 и т.д.
  // 1 0 0 1 1 1 1


  void* mPtrInherits;// назначить в IBaseObjectCommon (решение проблемы виртуального наследования)

  int GetCountPart(const char* name, std::vector<std::string>* pVec);

protected:
  void Notify(int event){mCallBackEvent.Notify(event);}
};


#endif

