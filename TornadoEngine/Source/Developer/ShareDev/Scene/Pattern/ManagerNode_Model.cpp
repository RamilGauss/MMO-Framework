/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerNode_Model.h"
#include "BaseNode_Model.h"
#include "BL_Debug.h"

TManagerNode_Model::TManagerNode_Model()
{

}
//-------------------------------------------------------------------------
TManagerNode_Model::~TManagerNode_Model()
{
  BL_ASSERT(mMapPartVariant_NodePtr.size()==0);
}
//-------------------------------------------------------------------------
void TManagerNode_Model::Add(TBaseNode_Model* p)
{
  TMapStrMapIt fitPart = mMapPartVariant_NodePtr.find(p->namePart);
  if( fitPart==mMapPartVariant_NodePtr.end() )
  {// не нашли, значит нужно создать карту "Вариант-Узел"
    TMapStrPtr mapVariantPtr;
    mMapPartVariant_NodePtr.insert(TMapStrMapVT(p->namePart,mapVariantPtr));
    fitPart = mMapPartVariant_NodePtr.find(p->namePart);
  }
  fitPart->second.insert(TMapStrPtrVT(p->nameVariant,p));
}
//-------------------------------------------------------------------------
void TManagerNode_Model::Remove(std::string namePart, std::string nameVariant)
{
  TMapStrMapIt fitPart = mMapPartVariant_NodePtr.find(namePart);
  if( fitPart==mMapPartVariant_NodePtr.end() )
    return;
  fitPart->second.erase(nameVariant);
  if( fitPart->second.size()==0 )
    mMapPartVariant_NodePtr.erase(namePart);
}
//-------------------------------------------------------------------------
TBaseNode_Model* TManagerNode_Model::Get(std::string namePart, std::string nameVariant)
{
  TBaseNode_Model* pNode = NULL;
  TMapStrMapIt fitPart = mMapPartVariant_NodePtr.find(namePart);
  if( fitPart==mMapPartVariant_NodePtr.end() )
    return pNode;
  TMapStrPtrIt fitVariant = fitPart->second.find(nameVariant);
  if( fitVariant==fitPart->second.end() )
    return pNode;
  pNode = fitVariant->second;
  return pNode;
}  
//-------------------------------------------------------------------------
int TManagerNode_Model::GetCountPart()
{
  return mMapPartVariant_NodePtr.size();
}
//-------------------------------------------------------------------------
std::string TManagerNode_Model::GetNamePart(int index)
{
  int cntPart = GetCountPart();

  if( index< 0      || 
      index>=cntPart )
    return "";

   TMapStrMapIt bit = mMapPartVariant_NodePtr.begin();
  for(int i = 0 ; i < index ; i++ )
    bit++;
  return bit->first;
}
//-------------------------------------------------------------------------
int TManagerNode_Model::GetCountVariant(std::string namePart)
{
  TMapStrMapIt fitPart = mMapPartVariant_NodePtr.find(namePart);
  if( fitPart==mMapPartVariant_NodePtr.end() )
    return 0;
  return fitPart->second.size();
}
//-------------------------------------------------------------------------
std::string TManagerNode_Model::GetNameVariant(std::string namePart, int index)
{
  int cntVariant = GetCountVariant(namePart);
  if( index < 0    ||
      index>=cntVariant )
    return "";

  TMapStrMapIt fitPart = mMapPartVariant_NodePtr.find(namePart);
  if( fitPart==mMapPartVariant_NodePtr.end() )
    return "";

  TMapStrPtrIt bit = fitPart->second.begin();
  for( int i = 0 ; i < index ; i++ )
    bit++;
  return bit->first;
}
//-------------------------------------------------------------------------
