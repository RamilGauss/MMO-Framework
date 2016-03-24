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

struct DllExport TMapItem : public TBaseItem
{
	typedef std::map<std::string,std::string> TMapStrStr;
	typedef TMapStrStr::iterator   						TMapStrStrIt;
	typedef TMapStrStr::value_type 						TMapStrStrVT;

	struct DllExport TObject
	{
		// base property
		std::string type;
    int         id;
		nsMathTools::TVector3 position;
		nsMathTools::TVector3 rotation;

		TMapStrStr internalState;
	};

	typedef std::list<TObject> TListObject;

	TListObject mListObject;
	std::string mNameTableSound;
  nsMathTools::TVector3 mGravity;
  nsMathTools::TVector3 mCameraUp;

  TMapItem(std::string& name);
};

#endif
