/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleLogicH
#define ModuleLogicH

#include "ModuleDev.h"
#include "Components.h"
#include "LogicEventCallBack.h"
#include "FactoryGameItem.h"
#include "FactoryBehaviourPattern.h"
#include <set>

class DllExport TModuleLogic : public TModuleDev
{
  volatile bool flgNeedExit;

	std::string mTerrainPath;
  TFactoryBehaviourPattern mFBP;
protected:
  TComponents      mComp;
  TFactoryGameItem mFGI;

	std::set<int> mSetUseID_Module;
public:
  TModuleLogic();
  virtual void ParseCmd(std::vector<std::string>& arg) = 0;
  virtual void InitLog();

	std::set<int> GetUseID_Module();

	void SetTerrainPath(std::string& path);
	std::string GetTerrainPath();

  void SetComponents(TComponents components);
  TComponents* GetC();
  TFactoryGameItem* GetFGI();
  virtual TFactoryBehaviourPattern* GetFBP();

	// оставить, потому что не только GUI использует, но и другие объекты из ShareDev
	// которые не знают про GameImpl
  static TModuleLogic* Get();

  void Exit( int reason = 0);

protected:
  bool NeedExit();
};

#endif
