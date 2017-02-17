/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Plane_TestH
#define Plane_TestH

#include "TypeDef.h"
#include <Ogre.h>

class DllExport TPlane_Test
{
	Ogre::SceneManager* mPtrSceneMng;
	Ogre::String mNameMesh;
	Ogre::String mNameMaterial;
	Ogre::String mNameFileTexture;

	Ogre::String mNameEntity;

	Ogre::MeshPtr mMeshPtr;
	Ogre::MaterialPtr mMaterialPtr;

	Ogre::Entity* mPtrEntity;

	Ogre::Real mWidthTexture;
	Ogre::Real mLenghtTexture;
	Ogre::Real mWidth;
	Ogre::Real mHeight;
	Ogre::Real mDepth;

	int mCntQuad;
public:
	TPlane_Test();

	void Setup(Ogre::Real width, Ogre::Real height, Ogre::Real depth,
		Ogre::String& nameMaterial, Ogre::String& nameFileTexture,
		Ogre::Real widthTexture, Ogre::Real lenghtTexture);// px

	Ogre::Entity* CreateEntity(Ogre::String& nameEntity);// Ogre thread only
protected:
	void CreateMaterial();
	void CreateMesh();
	void SetupEntity();

	Ogre::ManualObject* mPtrMO;
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
		Ogre::Real unuse, Ogre::Vector3& normal);

	void CreateQuad(Ogre::Real a_min, Ogre::Real a_max, 
		Ogre::Real b_min, Ogre::Real b_max,
		eUseAxe useA, eUseAxe useB,
		Ogre::Real unuse, Ogre::Vector3& normal,
		Ogre::Real u_min, Ogre::Real u_max, 
		Ogre::Real v_min, Ogre::Real v_max);
};

#endif
