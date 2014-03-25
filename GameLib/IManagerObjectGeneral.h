/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IManagerObjectGeneralH
#define IManagerObjectGeneralH

#include "SrcEvent.h"
#include <vector>

#define STR_NAME_MOC "MOC"

class IBaseObjectGeneral;
class IMakerObjectGeneral;

class IManagerObjectGeneral : public TSrcEvent
{
protected:
  std::vector< IBaseObjectGeneral* > mVectorObject;

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

  IManagerObjectGeneral();
  virtual ~IManagerObjectGeneral();

  virtual void Init(IMakerObjectGeneral* _pMakerObjectGeneral) = 0;
  virtual void Clear() = 0;// убить все объекты
  virtual void Done() = 0; // работа с Менеджером закончена
  virtual void LoadMap(unsigned int id_map) = 0;// загрузить карту в параллельном потоке
  virtual int  GetProgressLoadMap() = 0;// прогресс загрузки карты
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model) = 0;

  void AddObject(IBaseObjectGeneral* pObject);// отдать на контроль
  IBaseObjectGeneral* Get(int index);// отдать объект на изменение свойств (в основном для отладки)
  int GetCountObject();

};

#endif
