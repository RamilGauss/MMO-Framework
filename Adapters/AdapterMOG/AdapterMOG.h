/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterMOGH
#define AdapterMOGH

#include "PrototypeMOG.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

class PrototypeMakerObjectGeneral;
class TLoaderObjectGeneral;
class IBaseObjectGeneral;

#define STR_NAME_MOG "MOG"

class DllExport AdapterMOG : public PrototypeMOG
{
protected:
  std::vector< IBaseObjectGeneral* > mVectorObject;

protected:
  enum{
    eLoadMapEnd=0,
  };

  unsigned int mID_map;

  volatile unsigned char mProcentLoadMap;
  
  volatile bool flgActiveLoadThread;// активность потока
  volatile bool flgLoadMap;         // процесс загрузки идет
  volatile bool flgNeedStopThreadLoadMap;    // необходимо остановить загрузку

protected:
  
  boost::scoped_ptr<TLoaderObjectGeneral> mLoaderObjectGeneral;

public:

  AdapterMOG();
  virtual ~AdapterMOG();

  virtual void Init(PrototypeMakerObjectGeneral* pMakerObjectGeneral);
  virtual void Done();
  virtual void Clear();
  virtual void LoadMap(unsigned int id_map);
  virtual int  GetProgressLoadMap();
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model);

  virtual void AddObject(IBaseObjectGeneral* pObject);// отдать на контроль
  virtual IBaseObjectGeneral* Get(int index);// отдать объект на изменение свойств (в основном для отладки)
  virtual int GetCountObject();

  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);

  virtual int GetVersionAdapter();
  virtual bool Work();
protected:

  //friend void* Thread(void*p);

  //void ThreadLoadMap();
  //void NotifyLoadMapEndEvent();

  // загрузить карту
  void EndLoadMap();// очень криво и отвратительно, что есть такой метод! но пока только так.
  void StopLoadMap();// синхронно, придется подождать маленько

};

#endif
