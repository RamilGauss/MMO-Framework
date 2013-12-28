/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModelDXH
#define ModelDXH

#include "DXUT.h"

#include <d3dx9math.h>
#include <d3d9types.h>
#include <vector>
#include <map>
#include <list>

#include "Struct3D.h"
#include "EffectDX.h"
#include "ILoaderModelGE.h"
#include "ShaderStack.h"
#include "ExecShaderStack.h"
#include "IModelGE.h"


class TManagerResourceDX;

class TModelDX : public IModelGE
{
protected:

  TManagerResourceDX* mManagerResourceDX;

  IDirect3DDevice9* m_pd3dDevice;    // Direct3D Device object associated with this mesh

  // задаст ManagerModelDX
  unsigned int mID; // уникальный для моделей

  std::vector<TShaderStack*> mVectorShaderStack;
  std::vector<int>           mVectorShaderStackMask;
  TExecShaderStack           mExecSS;

	typedef std::list<IDirect3DCubeTexture9*> TListPtr;
	TListPtr mListCubeMap;

public:
  
  TModelDX(TManagerResourceDX* managerResourceDX);
  virtual ~TModelDX();
  virtual unsigned int GetID(){return mID;}
  virtual void SetID(unsigned int id){mID=id;}

  virtual int GetCntEffect();

  virtual void Draw(std::vector<void*>* pVecTexCubeMap,//                           
                    std::vector<unsigned char>* state, //                           
                    std::vector<unsigned char>* mask,  //                           
                    std::vector<nsStruct3D::TMatrix16*>* matrix,//кол-во совпадает с cSubset 
                    nsStruct3D::TMatrix16* pWorld,    // где и как расположен объект         
                    float alphaTransparency,  // прозрачность                       
                    const nsStruct3D::TMatrix16* pView, // расположение и ориентация камеры    
                    void* pEffect = NULL);


  bool Init(IDirect3DDevice9* pd3dDevice, LPCWSTR strPath);
  void Destroy();
  void LostDevice();
  void ResetDevice();
  virtual void SortPartByAlphabetic();

  virtual unsigned int GetIndexVisualGroupByName(char* sName, int num);
  virtual const char* GetNameByIndex(int index);
  virtual int GetNumUseByIndex(int index);

  
  virtual void SetShaderStackMask(std::vector<int>* pVectorMask);// по этой маске настраиваются шейдеры эффектов
  virtual TShaderStack* GetShaderStack(int index);// взять стек для настройки

	virtual void* MakeTextureForCubeMap(int index);// для получения текстуры - надо перебрать все эффекты

protected:
  void Done();
  //---------------------------------------------------------
  void SetupVectorLOD();
  bool AddEffectDX(ILoaderModelGE::TDefGroup* pDefGroup);
  void Draw(TEffectDX* pEffect, ID3DXMesh* pCurMesh);

  virtual bool Load(LPCWSTR strFilenameData);
  //---------------------------------------------------------
  
  struct TLOD
  {
    std::vector<TEffectDX*>* GetNonZeroVector(){if(normal.size()) return &normal;return &damage;}
    // визуальные индексы
    std::vector<TEffectDX*> normal;
    std::vector<TEffectDX*> damage;
    TLOD(){};
    ~TLOD()
    {
      normal.clear();
      damage.clear();
    }
  };

  // структурировать после загрузки
  std::vector<TLOD> mVectorLOD;

  // заполнить от загрузчика
  std::vector<TEffectDX*> mVectorAllEffect;// все состояния, ЛОДы, типы пушек, башен и т.д.
  float mLOD;// 2 состояния по ЛОДу, расстояние от камеры до центра координат


  // для оптимизации загрузки, чтобы исключить повторную загрузку текстур
  void LoadTexture(TEffectDX* pEffectDX);
  void LoadEffect(TEffectDX* pEffectDX);


  void SetupShaderStack();
  void SetShaderStack(TEffectDX* pEffect,int index);
  void AddShaderStack(ID3DXEffect* p);

	void LostCubeMap();
	void ResetCubeMap();

  // использовать свой эффект
  void DrawSelf(std::vector<void*>* pVecTexCubeMap,//                           
						    std::vector<unsigned char>* state, //                           
                std::vector<unsigned char>* mask,  //                           
                std::vector<nsStruct3D::TMatrix16*>* matrix,//кол-во совпадает с cSubset 
                nsStruct3D::TMatrix16* pWorld,    // где и как расположен объект         
                float alphaTransparency,  // прозрачность                       
                const nsStruct3D::TMatrix16* pView); // расположение и ориентация камеры    

  // подменить эффект для отрисовки (модель служит как источник ресурсов)
  void DrawBy(void* pVecEffect,// пока один эффект на модель, но нужно будет переделать на вектор
              std::vector<void*>* pVecTexCubeMap,    //                           
              std::vector<unsigned char>* state,     //                           
              std::vector<unsigned char>* mask,      //                           
              std::vector<nsStruct3D::TMatrix16*>* matrix,//кол-во совпадает с cSubset 
              nsStruct3D::TMatrix16* pWorld,    // где и как расположен объект         
              float alphaTransparency,  // прозрачность                        
              const nsStruct3D::TMatrix16* pView); // расположение и ориентация камеры    
};
//-----------------------------------------------------------------



#endif