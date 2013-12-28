/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GCSH
#define GCSH

#include <boost/thread/recursive_mutex.hpp>

#include "TypeDef.h"
//---------------------------------------------------------------------------
// надстройка над мьютексом
class SHARE_EI GCS
{
  boost::recursive_mutex m;

	const char* mDbgName;
public:
  GCS( const char * _dbgname = NULL );
  virtual ~GCS();

  void setDbgName( const char *_dbgname ) { mDbgName = _dbgname; }
  const char * dbgName() { return mDbgName; }

  bool tryLock();
  void lock();
  void unlock();
};

//---------------------------------------------------------------------------
// Класс автоматического блокиратора
// Обеспечивает вход в критическую секцию при создании объекта
// и выход из нее при удалении объекта.
// Предназначен для создания объектов на стеке
class TBL_Locker
{
  GCS* mCS;
public:
  TBL_Locker( GCS* cs )     { mCS = cs; mCS->lock(); }

  virtual ~TBL_Locker()             { done(); }

  void done()               { if( mCS ) { mCS->unlock(); mCS = NULL; } }
};

#define AUTO_LOCK( cs )     TBL_Locker locker( cs )
//===========================================================================


#endif // GCSH

