/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef StructBuilderTool_OgreH
#define StructBuilderTool_OgreH

namespace nsStructBuilderTool_Ogre
{
  struct TVertex
	{
		Ogre::Real x;
		Ogre::Real y; 
		Ogre::Real z;
		Ogre::Real u;
		Ogre::Real v;
	};
	struct TTriVertex
	{
		TVertex p[3];
	};
	struct TQuadVertex
	{
		TVertex p[4];
	};
}

#endif
