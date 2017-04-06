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
//#include "DataExchange2Thread.h"
//#include "GameObject.h"
#include "CallBackRegistrator.h"
//#include "ListModules.h"

#include <string>
#include <vector>
#include <set>

#include "BuilderGameMap_Object.h"
#include "BuilderGameMap_Param.h"

class TFactoryBehaviourPatternModel;

class DllExport TBuilderGameMap
{
  TFactoryBehaviourPatternModel* mFactoryBehaviourPattern;
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

	void Init(std::set<int>& useID_Module, TFactoryBehaviourPatternModel* pFBP, int id_world);
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

