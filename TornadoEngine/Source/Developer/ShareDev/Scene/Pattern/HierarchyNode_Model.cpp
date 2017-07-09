/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HierarchyNode_Model.h"
#include "BaseNode_Model.h"
#include "BL_Debug.h"

THierarchyNode_Model::THierarchyNode_Model()
{
	mRoot = NULL;
}
//-----------------------------------------------------------------------------
THierarchyNode_Model::~THierarchyNode_Model()
{

}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::Add(TBaseNode_Model* pNode)
{
	THierarchyNode hNode;
	hNode.pNode = pNode;
	if( Get(pNode->namePart)==NULL )
		mMapNamePart_Node.insert(TMapStrPtrVT(pNode->namePart,hNode));
	else
		mMapNamePart_Node[pNode->namePart] = hNode;
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::Remove(std::string namePart)
{
	THierarchyNode* pHNode = Get_private(namePart);
	if( pHNode==NULL )
		return;
	if( pHNode==mRoot ) 
		mRoot = NULL;
	mMapNamePart_Node.erase(namePart);
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::Clear()
{
	mRoot = NULL;
	mMapNamePart_Node.clear();
}
//-----------------------------------------------------------------------------
TBaseNode_Model* THierarchyNode_Model::Get(std::string namePart)
{
	TMapStrPtrIt fit = mMapNamePart_Node.find(namePart);
	if( fit==mMapNamePart_Node.end() )
		return NULL;

	return fit->second.pNode;
}
//-----------------------------------------------------------------------------
TBaseNode_Model* THierarchyNode_Model::Get(int index)
{
	if( index < 0          ||
		  index >= GetCount())
		return NULL;

	TMapStrPtrIt bit = mMapNamePart_Node.begin();
	for( int i = 0 ; i < index ; i++ )
		bit++;
	return bit->second.pNode;
}
//-----------------------------------------------------------------------------
int THierarchyNode_Model::GetCount()
{
	return mMapNamePart_Node.size();
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::SetRoot(std::string namePart)
{
	THierarchyNode* pHNode = Get_private(namePart);
	mRoot = pHNode;
}
//-----------------------------------------------------------------------------
TBaseNode_Model* THierarchyNode_Model::GetRoot()
{
	if( mRoot==NULL )
		return NULL;
	return mRoot->pNode;
}
//-----------------------------------------------------------------------------
TBaseNode_Model* THierarchyNode_Model::GetParent(std::string namePart)
{
	THierarchyNode* pHNode = Get_private(namePart);
	if( pHNode==NULL )
		return NULL;
	pHNode = Get_private(pHNode->nameParent);
	if( pHNode==NULL )
		return NULL;
	return pHNode->pNode;
}
//-----------------------------------------------------------------------------
int THierarchyNode_Model::GetCountChild(std::string namePart)
{
	THierarchyNode* pHNode = Get_private(namePart);
	if( pHNode==NULL )
		return 0;
	return pHNode->vecNameChild.size();
}
//-----------------------------------------------------------------------------
TBaseNode_Model* THierarchyNode_Model::GetChild(std::string namePart, int index)
{
	THierarchyNode* pHNode = Get_private(namePart);
	if( pHNode==NULL )
		return NULL;
	std::string nameChild = pHNode->vecNameChild[index];
	pHNode = Get_private(nameChild);
	if( pHNode==NULL )
		return 0;
	return pHNode->pNode;
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::LinkToRoot(std::string namePart)
{
	if( mRoot==NULL )
	{
		BL_FIX_BUG();
		return;
	}

	Link(namePart, mRoot->pNode->namePart);
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::Link(std::string namePartChild, std::string namePartParent)
{
	THierarchyNode* pHNodeChild  = Get_private(namePartChild);
	THierarchyNode* pHNodeParent = Get_private(namePartParent);
	if( pHNodeChild==NULL ||
		  pHNodeParent==NULL )
	{
		BL_FIX_BUG();
		return;
	}
	pHNodeChild->nameParent = namePartParent;
	RemoveChild(pHNodeParent,namePartChild);
	pHNodeParent->vecNameChild.push_back(namePartChild);
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::UnlinkFromParent(std::string namePart)
{
	THierarchyNode* pHNode = Get_private(namePart);
	if( pHNode==NULL )
	{
		BL_FIX_BUG();
		return;
	}

	THierarchyNode* pHNodeParent = Get_private(pHNode->nameParent);
	if( pHNodeParent )
		RemoveChild(pHNodeParent, namePart);

	pHNode->nameParent = "";
}
//-----------------------------------------------------------------------------
THierarchyNode_Model::THierarchyNode* THierarchyNode_Model::Get_private(std::string namePart)
{
	TMapStrPtrIt fit = mMapNamePart_Node.find(namePart);
	if( fit==mMapNamePart_Node.end() )
		return NULL;

	return &(fit->second);
}
//-----------------------------------------------------------------------------
void THierarchyNode_Model::RemoveChild(THierarchyNode* pHNode, std::string nameChild)
{
	TVecStrIt bit = pHNode->vecNameChild.begin();
	TVecStrIt eit = pHNode->vecNameChild.end();
	while( bit!=eit )
	{
		std::string nameChildIndex = *bit;
		if( nameChildIndex==nameChild )
			pHNode->vecNameChild.erase(bit);
		bit++;
	}
}
//-----------------------------------------------------------------------------
