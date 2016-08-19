/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MarkUpContainer.h"
#include "BL_Debug.h"

using namespace std;

//--------------------------------------------------------------------
TMarkUpContainer::TMarkUpContainer()
{
  mRootElem = NULL;
  mCurElem  = NULL;
}
//--------------------------------------------------------------------
TMarkUpContainer::~TMarkUpContainer()
{
  delete mRootElem;
}
//--------------------------------------------------------------------
void TMarkUpContainer::SetMarkUp(TDesc* pDesc)
{
  // удалить старую разметку
  delete mRoot;
  mRoot = pDesc->CloneHierarhy();// создать свою иерархию

  // удалить старую структуру данных
  delete mRootElem;
  mRootElem = new TElem;
  mCurElem = mRootElem;

  std::list<TDesc*>::iterator bit = mRoot->list.begin();
  std::list<TDesc*>::iterator eit = mRoot->list.end();
  while(bit!=eit)
  {
    TDesc* itDesc = (*bit);

    TDescPrivate* pDescPrivate = new TDescPrivate;
    pDescPrivate->data.SetData(NULL, itDesc->size);
    memset(pDescPrivate->data.GetPtr(), 0, pDescPrivate->data.GetSize());
    pDescPrivate->pDesc = itDesc;
    pDescPrivate->pMasterElem = mRootElem;
    pDescPrivate->typeConst = itDesc->typeConst;

    mRootElem->mapNameDesc.insert(TMapStrDescPrivateVT(itDesc->name, pDescPrivate));
    mRootElem->vecSlaveDesc.push_back(pDescPrivate);
    bit++;
  }
}
//--------------------------------------------------------------------
void TMarkUpContainer::EnterRoot()
{
  BL_ASSERT(mRootElem);
  mCurElem = mRootElem;
}
//--------------------------------------------------------------------
bool TMarkUpContainer::Enter(const char* name, int indexElem)
{
  TMapStrDescPrivateIt fit = mCurElem->mapNameDesc.find(name);
  if(fit==mCurElem->mapNameDesc.end())
  {
    BL_FIX_BUG();
    return false;
  }

  if(fit->second->GetSelfType()!=eArr)
  {
    BL_FIX_BUG();
    return false;
  }
  
  if(indexElem >= int(fit->second->vecSlaveElem.size()))
  {
    BL_FIX_BUG();
    return false;
  }
  
  mCurElem = fit->second->vecSlaveElem[indexElem];
  return true;
}
//--------------------------------------------------------------------
void TMarkUpContainer::Leave()
{
  if((mRootElem==NULL) || 
     (mCurElem ==NULL))
  {
    BL_FIX_BUG();
    return;
  }
  if(mCurElem==mRootElem) 
    return;
  
  if(mCurElem->pMasterDesc==NULL)
  {
    BL_FIX_BUG();
    return;
  }

  mCurElem = mCurElem->pMasterDesc->pMasterElem ;
  BL_ASSERT(mCurElem);
}
//--------------------------------------------------------------------
int TMarkUpContainer::GetCountDesc()
{
  if(mCurElem==NULL)
    return 0;
  return mCurElem->vecSlaveDesc.size();
}
//--------------------------------------------------------------------
std::string TMarkUpContainer::GetNameDesc(int indexDesc)
{
  if(mCurElem==NULL)
    return "";

  return mCurElem->vecSlaveDesc[indexDesc]->pDesc->name;
}
//--------------------------------------------------------------------
IMarkUpContainer::eType TMarkUpContainer::GetTypeDesc(int indexDesc)
{
  if(mCurElem==NULL)
    return eUndef;

  return mCurElem->vecSlaveDesc[indexDesc]->GetSelfType();//GetTypeDescByIndex(indexDesc);
}
//--------------------------------------------------------------------
void TMarkUpContainer::SetCount(int indexDesc, int cnt)
{
  if(mCurElem==NULL)
  {
    BL_FIX_BUG();
    return;
  }

  TDescPrivate* pDescPrivate = mCurElem->vecSlaveDesc[indexDesc];
  memcpy(pDescPrivate->data.GetPtr(), &cnt, pDescPrivate->data.GetSize());

  pDescPrivate->DeleteAllElem();
  for( int i = 0 ; i < cnt ; i++ )
    pDescPrivate->AddElem();
}
//--------------------------------------------------------------------
int TMarkUpContainer::GetCount(int indexDesc)
{
  if(mCurElem==NULL)
  {
    BL_FIX_BUG();
    return 0;
  }

  int cnt = 0;
  memcpy(&cnt, mCurElem->vecSlaveDesc[indexDesc]->data.GetPtr(), 
               mCurElem->vecSlaveDesc[indexDesc]->data.GetSize());
  return cnt;
}
//--------------------------------------------------------------------
void TMarkUpContainer::SetCount(const char* name, int cnt)
{
  if(mCurElem==NULL)
  {
    BL_FIX_BUG();
    return;
  }

  TMapStrDescPrivateIt fit = mCurElem->mapNameDesc.find(name);
  if(fit==mCurElem->mapNameDesc.end())
    return;
  TDescPrivate* pDescPrivate = fit->second;
  memcpy(pDescPrivate->data.GetPtr(), &cnt, pDescPrivate->data.GetSize());

  pDescPrivate->DeleteAllElem();
  for( int i = 0 ; i < cnt ; i++ )
    pDescPrivate->AddElem();
}
//--------------------------------------------------------------------
int TMarkUpContainer::GetCount(const char* name)
{
  if(mCurElem==NULL)
  {
    BL_FIX_BUG();
    return 0;
  }

  TMapStrDescPrivateIt fit = mCurElem->mapNameDesc.find(name);
  if(fit==mCurElem->mapNameDesc.end())
    return 0;

  int cnt = 0;
  memcpy(&cnt, fit->second->data.GetPtr(), fit->second->data.GetSize());
  return cnt;
}
//--------------------------------------------------------------------
void* TMarkUpContainer::GetPtrConst(int indexDesc)
{
  if(mCurElem==NULL)
    return NULL;

  return mCurElem->vecSlaveDesc[indexDesc]->data.GetPtr();
}
//--------------------------------------------------------------------
void* TMarkUpContainer::GetPtrConst(const char* name)
{
  if(mCurElem==NULL)
    return NULL;

  TMapStrDescPrivateIt fit = mCurElem->mapNameDesc.find(name);
  if(fit==mCurElem->mapNameDesc.end())
    return NULL;
  return fit->second->data.GetPtr();
}
//--------------------------------------------------------------------
int TMarkUpContainer::GetSizeConst(int indexDesc)
{
  if(mCurElem==NULL)
    return 0;

  return mCurElem->vecSlaveDesc[indexDesc]->data.GetSize();
}
//--------------------------------------------------------------------
int TMarkUpContainer::GetSizeConst(const char* name)
{
  if(mCurElem==NULL)
    return 0;

  TMapStrDescPrivateIt fit = mCurElem->mapNameDesc.find(name);
  if(fit==mCurElem->mapNameDesc.end())
    return 0;
  return fit->second->data.GetSize();
}
//--------------------------------------------------------------------
std::string TMarkUpContainer::GetTypeConst(int indexDesc)
{
  if(mCurElem==NULL)
    return "";

  return mCurElem->vecSlaveDesc[indexDesc]->typeConst;
}
//--------------------------------------------------------------------
std::string TMarkUpContainer::GetTypeConst(const char* name)
{
  if(mCurElem==NULL)
    return "";

  TMapStrDescPrivateIt fit = mCurElem->mapNameDesc.find(name);
  if(fit==mCurElem->mapNameDesc.end())
    return "";
  return fit->second->typeConst;
}
//--------------------------------------------------------------------
void TMarkUpContainer::Collect()
{
  if(mRootElem==NULL)
    return;

  mBP.UnlinkPart();
  mRootElem->AddData(&mBP);
  mBP.Collect();
}
//--------------------------------------------------------------------
void* TMarkUpContainer::GetPtr()
{
  return mBP.GetCollectPtr();
}
//--------------------------------------------------------------------
int TMarkUpContainer::GetSize()
{
  return mBP.GetSize();
}
//--------------------------------------------------------------------
int TMarkUpContainer::Set(void* p, int size)
{
  return mRootElem->Set((char*)p,size);
}
//====================================================================
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//--------------------------------------------------------------------
TMarkUpContainer::TElem::TElem()
{
  pMasterDesc = NULL;
}
//--------------------------------------------------------------------
TMarkUpContainer::TElem::~TElem()
{
  pMasterDesc = NULL;

  int cnt = vecSlaveDesc.size();
  for( int i = 0 ; i < cnt ; i++ )
    delete vecSlaveDesc[i];
  vecSlaveDesc.clear();
}
//--------------------------------------------------------------------
TMarkUpContainer::TDescPrivate::TDescPrivate()
{
  pDesc       = NULL;
  pMasterElem = NULL;
}
//--------------------------------------------------------------------
TMarkUpContainer::TDescPrivate::~TDescPrivate()
{
  pDesc = NULL;
  pMasterElem = NULL;

  int cnt = vecSlaveElem.size();// индексация
  for( int i = 0 ; i < cnt ; i++ )
    delete vecSlaveElem[i];
  vecSlaveElem.clear();
}
//--------------------------------------------------------------------
void TMarkUpContainer::TDescPrivate::AddData(TBreakPacket* pBP)
{
  pBP->PushBack(data.GetPtr(), data.GetSize());
  int cnt = vecSlaveElem.size();
  for( int i = 0 ; i < cnt ; i++ )
    vecSlaveElem[i]->AddData(pBP);
}
//--------------------------------------------------------------------
void TMarkUpContainer::TElem::AddData(TBreakPacket* pBP)
{
  int cnt = vecSlaveDesc.size();
  for( int i = 0 ; i < cnt ; i++ )
    vecSlaveDesc[i]->AddData(pBP);
}
//--------------------------------------------------------------------
IMarkUpContainer::eType TMarkUpContainer::TDescPrivate::GetTypeDescByIndex(int indexDesc)
{
  std::list<TDesc*>::iterator bit = pDesc->list.begin();
  std::list<TDesc*>::iterator eit = pDesc->list.end();
  int i = 0;
  while(bit!=eit)
  {
    if(i==indexDesc)
    {
      if((*bit)->list.size())
        return eArr;
      return eConst;
    }
    bit++;
    i++;
  }
  return eArr;
}
//--------------------------------------------------------------------
IMarkUpContainer::eType TMarkUpContainer::TDescPrivate::GetSelfType()
{
  if((pDesc->list.size()  ==0) && 
     (data.GetSize()      ==0) &&
     (pDesc->name.length()==0))
    return eUndef;
  if((pDesc->list.size()  ==0) && 
     (data.GetSize()      ==0))
    return eRoot;

  BL_ASSERT(data.GetSize());// либо под cnt, либо под const

  if(pDesc->list.size())
    return eArr;

  return eConst;
}
//--------------------------------------------------------------------
void TMarkUpContainer::TDescPrivate::DeleteAllElem()
{
  int cnt = vecSlaveElem.size();
  for( int i = 0 ; i < cnt ; i++ )
    delete vecSlaveElem[i];
  vecSlaveElem.clear();
}
//--------------------------------------------------------------------
void TMarkUpContainer::TDescPrivate::AddElem()
{
  TElem* pElem = new TElem;
  pElem->pMasterDesc = this;
  
  std::list<TDesc*>::iterator bit = pDesc->list.begin();
  std::list<TDesc*>::iterator eit = pDesc->list.end();

  while(bit!=eit)
  {
    TDesc* pItDesc = *bit;
    TDescPrivate* pDescPrivate = new TDescPrivate;
    pDescPrivate->data.SetData(NULL, pItDesc->size);
    memset(pDescPrivate->data.GetPtr(), 0, pDescPrivate->data.GetSize());
    pDescPrivate->pDesc = pItDesc;
    pDescPrivate->pMasterElem = pElem;
    pDescPrivate->typeConst = pItDesc->typeConst;

    pElem->mapNameDesc.insert(TMapStrDescPrivateVT(pItDesc->name, pDescPrivate));
    pElem->vecSlaveDesc.push_back(pDescPrivate);

    bit++;
  }

  vecSlaveElem.push_back(pElem);
}
//--------------------------------------------------------------------
int TMarkUpContainer::TElem::Set(char* p, int size)
{
  int inputSize = size;
  int cnt = vecSlaveDesc.size();
  for( int i = 0 ; i < cnt ; i++ )
  {
    int spend = vecSlaveDesc[i]->Set(p, size);
    if(spend==-1)
      return -1;
    size -= spend;
    p    += spend;
  }
  return inputSize - size;
}
//--------------------------------------------------------------------
int TMarkUpContainer::TDescPrivate::Set(char* p, int size)
{
  int inputSize = size;
  int sizeData = data.GetSize();
  memcpy(data.GetPtr(), p, sizeData);
  size -= sizeData;
  p    += sizeData;

  if(GetSelfType()==eArr)
  {
    int cntElem = 0;
    memcpy(&cntElem, data.GetPtr(), data.GetSize());
    for( int i = 0 ; i < cntElem ; i++ )
    {
      AddElem();
      int spend = vecSlaveElem[i]->Set(p, size);
      if(spend==-1)
        return -1;
      size -= spend;
      p    += spend;
    }
  }
  return inputSize - size;
}
//--------------------------------------------------------------------
