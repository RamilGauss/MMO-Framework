/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Model_Ogre.h"
#include "Pattern_Model.h"
#include "FactoryBuilderTool_Shape_Ogre.h"

TBuilder_Model_Ogre::TBuilder_Model_Ogre()
{

}
//--------------------------------------------------------------------
TBuilder_Model_Ogre::~TBuilder_Model_Ogre()
{

}
//--------------------------------------------------------------------
TFactoryBuilderTool_Shape_Ogre* TBuilder_Model_Ogre::GetShapeMaker()
{
	return TFactoryBuilderTool_Shape_Ogre::Get();
}
//------------------------------------------------------------------------
