/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ShareH
#define DevTool_ShareH

#include "IDevTool.h"
#include "ManagerForm.h"
#include "PrototypeDevTool.h"
#include "AdapterAloneGUI_Dev.h"
#include "ManagerStateMachine.h"
#include "ManagerTime.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

class PrototypeMMOSlave;
class PrototypeMMOMaster;
class PrototypeMMOSuperServer;
class PrototypeMMOBase;
class PrototypeMMOClient;
class PrototypeGraphicEngine;
class PrototypeAloneGUI_Starter;
class PrototypeMOG;
class PrototypeMakerObjectGeneral;
class PrototypePhysicEngine;
class PrototypeTimer;
class PrototypeServer;
class AdapterGraphicEngineGUI_DX9;
class TMakerObjectGeneral;

class TDevTool_Share : public IDevTool
{ 
  boost::scoped_ptr<AdapterAloneGUI_Dev>         mAloneGUI_Dev;
  boost::scoped_ptr<AdapterGraphicEngineGUI_DX9> mMyGUI_DX9;
	boost::scoped_ptr<TMakerObjectGeneral>         mMakerObjectGeneral;
public:
  struct TComponent
  {
    TManagerForm            mGUI;           // GUI
    TManagerStateMachine    mMStateMachine; // конечный автомат, для HotKeys, Net (обработка пакетов)
    TManagerTime            mMTime;
    PrototypeDevTool*       mDev;
    PrototypeTimer*         mTimer;
    PrototypeGraphicEngine* mGraphicEngine; // BigJack отрисовка сцены
    PrototypePhysicEngine*  mPhysicEngine;  // PhysicEngine
    PrototypeMOG*           mMOG;
    PrototypeMMOClient*     mNetClient;     // MMOEngine
    union
    { // MMOEngine
      PrototypeMMOSlave*       Slave;      
      PrototypeMMOMaster*      Master;     
      PrototypeMMOSuperServer* SuperServer;
      PrototypeMMOBase*        Base;
    }mNet;
    IQtLib*                    mQtGUI;// полный доступ к возможностям Qt
    PrototypeAloneGUI_Starter* mQtSrcEvent;// оставить пакет-событие от AloneGUI
    PrototypeServer*           mServer;

    TComponent()
    {
      mDev             = NULL;
      mTimer           = NULL;
      mGraphicEngine   = NULL; 
      mNetClient       = NULL; 
      mPhysicEngine    = NULL; 
      mMOG             = NULL; 
      mNet.Base        = NULL;
      mQtGUI           = NULL;
      mQtSrcEvent      = NULL;
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

  virtual void SetModulePtr(IModule* ptr);
  virtual void FreeModulePtr(IModule* ptr);
  virtual std::string GetPathXMLFile();
protected:
  virtual std::string GetTitleWindow(){return "";}
};

#endif
