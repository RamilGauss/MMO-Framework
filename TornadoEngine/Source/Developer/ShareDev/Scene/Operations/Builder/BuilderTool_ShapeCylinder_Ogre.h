/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTool_ShapeCylinder_OgreH
#define BuilderTool_ShapeCylinder_OgreH

#include "TypeDef.h"
#include <Ogre.h>
#include "BuilderTool_ShapeBase_Ogre.h"

struct TShapeItem;

class DllExport TBuilderTool_ShapeCylinder_Ogre : public TBuilderTool_ShapeBase_Ogre
{
	nsParamBuilderShape::TCylinder* mPSh;
public:
	TBuilderTool_ShapeCylinder_Ogre();

	virtual Ogre::Entity* CreateEntity(std::string& nameEntity);
	virtual std::string GetNameType();
protected:
	virtual void SetNameMesh();
	virtual void SetParamShape( nsParamBuilderShape::TBaseParam* pShape );
protected:
	void CreateMesh();
	void SetupEntity();

	void CreateExternalTube();
	void CreateInternalTube();
	void CreateCircleSheetUp_Cut();
	void CreateCircleSheetDown_Cut();
	void CreateCircleSheetUp();
	void CreateCircleSheetDown();

	void CreateCircleSheet(Ogre::Real y, bool x_y);
	void CreateCircleSheet_Cut(Ogre::Real y, bool x_y);

	void CreateQuad( Ogre::Real x_0, Ogre::Real x_1, 
									 Ogre::Real y_0, Ogre::Real y_1,
									 Ogre::Real z_0, Ogre::Real z_1,
									 Ogre::Real u_0, Ogre::Real u_1,
									 Ogre::Real v_0, Ogre::Real v_1);
	void CreateTube(Ogre::Real radius, bool x_y);
};

#endif
