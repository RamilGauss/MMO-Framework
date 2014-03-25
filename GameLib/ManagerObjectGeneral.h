/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerObjectGeneralH
#define ManagerObjectGeneralH

#include "LoaderObjectGeneral.h"
#include "IManagerObjectGeneral.h"

class IBaseObjectGeneral;

class TManagerObjectGeneral : public IManagerObjectGeneral
{
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
  
  TLoaderObjectGeneral mLoaderObjectGeneral;

public:

  TManagerObjectGeneral();
  virtual ~TManagerObjectGeneral();

  virtual void Init(IMakerObjectGeneral* pMakerObjectGeneral);
  virtual void Done();
  virtual void Clear();
  virtual void LoadMap(unsigned int id_map);
  virtual int  GetProgressLoadMap();
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model);

protected:

  //friend void* Thread(void*p);

  //void ThreadLoadMap();
  //void NotifyLoadMapEndEvent();

  // загрузить карту
  void EndLoadMap();// очень криво и отвратительно, что есть такой метод! но пока только так.
  void StopLoadMap();// синхронно, придетс€ подождать маленько

};

#endif
