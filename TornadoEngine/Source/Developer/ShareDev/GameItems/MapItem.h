/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef MapItemH
#define MapItemH

#include "BaseItem.h"
#include <map>
#include <string>
#include "MathTools.h"
#include <list>

#ifdef WIN32
#pragma pack(push, 1)
#endif

struct DllExport TMapItem : public TBaseItem
{
  struct DllExport TPatternConfig
  {
    std::string name;
    std::string nameVariant;
  };
  struct DllExport TObject
  {
    std::string namePattern;
    int         id;
    nsMathTools::TVector3  position;
    nsMathTools::TMatrix16 orientation;

    TPatternConfig patternConfig;
  };
  typedef std::list<TObject> TListObject;

  TListObject mListObject;

  TMapItem(std::string& name);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
