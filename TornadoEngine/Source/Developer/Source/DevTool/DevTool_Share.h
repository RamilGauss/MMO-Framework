/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ShareH
#define DevTool_ShareH

#include <boost/smart_ptr/scoped_ptr.hpp>
#include <map>

#include "IDevTool.h"

class IQtLib;

class DllExport TDevTool_Share : public IDevTool
{ 
  typedef std::map<std::string,int> TMapStrInt;
  typedef TMapStrInt::value_type    TMapStrIntVT;
  typedef TMapStrInt::iterator      TMapStrIntIt;
  TMapStrInt mMapNameID_Modules;

  typedef std::map<int,IModule*>       TMapIntPtrModule;
  typedef TMapIntPtrModule::value_type TMapIntPtrModuleVT;
  typedef TMapIntPtrModule::iterator   TMapIntPtrModuleIt;
  TMapIntPtrModule mMapID_PtrModules;

public:
  TDevTool_Share();
  virtual ~TDevTool_Share();

  virtual void Init(std::vector<std::string>& arg);
  virtual std::string GetFileDescConveyer();
  virtual IModule* GetModuleByName(const char* sName);
  virtual void EventGameEngine(int id, const char* sDesc);
protected:
  void InitMapModules();
  // навигация
  int FindIDByNameModule(std::string name);
  IModule* FindPtrModuleByID(int id);
  
  void Add(int id, IModule* pModule);
  void Add(std::string name, int id);
};

#endif
