/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SaveToFileH
#define SaveToFileH


#include <stdio.h>
#include <vector>

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "ListPtr.h"
#include "InfoFile.h"

/*
  Сохранение файла. 
  Вывод в консоль.
  Буферизация при отсутствии открытого файла.
*/

class DllExport TSaveToFile : public InfoFile
{
  bool flgPrintf;
  bool flgEnable;
  bool flgBuffer;

  typedef TListPtr<TContainer> TListContainer;
  
  TListContainer mListBuffer;

  enum{eMaxNumberForBufferization=5000};

public:

	TSaveToFile(char* path = NULL);
	virtual ~TSaveToFile();

  // в случае append==false - стирает содержимое файла
	virtual bool ReOpen(char* path, bool append = false );

	virtual void Write(void* buffer, int size);
  // форматированная строка, по типу printf(...)
  virtual void WriteF(const char* format, ... );
  virtual void WriteF_time(const char* format, ... );


  void SetPrintf(bool val){flgPrintf=val;};// все что записывается - дублируется в вывод на консоль
  bool GetPrintf(){return flgPrintf;};     // но только для форматированной строки

  void SetEnable(bool val){flgEnable=val;};// отмена применения в Write, WriteF, WriteF_time
  bool GetEnable(){return flgEnable;};

  void SetBufferization(bool val){flgBuffer=val;};// буферизация, без открытого файла все складируется в памяти
  bool GetBufferization(){return flgBuffer;};

protected:
  void Write_Time();

  void ClearBuffer();
  void FlushBuffer();
  void FlushInBuffer(char* buffer, int size);
};


#endif

