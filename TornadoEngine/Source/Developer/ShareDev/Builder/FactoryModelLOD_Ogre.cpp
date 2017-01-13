/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryModelLOD_Ogre.h"

TFactoryModelLOD_Ogre::TFactoryModelLOD_Ogre()
{

}
//-----------------------------------------------------------------
TFactoryModelLOD_Ogre::~TFactoryModelLOD_Ogre()
{

}
//-----------------------------------------------------------------
Ogre::String TFactoryModelLOD_Ogre::FACTORY_TYPE_NAME = "ModelLOD_Ogre";
//-----------------------------------------------------------------------
const Ogre::String& TFactoryModelLOD_Ogre::getType(void) const
{
	return FACTORY_TYPE_NAME;
}
//-----------------------------------------------------------------------
Ogre::MovableObject* TFactoryModelLOD_Ogre::createInstanceImpl( 
																						const Ogre::String& name, 
																						const Ogre::NameValuePairList* params )
{
	// must have mesh parameter
	Ogre::MeshPtr pMesh;
	if( params != 0 )
	{
		/*Ogre::String groupName = Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME;

		NameValuePairList::const_iterator ni;

		ni = params->find("resourceGroup");
		if( ni != params->end() )
		{
			groupName = ni->second;
		}

		ni = params->find("mesh");
		if (ni != params->end())
		{
			// Get mesh (load if required)
			pMesh = Ogre::MeshManager::getSingleton().load(
				ni->second,
				// autodetect group location
				groupName );
		}*/
	}
	if( pMesh.isNull() )
	{
/*		OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
			"'mesh' parameter required when constructing an Entity.",
			"EntityFactory::createInstance");*/
	}
	return NULL;//new Ogre::Entity(name, pMesh);
}
//-----------------------------------------------------------------------
void TFactoryModelLOD_Ogre::destroyInstance( Ogre::MovableObject* obj)
{
	delete obj;
}
//-----------------------------------------------------------------------
