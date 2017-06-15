/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseNode_ModelH
#define BaseNode_ModelH

#include "TypeDef.h"
#include "MathTools.h"
#include <OgreEntity.h>
#include "ModelItem.h"

// TODO требует доработки! ->ShapeNode_Model + ModelNode_Model

class DllExport TBaseNode_Model
{
public:
	TModelItem::eType type;
	std::string namePart;
	std::string nameVariant;

	TBaseNode_Model* mNodeUp;

	typedef std::map<std::string,TBaseNode_Model*> TMapStrPtr;
	typedef TMapStrPtr::iterator   TMapStrPtrIt;
	typedef TMapStrPtr::value_type TMapStrPtrVT;

	TMapStrPtr mNameNodeDown;

	// расположение относительно Up
	nsMathTools::TVector3 mPos;
	nsMathTools::TVector4 mOrient;
public:
	TBaseNode_Model();
	virtual ~TBaseNode_Model();

};

#endif
