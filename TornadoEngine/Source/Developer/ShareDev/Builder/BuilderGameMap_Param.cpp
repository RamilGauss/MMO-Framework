/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderGameMap_Param.h"

#include "CacheTableSound.h"
#include "ApplySetup_GravityVector.h"
#include "ApplySetup_MapGraphicConfig.h"

#include "ModuleLogic.h"
#include "ListModules.h"

#include "PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"

TBuilderGameMap_Param::TBuilderGameMap_Param()
{
	flgUsePhysic  = false;
	flgUseGraphic = false;
	flgUseSound   = false;

	mFBP      			 = NULL; 
	mPhysicWorldID   = -1;
  mTableSound      = NULL;
	mFactoryGameItem = NULL;

	mCTableSound.reset(new TCacheTableSound);
	mAS_GravityVector.reset(new TApplySetup_GravityVector);
	mAS_CameraUp.reset(new TApplySetup_MapGraphicConfig);
}
//-------------------------------------------------------------------
TBuilderGameMap_Param::~TBuilderGameMap_Param()
{

}
//-------------------------------------------------------------------
void TBuilderGameMap_Param::Init(std::set<int>& useID_Module, 
	TFactoryBehaviourPatternModel* pFBP, int id_world)
{
	mSetUseID_Module = useID_Module;
	mFBP      			 = pFBP;
	mPhysicWorldID   = id_world;

  mFactoryGameItem = TModuleLogic::Get()->GetFGI();

	flgUsePhysic  = bool(mSetUseID_Module.find(nsListModules::PhysicEngine) !=mSetUseID_Module.end());
	flgUseGraphic = bool(mSetUseID_Module.find(nsListModules::GraphicEngine)!=mSetUseID_Module.end());
	flgUseSound   = bool(mSetUseID_Module.find(nsListModules::SoundEngine)  !=mSetUseID_Module.end());
}
//-------------------------------------------------------------------
void TBuilderGameMap_Param::Build( TMapItem* pMI )
{
	mMapItem = pMI;
	mTableSound = 
		(TTableSoundItem*)mFactoryGameItem->Get( TFactoryGameItem::TableSound, mMapItem->mNameTableSound);
	
	if( UsePhysic() )
		InitMapFrom_Physic();
	if( UseGraphic() )
		InitMapFrom_Graphic();
	if( UseSound() )
		InitMapFrom_Sound();
}
//-------------------------------------------------------------------
bool TBuilderGameMap_Param::UsePhysic()
{
	return flgUsePhysic;
}
//-------------------------------------------------------------------
bool TBuilderGameMap_Param::UseGraphic()
{
	return flgUseGraphic;
}
//-------------------------------------------------------------------
bool TBuilderGameMap_Param::UseSound()
{
	return flgUseSound;
}
//-------------------------------------------------------------------
void TBuilderGameMap_Param::InitMapFrom_Physic()
{
	mAS_GravityVector->Set(mMapItem->mGravity, mPhysicWorldID);
	mAS_GravityVector->WorkByModule_Physic();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap_Param::InitMapFrom_Graphic()
{
	mAS_CameraUp->Set(mMapItem->mBackgroundColour, mMapItem->mFog, mMapItem->mAmbientLight);
	mAS_CameraUp->WorkByModule_Graphic();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap_Param::InitMapFrom_Sound()
{
	mCTableSound->Set(mTableSound);
	mCTableSound->WorkByModule_Sound();
}
//--------------------------------------------------------------------------------------------
