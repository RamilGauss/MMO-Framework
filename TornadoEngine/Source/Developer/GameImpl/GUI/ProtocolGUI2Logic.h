#ifndef ProtocolGUI2LogicH
#define ProtocolGUI2LogicH

#include "TypeDef.h"

namespace nsProtocolGUI2Logic
{
#ifdef WIN32 
#pragma pack(push, 1)
#endif

	typedef enum 
	{
		eBaseEvent, 
		eLoadMap,
		eSetupStateCurrentPhysicWorld,
	}eType;
	
	struct TBaseProtocolGUI2Logic
	{
		eType type;
		TBaseProtocolGUI2Logic(eType v){type=v;};
	}_PACKED;
	//-------------------------------------------------------------
	struct TLoadMap : public TBaseProtocolGUI2Logic
	{
		std::string nameMap;
		TLoadMap():TBaseProtocolGUI2Logic(eLoadMap){}
	}_PACKED;
	//-------------------------------------------------------------
	struct TSetupStateCurrentPhysicWorld : public TBaseProtocolGUI2Logic
	{
		TSetupStateCurrentPhysicWorld():
			TBaseProtocolGUI2Logic(eSetupStateCurrentPhysicWorld){}
			TPhysicEngine_Bullet::eStateWorld stateWorld;
	}_PACKED;
	//-------------------------------------------------------------


#ifdef WIN32 
#pragma pack(pop)
#endif

}

#endif
