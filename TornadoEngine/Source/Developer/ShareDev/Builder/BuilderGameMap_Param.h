/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderGameMap_ParamH
#define BuilderGameMap_ParamH

#include "TypeDef.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <set>

class TCacheTableSound;
class TApplySetup_GravityVector;
class TApplySetup_MapGraphicConfig;

class TFactoryGameItem;
struct TTableSoundItem;
struct TMapItem;
class TFactoryBehaviourPattern;

class DllExport TBuilderGameMap_Param
{
	boost::scoped_ptr<TCacheTableSound>          		mCTableSound;
	boost::scoped_ptr<TApplySetup_GravityVector> 		mAS_GravityVector;
	boost::scoped_ptr<TApplySetup_MapGraphicConfig> mAS_CameraUp;

	std::set<int>             mSetUseID_Module; 
	TFactoryBehaviourPattern* mFBP; 
  TFactoryGameItem*         mFactoryGameItem;
	int                       mPhysicWorldID;
	TMapItem*                 mMapItem;
  TTableSoundItem*          mTableSound;

	bool flgUsePhysic;
	bool flgUseGraphic;
	bool flgUseSound;
public:
  TBuilderGameMap_Param();
  virtual ~TBuilderGameMap_Param();

	void Init(std::set<int>& useID_Module, 
		TFactoryBehaviourPattern* pFBP, int id_world);
	void Build( TMapItem* pMI );
private:
	bool UsePhysic();
	bool UseGraphic();
	bool UseSound();

	void InitMapFrom_Physic();
	void InitMapFrom_Graphic();
	void InitMapFrom_Sound();
};

#endif

