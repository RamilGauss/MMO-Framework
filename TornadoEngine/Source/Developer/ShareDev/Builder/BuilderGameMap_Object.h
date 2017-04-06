/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderGameMap_ObjectH
#define BuilderGameMap_ObjectH

#include "TypeDef.h"
#include "MapItem.h"
#include <set>
#include <map>

class TFactoryBehaviourPatternModel;
class TGameObject;

class DllExport TBuilderGameMap_Object
{
	int                            mID_World;
	TFactoryBehaviourPatternModel* mFBP;
	std::set<int>                  mSetID_Module;

	struct TObject
	{
		TGameObject*       ptrGameObject;// результат/result
		TMapItem::TObject* ptrMapObject; // задание/task

		bool flgLoadPhysic;
		bool flgLoadGraphic;
		bool flgLoadSound;

		TObject();

		bool IsComplete();
	};

	typedef std::map<int,TObject>     TMapIntObject;
	typedef TMapIntObject::iterator   TMapIntObjectIt;
	typedef TMapIntObject::value_type TMapIntObjectVT;

	TMapIntObject mMapID_BuildObject;

	std::string mNameMap;
public:
  TBuilderGameMap_Object();
  virtual ~TBuilderGameMap_Object();

	void Init(std::set<int>& useID_Module, 
		TFactoryBehaviourPatternModel* pFBP, int id_world);
	void SetNameMap(std::string nameMap);

	// return id built object
	int Begin(TMapItem::TObject* pObj);
	// return NULL or pointer of a built object by id
	TGameObject* Build(int idObject, bool fast = false);
private:
};

#endif
