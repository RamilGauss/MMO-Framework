/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Bullet.h"

TBuilder_Bullet::TBuilder_Bullet()
{
  mID_PhysicWorld = -1;
}
//---------------------------------------------------------------------------------
TBuilder_Bullet::~TBuilder_Bullet()
{

}
//---------------------------------------------------------------------------------
void TBuilder_Bullet::SetID_PhysicWorld( int id )
{
  mID_PhysicWorld = id;
}
//---------------------------------------------------------------------------------
void TBuilder_Bullet::Work(TTaskForBuilder_Bullet* pTask)
{

}
//---------------------------------------------------------------------------------
