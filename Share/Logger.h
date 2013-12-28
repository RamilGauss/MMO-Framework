/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef LoggerH 
#define LoggerH

#include "SaveOnHDD.h"
#include <map>
#include <string>
#include "Only_N_Object.h"
#include "TypeDef.h"

class SHARE_EI TLogger : public TOnly_N_Object
{
  typedef std::map<std::string,TSaveOnHDD*> TMapStrPtr;
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
  TSaveOnHDD* Get(const char* nameLog);

  void SetPrintf(bool val);
  bool GetPrintf();

  void SetEnable(bool val);
  bool GetEnable();

  void SetBufferization(bool val);
  bool GetBufferization();

protected:
  void InitLogger(TSaveOnHDD* saver, const char* sName);
};

extern SHARE_EI TLogger* GetLogger();
extern SHARE_EI TSaveOnHDD* GetLogger(const char* nameLog);


#endif 