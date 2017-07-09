/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HierarchyNode_ModelH
#define HierarchyNode_ModelH

#include "TypeDef.h"
#include <map>
#include <vector>

class TBaseNode_Model;

// Задача класса:
// иерархия насыщается нодами, потом располагаем их

class DllExport THierarchyNode_Model
{
	typedef std::vector<std::string> TVecStr;
	typedef TVecStr::iterator TVecStrIt;

	struct DllExport THierarchyNode
	{
		TBaseNode_Model* pNode;

		std::string nameParent;

		TVecStr vecNameChild;
		THierarchyNode(){pNode=NULL;}
	};

	typedef std::map<std::string,THierarchyNode> TMapStrPtr;
	typedef TMapStrPtr::iterator   							 TMapStrPtrIt;
	typedef TMapStrPtr::value_type 						   TMapStrPtrVT;

	TMapStrPtr mMapNamePart_Node;
	THierarchyNode* mRoot;
public:
	THierarchyNode_Model();
	virtual ~THierarchyNode_Model();

	// насыщение данными
	void Add(TBaseNode_Model* pNode);
	void Remove(std::string namePart);
	void Clear();

	// доступ
	int GetCount();
	TBaseNode_Model* Get(int index);
	TBaseNode_Model* Get(std::string namePart);

	// установка корня
	void SetRoot(std::string namePart);
	TBaseNode_Model* GetRoot();
	
	// кто родитель?
	TBaseNode_Model* GetParent(std::string namePart);
	// список детей
	int GetCountChild(std::string namePart);
	TBaseNode_Model* GetChild(std::string namePart, int index);

	// цепляем кого-то к кому-то
	void LinkToRoot(std::string namePart);
	void Link(std::string namePartChild, std::string namePartParent);
	// отцепиться
	void UnlinkFromParent(std::string namePart);
	void UnlinkAll();

protected:
	THierarchyNode* Get_private(std::string namePart);

	void RemoveChild(THierarchyNode* pHNode, std::string nameChild);
};

#endif
