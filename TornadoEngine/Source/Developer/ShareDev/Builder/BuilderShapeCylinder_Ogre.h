/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderShapeCylinder_OgreH
#define BuilderShapeCylinder_OgreH

#include "TypeDef.h"
#include <Ogre.h>
#include "BuilderShapeBase_Ogre.h"

struct TShapeItem;

class DllExport TBuilderShapeCylinder_Ogre : public TBuilderShapeBase_Ogre
{
	nsParamBuilderShape::TCylinder* mPSh;
	int mCntQuad;
public:
	TBuilderShapeCylinder_Ogre();

	virtual Ogre::Entity* CreateEntity(std::string& nameEntity);
	virtual std::string GetNameType();
protected:
	virtual void SetNameMesh();
	virtual void SetParamShape( nsParamBuilderShape::TBaseParam* pShape );
protected:
	//void CreateMaterial();
	void CreateMesh();
	void SetupEntity();

	Ogre::ManualObject* mPtrMO;

	void CreateExternalTube();
	void CreateInternalTube();
	void CreateCircleSheetUp_Cut();
	void CreateCircleSheetDown_Cut();
	void CreateCircleSheetUp();
	void CreateCircleSheetDown();

	void CreateQuad( Ogre::Real x_0, Ogre::Real x_1, 
									 Ogre::Real y_0, Ogre::Real y_1,
									 Ogre::Real z_0, Ogre::Real z_1,
									 Ogre::Real u_0, Ogre::Real u_1,
									 Ogre::Real v_0, Ogre::Real v_1);
};

#endif
