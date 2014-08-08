/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBaseObjectH
#define IBaseObjectH

#include <map>
#include <vector>

#include "MathTools.h"
#include "TreeJoint.h"
#include "PrototypeObject.h"

// базовый класс объектов сцены, физики

class DllExport IBaseObject : public PrototypeObject
{
  // свойства, характерные для физики и графики
  // ориентация, координаты, состояние
public:
  typedef enum
  {
    eWorld = 0,
    eTree,
    eVectorMatrix,
    cntUpdateBase,
  }TypeUpdateBase;

  IBaseObject();
  virtual ~IBaseObject();

  void SetWorld(nsMathTools::TMatrix16* world);
  const nsMathTools::TMatrix16* GetWorld()const;

  void SetID_Model(unsigned int id);
  void SetID_Map(unsigned int id){ID_map = id;}

  unsigned int GetID_Model(){return ID_model;}
  unsigned int GetID_Map(){return ID_map;}
  std::vector<unsigned char>* GetState(){return &mState;}

  virtual const nsMathTools::TMatrix16* GetMatrixForCamera(){return GetWorld();}

  //void SetVelocity(float v){mV=v;}// м/с - скаляр скорости
  //float GetVelocity(){return mV;}

  void SetTree(TTreeJoint::TLoadedJoint* pTree);
  TTreeJoint::TLoadedJoint* GetTree();

  void SetMapUse(std::map<std::string,int>* mapUse = NULL);// использовать при смене используемых частей и при (собственно) начальном задании
  void SetState(std::vector<unsigned char>* state);
  
  void GetDefaultMapUse(std::map<std::string,int>* mapUse);
  
  void* GetPtrInherits(){return mPtrInherits;}

  TTreeJoint* GetReadyTree();
  std::vector<nsMathTools::TMatrix16*>* GetVectorMatrix();

protected:
  void ChangeTreeMatrix(std::string& name,nsMathTools::TMatrix16* matrix, bool def = true);
  void RefreshVectorMatrixByTree();
  
  TTreeJoint::TLoadedJoint* pLoadedTree;
private:  
  TTreeJoint mTree;
protected:
  unsigned int ID_map;  // идентификатор на карте
  unsigned int ID_model;// идентификатор модели

  nsMathTools::TMatrix16 mWorld; // здесь вся инфа по ориентации и координатам объекта

  std::vector<unsigned char> mState;// графика, говорит движку какую из частей рисовать, для физики определяет поведение объекта
  std::vector<unsigned char> mMask; // и физика и графика какие части рисовать и использовать
  std::vector<nsMathTools::TMatrix16*> mVectorMatrix;// и физика и графика, cnt=cntAllJoint

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
protected:
  // настроить матрицу расположения и ориентации локальных видимых частей
  void SetDefaultMatrix();//### эксперимент
  void SetupState();
  void SetupMask();

  void SetupDefaultMapUse();

  // маска отрисовки частей модели
  // например, нарисовать Пушку1, а не Пушку0 и т.д.
  // 1 0 0 1 1 1 1


  void* mPtrInherits;// назначить в IBaseObjectGeneral (решение проблемы виртуального наследования)

  int GetCountPart(const char* name, std::vector<std::string>* pVec);
};


#endif

