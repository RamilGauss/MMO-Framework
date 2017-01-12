/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef FactoryModelLOD_OgreH
#define FactoryModelLOD_OgreH

#include "TypeDef.h"
#include "OgreMovableObject.h"

class DllExport TFactoryModelLOD_Ogre : public Ogre::MovableObjectFactory
{
protected:
	virtual Ogre::MovableObject* createInstanceImpl(const Ogre::String& name, 
		const Ogre::NameValuePairList* params = 0);
public:
	TFactoryModelLOD_Ogre();
	virtual ~TFactoryModelLOD_Ogre();

	static Ogre::String FACTORY_TYPE_NAME;

	virtual const Ogre::String& getType(void) const;
	virtual void destroyInstance(Ogre::MovableObject* obj);

};

#endif
