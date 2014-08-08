/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterModelGE.h"
#include "IModelGE.h"

AdapterModelGE::AdapterModelGE()
{
  mModel = NULL;
}
//-----------------------------------------------------------------------------------
AdapterModelGE::~AdapterModelGE()
{

}
//-----------------------------------------------------------------------------------
unsigned int AdapterModelGE::GetID()
{
  return mModel->GetID();
}
//-----------------------------------------------------------------------------------
void AdapterModelGE::SetID(unsigned int id)
{
  mModel->SetID(id);
}
//-----------------------------------------------------------------------------------
int AdapterModelGE::GetCntEffect()
{
  return mModel->GetCntEffect();
}
//-----------------------------------------------------------------------------------
void AdapterModelGE::SortPartByAlphabetic()
{
  mModel->SortPartByAlphabetic();
}
//-----------------------------------------------------------------------------------
unsigned int AdapterModelGE::GetIndexVisualGroupByName(char* sName, int num)
{
  return mModel->GetIndexVisualGroupByName(sName, num);
}
//-----------------------------------------------------------------------------------
const char* AdapterModelGE::GetNameByIndex(int index)
{
  return mModel->GetNameByIndex(index);
}
//-----------------------------------------------------------------------------------
int AdapterModelGE::GetNumUseByIndex(int index)
{
  return mModel->GetNumUseByIndex(index);
}
//-----------------------------------------------------------------------------------
void AdapterModelGE::SetShaderStackMask(std::vector<int>* pVectorMask)
{
  mModel->SetShaderStackMask(pVectorMask);
}
//-----------------------------------------------------------------------------------
TShaderStack* AdapterModelGE::GetShaderStack(int index)
{
  return mModel->GetShaderStack(index);
}
//-----------------------------------------------------------------------------------
void* AdapterModelGE::MakeTextureForCubeMap(int index)
{
  return mModel->MakeTextureForCubeMap(index);
}
//-----------------------------------------------------------------------------------
void AdapterModelGE::SetModelGE(IModelGE* pModel)
{
  mModel = pModel;
}
//-----------------------------------------------------------------------------------
