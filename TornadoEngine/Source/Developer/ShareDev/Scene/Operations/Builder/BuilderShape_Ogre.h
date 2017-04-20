/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef BuilderShape_OgreH
#define BuilderShape_OgreH

#include "TypeDef.h"

#include <OgrePrerequisites.h>
#include <OgreMesh.h>
#include <map>
#include "ParamBuilderShape.h"

struct TShapeItem;
struct TMaterialItem;
class TBuilderShapeBase_Ogre;

class DllExport TBuilderShape_Ogre
{
  TShapeItem*    mShape;
	TMaterialItem* mMaterial;
	
	Ogre::Entity* mPtrEntity;

	std::string mNameEntity;

	int mCntShape;

	typedef std::map<nsParamBuilderShape::eType,TBuilderShapeBase_Ogre*> TMapTypePtr;
	typedef TMapTypePtr::iterator   					 TMapTypePtrIt;
	typedef TMapTypePtr::value_type 					 TMapTypePtrVT;

	TMapTypePtr mMapTypeBuilder;
public:
  TBuilderShape_Ogre();
  ~TBuilderShape_Ogre();

	Ogre::Entity* Build(TShapeItem* pShape);
protected:
	void FindMaterialByShape();
	void SetupBuilderMap();
};

#endif
