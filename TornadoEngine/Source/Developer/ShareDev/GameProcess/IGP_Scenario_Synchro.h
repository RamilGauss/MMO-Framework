/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_Scenario_SynchroH
#define IGP_Scenario_SynchroH

#include "TypeDef.h"
#include "MapItem.h"

class TGameObject;

class DllExport IGP_Scenario_Synchro
{
public:
  IGP_Scenario_Synchro();
  virtual ~IGP_Scenario_Synchro();

	// atomic operation, результат сразу после вызова методов
	virtual TGameObject* AddGameObject(TMapItem::TObject* pObject) = 0;
	virtual bool DeleteGameObject(int id) = 0;

  // сохранить любые изменения в карте
  virtual void SaveMap(std::string nameMap) = 0;

  // ниже реализуется только через сам объект
	//virtual void UpdateGameItemByGameObject(int id) = 0;
	//virtual void UpdateGameObjectByGameItem(int id) = 0;
};

#endif
