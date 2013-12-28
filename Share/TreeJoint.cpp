/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TreeJoint.h"
#include "BL_Debug.h"
#include "Struct3D.h"

using namespace std;
using namespace nsStruct3D;

TTreeJoint::TTreeJoint()
{
  mLoadedTree = NULL;
  flgNeedSetup = true;
  flgWasSort   = false;
  mRoot = NULL;
}
//-------------------------------------------------------------------------
TTreeJoint::~TTreeJoint()
{
  Done();
}
//-------------------------------------------------------------------------
void TTreeJoint::SetOrderMatrixByName(vector<string>* order)// вызвать до вызова ChangeMatrix и GetMatrix
{
  // переставить местами в векторе ноды в соответствии с порядком
  int cnt = order->size();
  BL_ASSERT(cnt==GetCountPart());
  for(int i = 0 ; i < cnt ; i++)
  {
    bool flgFound = false;
    for(int j = i ; j < cnt ; j++)
    {    
      TNodeJoint* pNode_j = mVectorNode.at(j);
      if(order->operator [](i).compare(pNode_j->name)==0)
      {
        flgFound = true;
        if(i==j)
          break;// в нужном месте
        // меняем местами
        TNodeJoint* pNode_i = mVectorNode.at(i);
        mVectorNode.at(i) = pNode_j;
        mVectorNode.at(j) = pNode_i;
      }
    }
    BL_ASSERT(flgFound);
  }
}
//-------------------------------------------------------------------------
int TTreeJoint::GetCountPart()
{
  return mVectorNode.size();
}
//-------------------------------------------------------------------------
void TTreeJoint::Setup(TLoadedJoint* pLoadedTree,TNumUseMap* mapUse)
{
  Done();
  mLoadedTree = pLoadedTree;
  mMapUse = mapUse;
  //-----------------------------------------
  // поиск root
  int cnt = mLoadedTree->vectorPart.size();
  for(int i = 0 ; i < cnt ; i++)
  {
    TPart* pPart = mLoadedTree->vectorPart.at(i);
    if(pPart->name.compare(mLoadedTree->root)==0)
    { 
      TNumUseMap::iterator fit = mMapUse->find(pPart->name);
      if(fit!=mMapUse->end()) // если нашли
      if(fit->second==pPart->numUse) // совпало
      {
        // нашли root
        TNodeJoint* pNode = new TNodeJoint;
        mVectorNode.push_back(pNode);
        mRoot = pNode;
        //---------------------------
        mRoot->name = mLoadedTree->root;
        mRoot->matrixDef = mLoadedTree->world;
        mRoot->SetMatrixDef();
        mRoot->matrix_pro = mRoot->matrix;
        // теперь данная ветка сама найдет ветки для своих детей
        FindBranch(pPart, mRoot);// + инициализация структуры TNodeJoint
        flgNeedSetup = false;
        break;
      }
    }
  }
  mLoadedTree = NULL;
  mMapUse = NULL;
  BL_ASSERT(flgNeedSetup==false);
  //-----------------------------------------
  ProductAllMatrix();
}
//-------------------------------------------------------------------------
void TTreeJoint::ChangeMatrix(string& name, TMatrix16* matrix, bool def)
{
  int cnt = GetCountPart();
  for(int i = 0 ; i < cnt ; i++ )
  {
    TNodeJoint* pNode = mVectorNode.at(i);
    if(pNode->name.compare(name)==0)
    {
      if(def)
        pNode->SetMatrixDef();
      pNode->matrix = (*matrix) * pNode->matrix;
      break;
    }
  }
  ProductAllMatrix();
}
//-------------------------------------------------------------------------
// заполнить матрицей
void TTreeJoint::GetMatrix(vector<TMatrix16*>* matrix)
{
  int cnt = GetCountPart();
  for(int i = 0 ; i < cnt ; i++ )
  {
    TNodeJoint* pNode = mVectorNode.at(i);
    TMatrix16* pM = matrix->operator [](i);
    *pM = pNode->matrix_pro;// умноженная по иерархии
  }
}
//-------------------------------------------------------------------------
// сбросить все матрицы в дефолт
void TTreeJoint::SetDefault()
{
  int cnt = GetCountPart();
  for(int i = 0 ; i < cnt ; i++ )
  {
    TNodeJoint* pNode = mVectorNode.at(i);
    pNode->SetMatrixDef();
  }
  ProductAllMatrix();
}
//-------------------------------------------------------------------------
void TTreeJoint::Done()
{
  int cnt = GetCountPart();
  for(int i = 0 ; i < cnt ; i++ )
  {
    TNodeJoint* pNode = mVectorNode.at(i);
    delete pNode;
  }
  mVectorNode.clear();
  mRoot = NULL;
}
//-------------------------------------------------------------------------
void TTreeJoint::ProductAllMatrix()
{
  BL_ASSERT(mRoot);
  //-----------------------------------------------------
  ProductChild(mRoot);
}
//-------------------------------------------------------------------------
void TTreeJoint::ProductChild(TNodeJoint* pNode)
{
  int cnt = pNode->mVectorChild.size();
  for(int i = 0 ; i < cnt ; i++)
  {
    TNodeJoint* pChild = pNode->mVectorChild.at(i);
    ProductUp(pChild);// умножить матрицы данного Node вверх к корню и 
    //дать перемножить детям
    ProductChild(pChild);
  }
}
//-------------------------------------------------------------------------
void TTreeJoint::ProductUp(TNodeJoint* pNode)
{
  pNode->matrix_pro = pNode->matrix;
  TNodeJoint* pParent = pNode->pParent;
  while(pParent)
  {
    pNode->matrix_pro *= pParent->matrix;
    pParent = pParent->pParent;
  }
}
//-------------------------------------------------------------------------
void TTreeJoint::FindBranch(TPart* pPart, TNodeJoint* pParent)
{
  int cntTree = mLoadedTree->vectorPart.size();
  // настройка детей и поиск продолжения 
  int cnt = pPart->vectorChild.size();
  for(int i = 0; i < cnt ; i++)
  {
    TNodeJoint* pNode = new TNodeJoint;
    pNode->pParent = pParent;// знакомим родителя с ребенком
    pParent->mVectorChild.push_back(pNode);// добавить в список детей родителя
    mVectorNode.push_back(pNode);// в общий список

    TChild* pChild = pPart->vectorChild.at(i);
    pNode->name = pChild->name;// имя
    pNode->matrixDef = pChild->matrix;// матрица
    pNode->SetMatrixDef();
    // поиск
    for(int j = 0 ; j < cntTree ; j++)
    {
      TPart* pFPart = mLoadedTree->vectorPart.at(j);
      if(pFPart->name.compare(pNode->name)==0)
      {
        TNumUseMap::iterator fit = mMapUse->find(pFPart->name);
        if((fit!=mMapUse->end()        )&&// если нашли
           (fit->second==pFPart->numUse)) // совпало
        {
          FindBranch(pFPart,pNode);
        }
      }
    }
  }
}
//-------------------------------------------------------------------------
