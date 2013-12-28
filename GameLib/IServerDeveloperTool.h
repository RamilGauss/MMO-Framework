/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IServerDeveloperToolH
#define IServerDeveloperToolH

#include "IDeveloperTool.h"
#include "Slave.h"
#include "SuperServer.h"
#include "Master.h"

class IMakerObjectCommon;
class IManagerStateMachine;
class IManagerScene;
class IManagerObjectCommon;
class IManagerConnectClient;
class IQtLib;

class IServerDeveloperTool : public IDeveloperTool
{
public:
	struct TComponentServer : public TComponent
	{
		union
		{ // MMOEngine
			nsMMOEngine::TSlave*       Slave;      
			nsMMOEngine::TMaster*      Master;     
			nsMMOEngine::TSuperServer* SuperServer;
			nsMMOEngine::TBase*        Base;
		}mNet;
		IManagerScene*             mManagerScene;  // только для Slave
    IManagerConnectClient*     mManagerCClient;// клиенты, которые подсоединились
    IQtLib*                    mQtGUI;
		TComponentServer()
		{
			mNet.Base       = NULL; // MMOEngine
			mManagerScene   = NULL; 
      mManagerCClient = NULL;
      mQtGUI          = NULL;
		}
	};
protected:
	// компоненты
	TComponentServer mComponent;

public:
  IServerDeveloperTool();
  virtual ~IServerDeveloperTool();
  
	virtual void Init(TComponentServer* pComponent, std::vector<std::string>& arg) = 0;
	// временной интервал работы сервера
  virtual int GetTimeRefreshMS() = 0;
  // вызов не более одного раз в GetTimeRefreshMS
	//virtual void Refresh() = 0;
	// доступ к компонентам
	TComponentServer* GetComponent(){return &mComponent;}

	static IServerDeveloperTool* Singleton();
};

#endif
