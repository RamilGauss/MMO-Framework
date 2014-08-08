/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <map>
#include <string>

#include "Only_N_Object.h"
#include "GCS.h"

typedef std::map<std::string,int> TMapStrInt;
typedef std::map<void*,std::string> TMapPtrStr;
//----------------------------------------------------------------------------
namespace nsStoreObject
{
  enum{ePush=0,ePop=1,};
}
namespace nsLockThread
{
  enum{eLock=0,eUnlock=1,};
}
//----------------------------------------------------------------------------
void LockThread(int lock);
void StoreObject(int i, int maxCntObject, std::string nameClass, void* pThis);
//----------------------------------------------------------------------------
TOnly_N_Object::TOnly_N_Object(int maxCntObject, std::string nameClass)
{
  StoreObject(nsStoreObject::ePush,maxCntObject,nameClass,this);
}
//----------------------------------------------------------------------------
TOnly_N_Object::~TOnly_N_Object()
{
  StoreObject(nsStoreObject::ePop,0,"",this);
}
//----------------------------------------------------------------------------
// like C-style
void StoreObject(int i, int maxCntObject, std::string nameClass, void* pThis)
{
  static TMapStrInt mMapClassCnt;// для нахождения по имени класса макс. кол-ва объектов
  static TMapPtrStr mMapPtrName; //                по указателю на объект имя класса
  int cntMake = 0;
  bool res = false;

  LockThread(nsLockThread::eLock);// блокировка
  switch(i)
  {
    case nsStoreObject::ePush:
    {
      //-------------------------------
      TMapStrInt::iterator fit = mMapClassCnt.find(nameClass);
      if(fit==mMapClassCnt.end())
      {
        // не нашли - добавить
        mMapClassCnt.insert(TMapStrInt::value_type(nameClass,1));
        fit = mMapClassCnt.find(nameClass);

        // что бы потом найти в деструкторе
        mMapPtrName.insert(TMapPtrStr::value_type(pThis,nameClass));
      }
      else
        fit->second++;

      cntMake = fit->second;
    }
    break;
    case nsStoreObject::ePop:
    {
      //-------------------------------
      TMapPtrStr::iterator fit_name = mMapPtrName.find(pThis);
      if(fit_name!=mMapPtrName.end())
      {
        TMapStrInt::iterator fit = mMapClassCnt.find(fit_name->second);
        if(fit!=mMapClassCnt.end())
        {
          fit->second--;
          cntMake = fit->second;
          res = true;
        }
      }
    }
    break;
  }
  LockThread(nsLockThread::eUnlock);// разблокировать
  // проверка результатов
  switch(i)
  {
    case nsStoreObject::ePush:
      BL_ASSERT(cntMake <= maxCntObject);
      break;
    case nsStoreObject::ePop:
      BL_ASSERT(cntMake >= 0 && res);
      break;
  }
}
//----------------------------------------------------------------------------
void LockThread(int lock)
{
  static GCS gcs;
  switch(lock)
  {
    case nsLockThread::eLock:
      gcs.lock();
      break;
    case nsLockThread::eUnlock:
      gcs.unlock();
      break;
  }
}
//----------------------------------------------------------------------------
