/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "Resources.h"
#include "IXML.h"

namespace nsResources
{
  const char* sResource = "Resource";

  const char* sPath = "Path";
  const char* sType = "Type";
}

using namespace nsResources;

TResources::TResources()
{
  mXML = NULL;
}
//--------------------------------------------------------------------------
TResources::~TResources()
{

}
//--------------------------------------------------------------------------
bool TResources::Work(IXML* pXML)
{
	mMapTypePath.clear();
  strError = "";
  mXML = pXML;

  if(LoadResources()==false)
  {
    strError = "Resources";
    return false;
  }
  return true;
}
//--------------------------------------------------------------------------
void TResources::GetResource(TMMapStrStr& mapTypePath)
{
	mapTypePath = mMapTypePath;
}
//--------------------------------------------------------------------------
std::string TResources::GetStrError()
{
  return strError;
}
//--------------------------------------------------------------------------
void TResources::ErrorNoSection(const char* section)
{
  char s[200];
  sprintf(s, "Нет секции %s", section);
  strError = s;
}
//--------------------------------------------------------------------------
bool TResources::LoadResources()
{
  int cntResource = mXML->GetCountSection(sResource);
  for( int iResource = 0 ; iResource < cntResource ; iResource++ )
  {
    std::string path = mXML->ReadSectionAttr(sResource, iResource, sPath);
    std::string type = mXML->ReadSectionAttr(sResource, iResource, sType);

		mMapTypePath.insert(TMMapStrStrVT(type,path));
  }
  return true;
}
//--------------------------------------------------------------------------
