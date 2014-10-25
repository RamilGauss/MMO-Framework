/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ShareH
#define DevTool_ShareH

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "IDevTool.h"
#include "ManagerForm.h"
#include "ManagerStateMachine.h"
#include "ManagerTime.h"
#include "ManagerSynchroObject.h"
#include "ManagerObject.h"

#include "AdapterDevTool.h"
#include "AdapterAloneGUI.h"
#include "AdapterMMO.h"
#include "AdapterTimer.h"
#include "AdapterGraphicEngine.h"
#include "AdapterPhysicEngine.h"
#include "AdapterAloneGUI.h"
#include "AdapterServer.h"

#include "Client.h"
#include "Master.h"
#include "Slave.h"
#include "SuperServer.h"

class IQtLib;

class DllExport TDevTool_Share : public IDevTool
{ 
  boost::scoped_ptr<AdapterAloneGUI> mAloneGUI_Dev;
public:
  struct TComponent
  {
    // для доступа из потока Qt к объектам и функциям разработчика
    IQtLib*               mQtGUI;        
    TManagerObject        mMngObject;
    TManagerSynchroObject mMngSynchroObject;// использовать по таймеру
    TManagerForm          mGUI;          // GUI
    TManagerStateMachine  mMStateMachine;// конечный автомат, для HotKeys, Net (обработка пакетов)
    TManagerTime          mMTime;
    boost::scoped_ptr<AdapterDevTool>       mDev;
    boost::scoped_ptr<AdapterTimer>         mTimer;
    boost::scoped_ptr<AdapterGraphicEngine> mGraphicEngine;// OGRE отрисовка сцены
    boost::scoped_ptr<AdapterPhysicEngine>  mPhysicEngine; // Bullet
    // оставить пакет-событие от AloneGUI для обработчика
    boost::scoped_ptr<AdapterAloneGUI>      mQtSrcEvent;   
    boost::scoped_ptr<AdapterServer>        mServer;
    // MMOEngine
    boost::scoped_ptr<AdapterMMO<nsMMOEngine::TClient> >      mClient;
    boost::scoped_ptr<AdapterMMO<nsMMOEngine::TSlave> >       mSlave;      
    boost::scoped_ptr<AdapterMMO<nsMMOEngine::TMaster> >      mMaster;     
    boost::scoped_ptr<AdapterMMO<nsMMOEngine::TSuperServer> > mSuperServer;
    nsMMOEngine::TBase*                                       mMMO;

    TComponent()
    {
      mQtGUI = NULL;
      mMMO   = NULL;
    }
  };

protected:
  // компоненты
  TComponent mComponent;
public:

  TDevTool_Share();
  virtual ~TDevTool_Share();
  // доступ к компонентам
  TComponent* GetComponent(){return &mComponent;}
  static TDevTool_Share* Singleton();

  virtual void SetModulePtr(TModuleDev* ptr);
  virtual void FreeModulePtr(TModuleDev* ptr);
  virtual std::string GetPathXMLFile();
protected:
  virtual std::string GetTitleWindow(){return "";}
};

#endif
