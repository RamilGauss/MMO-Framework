/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Model_Bullet.h"
#include "FactoryBuilderTool_Shape_Bullet.h"

#include "Pattern_Model.h"

TBuilder_Model_Bullet::TBuilder_Model_Bullet()
{

}
//--------------------------------------------------------------------
TBuilder_Model_Bullet::~TBuilder_Model_Bullet()
{

}
//--------------------------------------------------------------------
TFactoryBuilderTool_Shape_Bullet* TBuilder_Model_Bullet::GetShapeMaker()
{
	return TFactoryBuilderTool_Shape_Bullet::Get();
}
//--------------------------------------------------------------------
