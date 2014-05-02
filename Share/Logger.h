/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef LoggerH 
#define LoggerH

#include "SaveToFile.h"
#include <map>
#include <string>
#include "Only_N_Object.h"
#include "TypeDef.h"

class SHARE_EI TLogger : public TOnly_N_Object
{
	typedef std::vector<TSaveToFile*> TVectorPtr;
	TVectorPtr mVecPtr;

  typedef std::map<std::string,TSaveToFile*> TMapStrPtr;
  TMapStrPtr mMapNamePtr;

  std::string sPrefix;

  bool flgPrintf;
  bool flgEnable;
  bool flgBuffer;

protected:
  TLogger():                            // запрет на создание
         TOnly_N_Object(1,NAME_CLASS)
         {
           flgPrintf = true;
           flgEnable = true;
           flgBuffer = true;
         }// только один объект
public:

  virtual ~TLogger();

  void Register(const char* nameLogger);

  void Init(char* sPrefix);
  void Done();
  TSaveToFile* Get(const char* nameLog);

  void SetPrintf(bool val);
  bool GetPrintf();

  void SetEnable(bool val);
  bool GetEnable();

  void SetBufferization(bool val);
  bool GetBufferization();

	int GetCount();
	TSaveToFile* GetByIndex( int index);

protected:
  void InitLogger(TSaveToFile* saver, const char* sName);
};

extern SHARE_EI TLogger* GetLogger();
extern SHARE_EI TSaveToFile* GetLogger(const char* nameLog);


#endif 