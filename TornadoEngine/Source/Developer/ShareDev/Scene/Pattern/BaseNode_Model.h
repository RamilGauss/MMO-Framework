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

class DllExport TBaseNode_Model
{
public:
	TModelItem::eType type;
	std::string namePart;
	std::string nameVariant;

	struct TLocation
	{
		nsMathTools::TVector3    mPos;
		nsMathTools::TQuaternion mOrient;
	};
	// расположение относительно Parent
	TLocation mLocal;
	// помощник для построения модели
	TLocation mGlobal;
public:
	TBaseNode_Model();
	virtual ~TBaseNode_Model();

	// globalParent - глобальное положение и ориентация родителя, к которому цепляется данный нод
	void CalcGlobal(TLocation& globalParent);
};

#endif
