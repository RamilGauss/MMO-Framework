/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>

#include "BaseObjectGE.h"

#include <map>
#include "BL_Debug.h"
#include "AutoCreateVar.h"

using namespace nsMathTools;
using namespace std;

// ### «адать в адаптаре SetTree!!!
//#include "ManagerBaseObject.h"
//static TAutoCreateVarT<TManagerBaseObject> mManagerObject;

TBaseObjectGE::TBaseObjectGE()
{
  mPtrInherits = NULL;
  ID_model = 0;
  ID_map = 0;
  mV = 0;
  mA = 0;

  SetMatrixIdentity(&mWorld);
}
//------------------------------------------------------------------------------------------------
TBaseObjectGE::~TBaseObjectGE()
{
  int cnt = mVectorMatrix.size();
  for(int i = 0 ; i < cnt ; i++)
    delete mVectorMatrix[i];

  mVectorMatrix.clear();
  delete pLoadedTree;
  pLoadedTree = NULL;
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetState(vector<unsigned char>* state)
{
  BL_ASSERT(mState.size()==state->size());
  mState = *state;
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetTree(TTreeJoint::TLoadedJoint* pTree)
{
  delete pLoadedTree;
  pLoadedTree = new TTreeJoint::TLoadedJoint;
  *pLoadedTree = *pTree;// копируем структуру
}
//------------------------------------------------------------------------------------------------
// считываем данные либо из —”Ѕƒ либо с GUI -
// считать с объекта информацию о част€х, 
// выставить использование на первой неповтор€ющейс€ части и задать в окне в виде CheckBox
void TBaseObjectGE::SetMapUse(map<string, int>* mapUse)
{
  if(mapUse)
    mMapUse = *mapUse;
  mTree.Setup(pLoadedTree,&mMapUse);// инициализаци€ внутренностей иерархии
  mTree.SetOrderMatrixByName(&mVectorOrderPart);// в таком пор€дке будут строитьс€ матрицы

  SetDefaultMatrix();// в соответствии с деревом настроить матрицы по-умолчанию
  SetupState();// теперь известно сколько элементов
  SetupMask();// известно кол-во и пор€док следовани€ элементов
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetDefaultMatrix() 
{
  int cnt = mTree.GetCountPart();
  for(int i = 0 ; i < cnt ; i++) 
  {
    TMatrix16* pIdentity = new TMatrix16;
    SetMatrixIdentity(pIdentity);

    mVectorMatrix.push_back(pIdentity);
  }
  mTree.GetMatrix(&mVectorMatrix);
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetupState()
{
  int cnt = mTree.GetCountPart();
  if(cnt==mState.size()) return;
  //------------------------------------
  mState.clear();
  for(int i = 0 ; i < cnt ; i++ )
    mState.push_back(1);// по-умолчанию
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetupMask()
{
  BL_ASSERT(mVectorNamePart.size());// сначала должна быть проинициализирована модель!
  //-------------------------------------------------------------------------------
  int cntMask = mVectorNamePart.size();
  mMask.clear();
  for(int i = 0 ; i < cntMask ; i++ )
    mMask.push_back(0);// размер маски должен быть таким же как все части модели
  //-----------------------------------------------
  int sumMask = 0;
  // mMask - маска
  // mapUse - им€ - номер, не сортированный
  // mVectorNamePart - перечисление имен частей, сортированный
  for(int i = 0 ; i < cntMask ; i++)
  {
    TPart part = mVectorNamePart.at(i);
    // заполнить часть маски дл€ данного имени
    map<string,int>::iterator fit = mMapUse.find(part.name);
    if(fit->second==part.use)
    {
      mMask.at(i) = 1;
      sumMask++;
    }
  }
  BL_ASSERT(sumMask==mVectorOrderPart.size());
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetID_Model(unsigned int id)
{
  ID_model = id;
  //mManagerObject->AddObject(this);//####
}
//------------------------------------------------------------------------------------------------
int TBaseObjectGE::GetCountPart(const char* name,vector<string>* pVec)
{
  int found = 0;
  int cnt = pVec->size();
  for(int i = 0 ; i < cnt ; i++)
  {
    if(pVec->at(i).compare(name)==0)
      found++;
  }
  return found;
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::GetDefaultMapUse(map<string,int>* mapUse)
{
  *mapUse = mMapUse;
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetupDefaultMapUse()
{
  mMapUse.clear();
  int cnt = mVectorOrderPart.size();
  for(int i = 0 ; i < cnt ; i++)
  { 
    string name = mVectorOrderPart.at(i);
    map<string,int>::value_type val(name,0);
    mMapUse.insert(val);
  }
  SetMapUse();
}
//------------------------------------------------------------------------------------------------
void TBaseObjectGE::SetWorld(TMatrix16* world)
{
  mWorld=*world;
  //Notify(eWorld);
}
//------------------------------------------------------------------------------------------------
