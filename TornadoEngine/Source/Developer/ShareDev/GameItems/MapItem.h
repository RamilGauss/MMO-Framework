/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
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
	typedef std::map<std::string,std::string> TMapStrStr;
	typedef TMapStrStr::iterator   						TMapStrStrIt;
	typedef TMapStrStr::const_iterator   			TMapStrStrConstIt;
	typedef TMapStrStr::value_type 						TMapStrStrVT;

	struct DllExport TObject
	{
		// base parameters
    std::string namePattern;
    int         id;
		nsMathTools::TVector3 position;
		nsMathTools::TVector3 rotation;

		TMapStrStr parameterMap;
	};
  typedef std::list<TObject> TListObject;

	struct TFog
	{
		int mode;
		nsMathTools::TVector3 colour;
		float expDensity;
		float linearStart;
    float linearEnd;
	};

	std::string mNameTableSound;
	nsMathTools::TVector3 mGravity;
	TFog mFog;
	TListObject mListObject;
	nsMathTools::TVector3 mBackgroundColour;
	nsMathTools::TVector3 mAmbientLight;

  TMapItem(std::string& name);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
