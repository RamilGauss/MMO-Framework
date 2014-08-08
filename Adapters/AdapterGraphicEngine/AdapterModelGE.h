/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterModelGEH
#define AdapterModelGEH

#include "MathTools.h"

#include <vector>
#include <map>
#include "PrototypeModelGE.h"

class IModelGE;

class DllExport AdapterModelGE : public PrototypeModelGE
{
  IModelGE* mModel;
public:
  AdapterModelGE();
  virtual ~AdapterModelGE();
  virtual unsigned int GetID();
  virtual void SetID(unsigned int id);

  virtual int GetCntEffect();

  virtual void SortPartByAlphabetic();

  virtual unsigned int GetIndexVisualGroupByName(char* sName, int num);
  virtual const char* GetNameByIndex(int index);
  virtual int GetNumUseByIndex(int index);
  
  virtual void SetShaderStackMask(std::vector<int>* pVectorMask);// по этой маске настраиваются шейдеры эффектов
  virtual TShaderStack* GetShaderStack(int index);// взять стек для настройки

	virtual void* MakeTextureForCubeMap(int index);// для получения текстуры - надо перебрать все эффекты


  void SetModelGE(IModelGE* pModel);
};

#endif
