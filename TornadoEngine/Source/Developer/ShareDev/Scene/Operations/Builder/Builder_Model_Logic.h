/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_Model_LogicH
#define Builder_Model_LogicH

#include "TypeDef.h"
#include "Builder_Model.h"
#include "ModelItem.h"

class TBaseNode_Model;
class TFactoryBehaviourPattern;
class TFactoryGameItem;

class DllExport TBuilder_Model_Logic : public TBuilder_Model
{
	TFactoryBehaviourPattern* mFBP;
	TFactoryGameItem*         mFGI;

	TModelItem*               mModelItem;
public:
	TBuilder_Model_Logic();
	virtual ~TBuilder_Model_Logic();

	virtual void Build();
protected:
	void Build_Private(TModelItem::TMapStrPart& mapNamePart);

	void BuildModels(std::string& namePart, TModelItem::TVariant& variant);
	void BuildShapes(std::string& namePart, TModelItem::TVariant& variant);

	void CalcGlobal(TBaseNode_Model* pNode);
	void CalcLocal();
};

#endif
