/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Builder_Model_BulletH
#define Builder_Model_BulletH

#include "TypeDef.h"
#include "Builder_Model.h"

class TFactoryBuilderTool_Shape_Bullet;

class DllExport TBuilder_Model_Bullet : public TBuilder_Model
{
public:
	TBuilder_Model_Bullet();
	virtual ~TBuilder_Model_Bullet();

  TFactoryBuilderTool_Shape_Bullet* GetShapeMaker();
protected:
};

#endif
