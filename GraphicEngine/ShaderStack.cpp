/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ShaderStack.h"
#include "BL_Debug.h"

using namespace std;

TShaderStack::TShaderStack()
{

}
//-----------------------------------------------------------------------------------------------------
TShaderStack::~TShaderStack()
{
  Done();
}
//-----------------------------------------------------------------------------------------------------
int TShaderStack::Push(const char* nameValueIn, void* pDataIn, int sizeIn)
{
  TData* data = new TData;
  data->name = nameValueIn;
  data->Set((char*)pDataIn, sizeIn);
  mVectorNameData.push_back(data);
  return mVectorNameData.size()-1;
}
//-----------------------------------------------------------------------------------------------------
string TShaderStack::GetName(int index)
{
  BL_ASSERT(index<int(mVectorNameData.size()));
  return mVectorNameData.at(index)->name;
}
//-----------------------------------------------------------------------------------------------------
void* TShaderStack::GetData(int index, int& size)
{
  BL_ASSERT(index<int(mVectorNameData.size()));
  size = mVectorNameData.at(index)->c.GetSize();
  return mVectorNameData.at(index)->c.GetPtr();
}
//-----------------------------------------------------------------------------------------------------
void TShaderStack::Done()
{
  int cnt = mVectorNameData.size();
  for(int i = 0 ; i < cnt ; i++)
    delete mVectorNameData.at(i);

  mVectorNameData.clear();
}
//-----------------------------------------------------------------------------------------------------
void TShaderStack::SetData(int index, void* pDataIn, int sizeIn)
{
  mVectorNameData.at(index)->Set((char*)pDataIn, sizeIn);
}
//-----------------------------------------------------------------------------------------------------
int TShaderStack::GetIndexByName(const char* name)
{
  int cnt = mVectorNameData.size();
  for(int i = 0 ; i < cnt ; i++ )
  {
    if(mVectorNameData.at(i)->name.compare(name)==0)
      return i;
  }
  BL_FIX_BUG();
  return -1;
}
//-----------------------------------------------------------------------------------------------------
