/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerXML.h"
#include "MapXML_Field.h"

using namespace std;

TMapXML_Field::TMapXML_Field()
{
  TMakerXML makerXML;
  mXML = makerXML.New();
}
//--------------------------------------------------------------------------------------
TMapXML_Field::~TMapXML_Field()
{
  TMakerXML makerXML;
  makerXML.Delete(mXML);
  mXML = NULL;
}
//--------------------------------------------------------------------------------------
bool TMapXML_Field::Load(const char* sAbsPath)
{
  bool res = true;
  RET_FALSE(mXML->Load(sAbsPath))
  mMap.clear();
  string sRoot = mXML->GetNameSection(0);
  if(sRoot.length()==0) return false;
  RET_FALSE(mXML->EnterSection(sRoot.data(),0))
  int cntChild = mXML->GetCountSection();
  for(int i = 0 ; i < cntChild ; i++)
  {
    string sChild = mXML->GetNameSection(i);
    string sPath = mXML->ReadSection(i);
    mMap.insert(TMultiMapStrStr::value_type(sChild,sPath));
  }

  RET_FALSE(mXML->LeaveSection());
  return res;
}
//--------------------------------------------------------------------------------------
const char* TMapXML_Field::GetSecond(const char* name, unsigned int index)
{
  unsigned int cnt = GetCount(name);
  if(cnt<index+1) return NULL;// перебор

  TMultiMapStrStr::iterator fit = mMap.lower_bound(name);
  for(unsigned int i = 0 ; i < index ; i++)
    fit++;
  return fit->second.data();
}
//--------------------------------------------------------------------------------------
unsigned int TMapXML_Field::GetCount(const char* name)
{
  return mMap.count(name);
}
//--------------------------------------------------------------------------------------
