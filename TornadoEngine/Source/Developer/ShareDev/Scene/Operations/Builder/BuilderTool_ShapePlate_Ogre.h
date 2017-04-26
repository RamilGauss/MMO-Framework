/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTool_ShapePlate_OgreH
#define BuilderTool_ShapePlate_OgreH

#include "TypeDef.h"
#include <Ogre.h>
#include "BuilderTool_ShapeBase_Ogre.h"

struct TShapeItem;

class DllExport TBuilderTool_ShapePlate_Ogre : public TBuilderTool_ShapeBase_Ogre
{
	nsParamBuilderShape::TPlate* mPSh;
public:
	TBuilderTool_ShapePlate_Ogre();

	virtual Ogre::Entity* CreateEntity(std::string& nameEntity);
	virtual std::string GetNameType();
protected:
	virtual void SetNameMesh();
	virtual void SetParamShape( nsParamBuilderShape::TBaseParam* pShape );
protected:
	void CreateMesh();
	void SetupEntity();

	void CreateSheetY(Ogre::Real x_min, Ogre::Real x_max, 
		Ogre::Real z_min, Ogre::Real z_max, 
		Ogre::Real y);
	void CreateSheetZ(Ogre::Real x_min, Ogre::Real x_max, 
		Ogre::Real y_min, Ogre::Real y_max, 
		Ogre::Real z );
	void CreateSheetX(Ogre::Real y_min, Ogre::Real y_max, 
		Ogre::Real z_min, Ogre::Real z_max, 
		Ogre::Real x );

	typedef enum{useX,useY,useZ}eUseAxe;
	void SetVector3ByUse(Ogre::Vector3& pos, Ogre::Real v, eUseAxe use);

	void CreateSheet(Ogre::Real a_min, Ogre::Real a_max, 
		Ogre::Real b_min, Ogre::Real b_max,
		eUseAxe useA, eUseAxe useB,
		Ogre::Real unuse/*, Ogre::Vector3& normal*/);

	void CreateQuad(Ogre::Real a_min, Ogre::Real a_max, 
		Ogre::Real b_min, Ogre::Real b_max,
		eUseAxe useA, eUseAxe useB,
		Ogre::Real unuse/*, Ogre::Vector3& normal*/,
		Ogre::Real u_min, Ogre::Real u_max, 
		Ogre::Real v_min, Ogre::Real v_max);
};

#endif
