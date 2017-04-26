/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_Model_OgreH
#define Builder_Model_OgreH

#include "TypeDef.h"
#include "Builder_Model.h"

class TFactoryBuilderTool_Shape_Ogre;

class DllExport TBuilder_Model_Ogre : public TBuilder_Model
{
public:
	TBuilder_Model_Ogre();
	virtual ~TBuilder_Model_Ogre();

	TFactoryBuilderTool_Shape_Ogre* GetShapeMaker();
protected:
};

#endif
