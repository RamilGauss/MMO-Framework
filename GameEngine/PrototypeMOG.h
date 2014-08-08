/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMOGH
#define PrototypeMOGH

#include "PrototypeBaseModule.h"
#include <vector>
#include "TypeDef.h"

class IBaseObjectGeneral;
class PrototypeMakerObjectGeneral;

class DllExport PrototypeMOG : public PrototypeBaseModule
{
public:
  // события внутри объекта
  typedef enum
  {
    eBeginLoadMap = 0,
    eLoadingMap10,       // каждые 10% от прогресса загрузки
    eEndLoadMap,
    eStoppedLoadMap,
    //---------------------------
    eErrorLoadMap,
  }tEvent;

  PrototypeMOG();
  virtual ~PrototypeMOG();

  virtual void Init(PrototypeMakerObjectGeneral* pMakerObjectGeneral) = 0;
  virtual void Clear() = 0;// убить все объекты
  virtual void Done() = 0; // работа с Менеджером закончена
  virtual void LoadMap(unsigned int id_map) = 0;// загрузить карту в параллельном потоке
  virtual int  GetProgressLoadMap() = 0;// прогресс загрузки карты
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model) = 0;

  virtual void AddObject(IBaseObjectGeneral* pObject) = 0;// отдать на контроль
  virtual IBaseObjectGeneral* Get(int index) = 0;// отдать объект на изменение свойств (в основном для отладки)
  virtual int GetCountObject() = 0;

  virtual int GetVersionPrototype();
};

#endif
