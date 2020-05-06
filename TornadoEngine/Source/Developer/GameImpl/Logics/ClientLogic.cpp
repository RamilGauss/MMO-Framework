/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <OgreRenderWindow.h>
#include <OgreRenderTarget.h>

#include "ClientLogic.h"

#include "ListModules.h"
#include "Logger.h"

#include "ModuleTimer.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"

#include "ClientMain.h"
#include "DebugPanel.h"

#include "ShowTankWoT_test.h"

TClientLogic::TClientLogic()
{
  mClientMain = nullptr;
  mDebugPanel = nullptr;
  fallMotionState = nullptr;

  mPtrShowTank.reset( new TShowTankWoT_test );
}
//----------------------------------------------------------
TClientLogic::~TClientLogic()
{

}
//----------------------------------------------------------
bool TClientLogic::WorkClient()
{
  return true;
}
//----------------------------------------------------------
void TClientLogic::Input( int id, void* p, int size )
{
  switch ( id )
  {
    case nsListModules::GraphicEngine:
      break;
    case nsListModules::MMOEngineClient:
      HandleFromMMOEngine( ( nsMMOEngine::TBaseEvent* )p );
      break;
    case nsListModules::PhysicEngine:
      break;
    case nsListModules::SoundEngine:
      break;
    case nsListModules::Timer:
      ShowFPS();
      break;
    default:BL_FIX_BUG();
  }
}
//----------------------------------------------------------
void TClientLogic::StartEvent()
{
  StartTimer();
  InitForms();
  ShowTanks();
  InitPhysic();

  //mComp.pGraphicEngine->GetCBBeginWork()->Register( &TClientLogic::GraphicBeginWork ,this);
  //mComp.pGraphicEngine->GetCBStopEvent()->Register( &TClientLogic::FreeGraphicResource,this);

  //mComp.pPhysicEngine->GetCBBeginWork()->Register( &TClientLogic::PhysicBeginWork ,this);
  //mComp.pPhysicEngine->GetCBEndWork()->Register( &TClientLogic::PhysicEndWork ,this);
}
//----------------------------------------------------------
void TClientLogic::StopEvent()
{
  FreeGraphicResource();
}
//----------------------------------------------------------
void TClientLogic::StartTimer()
{
  // вызовется из потока таймера
  unsigned int mID_Timer = mComp.pTimer->New( 10 );
}
//----------------------------------------------------------
void TClientLogic::InitForms()
{
  //mClientMain = new TClientMain;
  //mClientMain->Show();

  mDebugPanel = new TDebugPanel;
  mDebugPanel->Show();
}
//----------------------------------------------------------
void TClientLogic::InitLog()
{
  GetLogger()->Register( "Inner" );// для логирования внутренних событий
  GetLogger()->Init( "Client" );
}
//---------------------------------------------------------------------------------------------
void TClientLogic::HandleFromMMOEngine( nsMMOEngine::TBaseEvent* pBE )
{
  std::string sEvent;
  switch ( pBE->mType )
  {
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      break;
    case nsMMOEngine::eError:
      sEvent = "Error";
      break;
    case nsMMOEngine::eEnterInQueue:
      sEvent = "EnterInQueue";
      break;
    case nsMMOEngine::eLeaveQueue:
      sEvent = "LeaveQueue";
      break;
    case nsMMOEngine::eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case nsMMOEngine::eResultLogin:
      sEvent = "ResultLogin";
      LoginOnServer();
      break;
    default:BL_FIX_BUG();
  }
  GetLogger( "Inner" )->WriteF_time( "MMOEngine: %s.\n", sEvent.data() );
}
//---------------------------------------------------------------------------------------------
void TClientLogic::LoginOnServer()
{
  mClientMain->Hide();
  // вставка Танка (временно), прототип модели
  ShowTanks();

  Ogre::Camera* pCamera = mComp.pGraphicEngine->GetGE()->GetCamera();
  pCamera->setPosition( 60, 60, 60 );
  pCamera->lookAt( 0, 0, 0 );
}
//---------------------------------------------------------------------------------------------
void TClientLogic::ShowFPS()
{
  float fps = mComp.pGraphicEngine->GetGE()->GetWindow()->getStatistics().avgFPS;
  mDebugPanel->SetFPS( fps );

  mDebugPanel->SetX( x );
  mDebugPanel->SetY( y );
  mDebugPanel->SetZ( z );
}
//---------------------------------------------------------------------------------------------
void TClientLogic::ShowTanks()
{
  mPtrShowTank->ShowTanks();
}
//---------------------------------------------------------------------------------------------
//void TClientLogic::PhysicEndWork()
//{
//  if(fallMotionState)
//  {
//    static float minY = 100000;
//    btTransform trans;
//    fallMotionState->getWorldTransform(trans);
//    x = trans.getOrigin().getX();
//    minY = std::min(minY, trans.getOrigin().getY());
//    y = minY;
//    z = trans.getOrigin().getZ();
//  }
//}
//---------------------------------------------------------------------------------------------
void TClientLogic::InitPhysic()
{
  int id_world = mComp.pPhysicEngine->GetPE()->AddWorld();
  btDiscreteDynamicsWorld* dynamicsWorld = mComp.pPhysicEngine->GetPE()->GetWorld( id_world );
  dynamicsWorld->setGravity( btVector3( 0, -9.81f, 0 ) );

  btCollisionShape* groundShape = new btStaticPlaneShape( btVector3( 0, 1, 0 ), 1 );
  btDefaultMotionState* groundMotionState = new btDefaultMotionState( btTransform( btQuaternion( 0, 0, 0, 1 ), btVector3( 0, -1, 0 ) ) );
  btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI( 0, groundMotionState, groundShape, btVector3( 0, 0, 0 ) );
  btRigidBody* groundRigidBody = new btRigidBody( groundRigidBodyCI );
  dynamicsWorld->addRigidBody( groundRigidBody );
  //-----------------------------------------
  btCollisionShape* fallShape = new btSphereShape( 1 );
  /*btDefaultMotionState* */
  fallMotionState = new btDefaultMotionState( btTransform( btQuaternion( 0, 0, 0, 1 ), btVector3( 0, 15000, 0 ) ) );
  btScalar mass = 1;
  btVector3 fallInertia( 0, 0, 0 );
  fallShape->calculateLocalInertia( mass, fallInertia );
  btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI( mass, fallMotionState, fallShape, fallInertia );
  btRigidBody* fallRigidBody = new btRigidBody( fallRigidBodyCI );
  dynamicsWorld->addRigidBody( fallRigidBody );
  //-----------------------------------------
  btCollisionShape* fallShape2 = new btSphereShape( 1 );
  btDefaultMotionState*
    fallMotionState2 = new btDefaultMotionState( btTransform( btQuaternion( 0, 0, 0, 1 ), btVector3( 0.1f, 1, 0.1f ) ) );
  btScalar mass2 = 1;
  btVector3 fallInertia2( 0, 0, 0 );
  fallShape2->calculateLocalInertia( mass2, fallInertia2 );
  btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI2( mass2, fallMotionState2, fallShape2, fallInertia2 );
  btRigidBody* fallRigidBody2 = new btRigidBody( fallRigidBodyCI2 );
  //dynamicsWorld->addRigidBody(fallRigidBody2);
}
//---------------------------------------------------------------------------------------------
void TClientLogic::GraphicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
//void TClientLogic::PhysicBeginWork()
//{
//
//}
////---------------------------------------------------------------------------------------------
void TClientLogic::FreeGraphicResource()
{
  delete mClientMain;
  delete mDebugPanel;
}
//---------------------------------------------------------------------------------------------
