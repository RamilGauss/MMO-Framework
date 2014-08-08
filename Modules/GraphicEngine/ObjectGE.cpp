/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>
#include "ObjectGE.h"

#include "IModelGE.h"
#include "MathTools.h"
#include "ShaderStack.h"

using namespace nsMathTools;
using namespace std;

TObjectGE::TObjectGE(int typeDX)
{
  flgShow = true;// показан ли объект на сцене
  mTimeCreation = 0;
  mModel = NULL;
  pLoadedTree = NULL;
  mAlphaTransparency = 1.0f;

  mTypeGE = typeDX;// по-умолчанию не чисто анимированный
}
//------------------------------------------------------------------------------------------------
TObjectGE::~TObjectGE()
{
  Done();
}
//------------------------------------------------------------------------------------------------
void TObjectGE::Draw(const TMatrix16* mView, void* pEffect)
{          
  if(flgShow==false) return;

  // назначить шейдерный стек
  SetupShaderStackModelGE();

  mModel->Draw(&mVectorUseCubeMap,
		           &mState,             //                       
               &mMask,
               &mVectorMatrix,//кол-во совпадает с cSubset   
               &mWorld,       // где и как расположен объект 
               mAlphaTransparency,
               mView,// расположение и ориентация камеры   
               pEffect);
}
//------------------------------------------------------------------------------------------------
void TObjectGE::SetModel(IModelGE* pModel)
{
  mModel = pModel;
  // скинуть инфу об именах в базовый объект
  SetupVectorNamePart();
  SetupVectorOrderPart();
  SetupDefaultMapUse();

  EventSetModelGE();
	// если используется cube map
	SetupVectorForCubeMap();
}
//------------------------------------------------------------------------------------------------
IModelGE* TObjectGE::GetModel()
{
  return mModel;
}
//------------------------------------------------------------------------------------------------
void TObjectGE::Done()
{
}
//------------------------------------------------------------------------------------------------
void TObjectGE::SetupVectorNamePart()
{
  int cnt = mModel->GetCntEffect();
  for(int i = 0 ; i < cnt ; i++)
  { 
    TPart part;
    part.name = mModel->GetNameByIndex(i);
    part.use  = mModel->GetNumUseByIndex(i);
    mVectorNamePart.push_back(part);
  }
}
//------------------------------------------------------------------------------------------------
void TObjectGE::SetupVectorOrderPart()
{
  int cnt = mModel->GetCntEffect();
  for(int i = 0 ; i < cnt ; i++)
  {
    string name = mModel->GetNameByIndex(i);
    if(mVectorOrderPart.size()==0)
      mVectorOrderPart.push_back(name);
    else
    {
      int lastIndex = mVectorOrderPart.size()-1;
      if(mVectorOrderPart.at(lastIndex).compare(name)!=0)
        mVectorOrderPart.push_back(name);
    }
  }
}
//------------------------------------------------------------------------------------------------
void TObjectGE::SetShaderStackMask(vector<int>* shaderStackMask)// настроить маску
{
  mModel->SetShaderStackMask(shaderStackMask);// настроить маску
}
//------------------------------------------------------------------------------------------------
void TObjectGE::SetupShaderStack(int indexSS, int index, void* data,int size)
{
  TShaderStack* pSS = mModel->GetShaderStack(indexSS);
  pSS->SetData(index, data, size);
}
//------------------------------------------------------------------------------------------------
int TObjectGE::GetShaderStackIndexByName(int index, const char* nameParam)
{
  TShaderStack* pSS = mModel->GetShaderStack(index);
  return pSS->GetIndexByName(nameParam);
}
//------------------------------------------------------------------------------------------------
int TObjectGE::GetCountPartForCubeMap()
{
	int nFind = 0;
	int cnt = mVectorUseCubeMap.size();
	for(int i = 0 ; i < cnt ; i++)
	{
		if(mVectorUseCubeMap[i])
			nFind++;
	}
	return nFind;
}
//------------------------------------------------------------------------------------------------
void* TObjectGE::GetTextureForCubeMap(int index)
{
	int nFind = 0;
	int cnt = mVectorUseCubeMap.size();
	for(int i = 0 ; i < cnt ; i++)
	{
		if(mVectorUseCubeMap[i])
			nFind++;
		if(index==nFind-1) return mVectorUseCubeMap[i];
	}
	return NULL;
}
//------------------------------------------------------------------------------------------------
void TObjectGE::SetupVectorForCubeMap()
{
	int cnt = mModel->GetCntEffect();
	for(int i = 0 ; i < cnt ; i++ )
		mVectorUseCubeMap.push_back(mModel->MakeTextureForCubeMap(i));
}
//------------------------------------------------------------------------------------------------
