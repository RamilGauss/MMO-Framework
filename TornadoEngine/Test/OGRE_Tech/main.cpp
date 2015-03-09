/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ShareMisc.h"
#include "GraphicEngine_OGRE_MyGUI.h"
#include "BL_Debug.h"
#include "ClientMain_Test.h"
#include "Logger.h"
#include <OgreEntity.h>
#include <OgreRenderWindow.h>
#include "DstEvent.h"

#ifdef WIN32
#include <windows.h>
#endif
//---------------------------------------------------------------------------------------------
class TDstGE : public TDstEvent
{
public:
  void HandleEvent()
  {
    nsEvent::TEvent* pEvent = GetEvent();
		while(pEvent)
		{
			delete pEvent;
			pEvent = GetEvent();
		}
  }
};
//---------------------------------------------------------------------------------------------
struct TOrient
{
  const Ogre::Vector3 axisRotate;
  const Ogre::Radian  angleRotate;
  const Ogre::Vector3 scale;
  const Ogre::Vector3 pos;
  TOrient(Ogre::Vector3 _axisRotate, Ogre::Radian _angleRotate, 
    Ogre::Vector3 _scale, Ogre::Vector3 _pos):
    axisRotate(_axisRotate), angleRotate(_angleRotate),
    scale(_scale),pos(_pos){}
};
//---------------------------------------------------------------------------------------------
TGraphicEngine_OGRE_MyGUI ge;
TDstGE dst;
//---------------------------------------------------------------------------------------------
void AddEntity(Ogre::Entity* pEnt, TOrient& orient)
{
  pEnt->setCastShadows(false);
  Ogre::SceneNode* pNode = ge.GetSceneManager()->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(pEnt);

  pNode->setScale(orient.scale);
  pNode->rotate(orient.axisRotate, orient.angleRotate);
  pNode->setPosition(orient.pos);
}
//---------------------------------------------------------------------------------------------
#ifdef WIN32
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT){	char** argv = __argv;
#else
int main(int argc, char *argv[]){
#endif
  bool resSetPath = SetCurrentPathByFile(argv[0]);
	BL_ASSERT(resSetPath);

  ge.SetDstObject(&dst);

  GetLogger()->Register(STR_NAME_GRAPHIC_ENGINE);
  GetLogger()->Init("testGE");
	GetLogger(STR_NAME_GRAPHIC_ENGINE)->SetEnable(false);
#ifdef _DEBUG
	ge.InitOGRE("./plugins_d.cfg");
#else
	ge.InitOGRE("./plugins.cfg");
#endif
  ge.AddResource("../../Resources/GUI/MyGUI_Media",       "FileSystem");
  ge.AddResource("../../Resources/GUI/Demos/Demo_Themes", "FileSystem");
  ge.AddResource("../../Resources/GUI/Common/Base",       "FileSystem");
  ge.AddResource("../../Resources/GUI/Common/Themes",     "FileSystem");
  ge.AddResource("../../Resources/GUI_forms",             "FileSystem");
  ge.AddResource("../../Resources/Graphic/materials/programs", "FileSystem");
  ge.AddResource("../../Resources/Graphic/materials/scripts",  "FileSystem");
  ge.AddResource("../../Resources/Graphic/materials/textures", "FileSystem");
  ge.AddResource("../../Resources/Graphic/models",             "FileSystem");
  ge.AddResource("../../Resources/Graphic/packs/SdkTrays.zip", "Zip");
  ge.InitMyGUI("MyGUI_Core.xml", "MyGUI_BlackBlueTheme.xml");

  boost::scoped_ptr<TClientMain_Test> pForm(new TClientMain_Test);

  ge.GetSceneManager()->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  TOrient orGun     (Ogre::Vector3(1,0,0), Ogre::Radian( 3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, 3,4));
  TOrient orHull    (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,-10,-10));
  TOrient orChassisL(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orChassisR(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTurret  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, 0,-10));
  TOrient orTrackL  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTrackR  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));

  AddEntity(ge.GetSceneManager()->createEntity("Hull",     "KingTiger/Hull.mesh"),    orHull);
  AddEntity(ge.GetSceneManager()->createEntity("Turret",   "KingTiger/Turret.mesh"),  orTurret);
  AddEntity(ge.GetSceneManager()->createEntity("ChassisL", "KingTiger/ChassisL.mesh"),orChassisL);
  AddEntity(ge.GetSceneManager()->createEntity("ChassisR", "KingTiger/ChassisR.mesh"),orChassisR);
  AddEntity(ge.GetSceneManager()->createEntity("Gun",      "KingTiger/Gun.mesh"),     orGun);
  AddEntity(ge.GetSceneManager()->createEntity("TrackL",   "KingTiger/TrackL.mesh"),  orTrackL);
  AddEntity(ge.GetSceneManager()->createEntity("TrackR",   "KingTiger/TrackR.mesh"),  orTrackR);
  //---------------------------------------------------------------------------

  pForm->Show();
	ge.GetWindow()->resize(ge.GetWindow()->getWidth()-1,ge.GetWindow()->getHeight());
	ge.GetWindow()->resize(ge.GetWindow()->getWidth()+1,ge.GetWindow()->getHeight());

	while(ge.Work())
	{
		float fps = ge.GetWindow()->getAverageFPS();
		pForm->SetFPS(fps);
    
    dst.HandleEvent();
	}

  return 0;
}
