/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerNode_ModelH
#define ManagerNode_ModelH

#include "TypeDef.h"
#include <string>
#include <map>

class TBaseNode_Model;

class DllExport TManagerNode_Model
{
	typedef std::map<std::string,TBaseNode_Model*> TMapStrPtr;
	typedef TMapStrPtr::iterator   								 TMapStrPtrIt;
	typedef TMapStrPtr::value_type 								 TMapStrPtrVT;

	typedef std::map<std::string,TMapStrPtr> TMapStrMap;
	typedef TMapStrMap::iterator   					 TMapStrMapIt;
	typedef TMapStrMap::value_type 					 TMapStrMapVT;


	TMapStrMap mMapPartVariant_NodePtr;
public:
	TManagerNode_Model();
	virtual ~TManagerNode_Model();

	void Add(TBaseNode_Model* p);
	void Remove(std::string namePart, std::string nameVariant);
	TBaseNode_Model* Get(std::string namePart, std::string nameVariant);

	int GetCountPart();
	std::string GetNamePart(int index);

	int GetCountVariant(std::string namePart);
	std::string GetNameVariant(std::string namePart, int index);
};

#endif
