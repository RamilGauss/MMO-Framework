/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IClientDeveloperToolH
#define IClientDeveloperToolH

#include <string>
#include <vector>

#include "IDeveloperTool.h"
#include "DstEvent.h"
#include "Client.h"

class TLogger;
class IMakerObjectCommon;
class IManagerStateMachine;
class IPhysicEngine;
class IManagerObjectCommon;
class IManagerTime;
class IControlCamera;
class IGUI;
class IGraphicEngine;

class IClientDeveloperTool : public IDeveloperTool
{
public:
  struct TComponentClient : public TComponent
  {
    IControlCamera*         mControlCamera; // Camera
    IGUI*                   mGUI;           // GUI, MyGUI!
    IGraphicEngine*         mGraphicEngine; // BigJack отрисовка сцены
    IManagerStateMachine*   mMStateMachine; // конечный автомат, для HotKeys, Net (обработка пакетов)
    nsMMOEngine::TClient*     mNetClient;   // MMOEngine
    IPhysicEngine*          mPhysicEngine;  // PhysicEngine
    IManagerObjectCommon*   mMOC;           // GameLib
    IManagerTime*           mMTime;         // GameLib
    TComponentClient()
    {
      mControlCamera = NULL; 
      mGraphicEngine = NULL; 
      mGUI           = NULL; 
      mMStateMachine = NULL; 
      mNetClient     = NULL; 
      mPhysicEngine  = NULL; 
      mMOC           = NULL; 
      mMTime         = NULL; 
    }
  };
protected:
  // компоненты
  TComponentClient mComponent;
 
public:

  IClientDeveloperTool();
  virtual ~IClientDeveloperTool();

  virtual void Init(TComponentClient* pComponent, std::vector<std::string>& arg) = 0;
  virtual std::string GetTitleWindow() = 0;

  // доступ к компонентам
  TComponentClient* GetComponent(){return &mComponent;}

  static IClientDeveloperTool* Singleton();
};


#endif
