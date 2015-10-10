#include "IMarkUpContainer.h"

IMarkUpContainer::IMarkUpContainer()
{
  mRoot = NULL;
}
//-------------------------------------------------------------------
IMarkUpContainer::~IMarkUpContainer()
{
  delete mRoot;
}
//-------------------------------------------------------------------
IMarkUpContainer::TDesc::TDesc()
{
  size = 0;
  name = "Root";
}
//-------------------------------------------------------------------
IMarkUpContainer::TDesc::~TDesc()
{
  std::list<TDesc*>::iterator bit = list.begin();
  std::list<TDesc*>::iterator eit = list.end();
  while(bit!=eit)
  {
    delete *bit;
    bit++;
  }
  list.clear();
}
//-------------------------------------------------------------------
IMarkUpContainer::TDesc* IMarkUpContainer::TDesc::CloneHierarhy()
{
  TDesc* pNew = new TDesc;
  pNew->size = size;
  pNew->name = name;

  std::list<TDesc*>::iterator bit = list.begin();
  std::list<TDesc*>::iterator eit = list.end();
  while(bit!=eit)
  {
    pNew->list.push_back( (*bit)->CloneHierarhy() );
    bit++;
  }
  return pNew;
}
//-------------------------------------------------------------------
