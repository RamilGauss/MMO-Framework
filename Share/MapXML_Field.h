/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MapXML_FieldH
#define MapXML_FieldH

#include <map>
#include <string>
#include "IXML.h"
#include "TypeDef.h"

#ifdef WIN32
#pragma warning(disable:4251)
#endif

class SHARE_EI TMapXML_Field
{
  typedef std::multimap<std::string,std::string> TMultiMapStrStr;

  TMultiMapStrStr mMap;

  IXML* mXML;
    
public:

  TMapXML_Field();
  virtual ~TMapXML_Field();
  
  // зугрузить XML
  bool Load(const char* sAbsPath);

  // вернуть по ключу значение 
	const char* GetSecond(const char* name, unsigned int index = 0);
  unsigned int GetCount(const char* name);

protected:
};

#endif