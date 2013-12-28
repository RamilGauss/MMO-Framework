/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IModelGEH
#define IModelGEH

#include "Struct3D.h"

#include <vector>
#include <map>

class TShaderStack;

class IModelGE
{
public:
  
  IModelGE(){};
  virtual ~IModelGE(){};
  virtual unsigned int GetID() = 0;
  virtual void SetID(unsigned int id) = 0;

  virtual int GetCntEffect() = 0;

  /*
    Рендер маски частей
    с ориентацией и положением частей
    в мировых координатах
  */
  virtual void Draw(std::vector<void*>* pVecTexCubeMap,//                           
                    std::vector<unsigned char>* state, //                           
                    std::vector<unsigned char>* mask,  //                           
                    std::vector<nsStruct3D::TMatrix16*>* matrix,//кол-во совпадает с cSubset 
                    nsStruct3D::TMatrix16* pWorld,    // где и как расположен объект         
                    float alphaTransparency,  // прозрачность                       
                    const nsStruct3D::TMatrix16* pView, // расположение и ориентация камеры    
                    void* pEffect = NULL) = 0;// поменять ли эффект


  virtual void SortPartByAlphabetic() = 0;

  virtual unsigned int GetIndexVisualGroupByName(char* sName, int num) = 0;
  virtual const char* GetNameByIndex(int index) = 0;
  virtual int GetNumUseByIndex(int index) = 0;

  
  virtual void SetShaderStackMask(std::vector<int>* pVectorMask) = 0;// по этой маске настраиваются шейдеры эффектов
  virtual TShaderStack* GetShaderStack(int index) = 0;// взять стек для настройки

	virtual void* MakeTextureForCubeMap(int index) = 0;// для получения текстуры - надо перебрать все эффекты

};
//-----------------------------------------------------------------



#endif