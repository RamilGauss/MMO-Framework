/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderGameMapH
#define BuilderGameMapH

#include "TypeDef.h"

#include "MapItem.h"
#include "CallBackRegistrator.h"

#include <string>
#include <vector>
#include <set>

#include "BuilderGameMap_Object.h"
#include "BuilderGameMap_Param.h"

class TFactoryBehaviourPattern;

class DllExport TBuilderGameMap
{
  TFactoryBehaviourPattern* mFactoryBehaviourPattern;
  int                       mPhysicWorldID;
  TMapItem*                 mMapItem;

	std::set<int> mUseID_Module;

	TBuilderGameMap_Param mBuilderGameMap_Param;

	TBuilderGameMap_Object mBuilderGameObject;

	typedef std::list<int> TListInt;
	typedef TListInt::iterator TListIntIt;
	
	TListInt mListID_BuiltObject;
public:
  TBuilderGameMap();
  virtual ~TBuilderGameMap();

	void Init(std::set<int>& useID_Module, TFactoryBehaviourPattern* pFBP, int id_world);
  bool BuildMap( TMapItem* pMI );

  int GetProgress();

	void Build();

  typedef std::list<TGameObject*> TListPtrGameObject;
  typedef TListPtrGameObject::iterator TListPtrGameObjectIt;
  void GetResult(TListPtrGameObject& listPtrGameObject);
private:

  TListPtrGameObject mListGameObject;
  
  void InitPhysic();

  TMapItem::TListObject::iterator mBeginIteratorMapObject;
};

#endif

