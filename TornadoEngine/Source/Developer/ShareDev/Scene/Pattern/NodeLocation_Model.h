/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NodeLocation_ModelH
#define NodeLocation_ModelH

#include "TypeDef.h"
#include "MathTools.h"
#include <string>
#include <map>
#include <list>
#include "ParamBuilderConstraint.h"

// хотя лучше бы это была структура

class DllExport TNodeLocation_Model
{
public:
	struct DllExport TLocation
	{
		nsMathTools::TVector3    mPos;
		nsMathTools::TQuaternion mOrient;
	};
	struct DllExport TJoint
	{
		std::string name;
		TLocation mLocalRelativeNode;
		TLocation mGlobal;// результат для позиционирования
	};
	//------------------------------------------------------
	typedef std::map<std::string,TJoint> TMapStrJoint;
	typedef TMapStrJoint::iterator   		 TMapStrJointIt;
	typedef TMapStrJoint::value_type 		 TMapStrJointVT;

	// как соединить
	struct TLink
	{
		// геометрия
		std::string nameMyJointToParent;
		std::string nameJointParent;
		// настройка констрейнта
		nsParamBuilderConstraint::TBaseParam* mPtrConstraintToParent;

		TLink(){mPtrConstraintToParent=NULL;}
		~TLink(){DoneConstraint();}
		void SetConstraint(nsParamBuilderConstraint::TBaseParam* pConstraint)
		{
			DoneConstraint();
			nsParamBuilderConstraint::CopyConstraint(pConstraint,mPtrConstraintToParent);
		}
		void DoneConstraint()
		{
			delete mPtrConstraintToParent;
			mPtrConstraintToParent = NULL;
		}
	};

	typedef std::list<TLink*>      TListPtrLink;
	typedef TListPtrLink::iterator TListPtrLinkIt;

	std::string name;
	// ориентир как соединять
	std::string nameMyJointToParent;
	std::string nameJointParent;
	// параметры соединения
	nsMathTools::TQuaternion mOrientRelativeJointToJointParent;
	float mDistanceRelativeJointToJointParent;

	// описание констрейнтов как физически соединить с родителем
	TListPtrLink mListLink;

	TMapStrJoint mMapNameJoint;   // набор всех крючков
	TLocation    mGlobal;         // результат для позиционирования
public:
	TNodeLocation_Model();
	virtual ~TNodeLocation_Model();

	// для быстрых манипуляций с крючками
	void AddJoint(std::string nameJoint);
	int GetCountJoint();
	TJoint* GetJoint(int index);
	TJoint* GetJoint(std::string nameJoint);

	void RemoveJoint(std::string nameJoint);
	void RemoveAllJoint();

	void ClearListLink();

	void CalcGlobalJoint();
	void CalcGlobal(TNodeLocation_Model* pNodeLocationParent);
};

#endif
