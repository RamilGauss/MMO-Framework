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
	Ogre::String mNameTexture;

	Ogre::MeshPtr mMeshPtr;
	Ogre::MaterialPtr mMaterialPtr;
public:
	TPlane_Test();

	void ShowPlane(int widthNumPoints, int heightNumPoints, 
								 int widthPxTexture, int heightPxTexture,
								 int width,          int height);// Ogre thread only
protected:
	void SetupLight();
	void CreateMaterial(int widthPxTexture, int heightPxTexture, int width, int height);
	void CreateMesh(int widthNumPoints, int heightNumPoints);
	void SetupCamera();
	void SetupEntity();
};

#endif
