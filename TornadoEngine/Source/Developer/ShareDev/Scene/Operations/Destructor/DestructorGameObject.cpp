/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DestructorGameObject.h"

TDestructorGameObject::TDestructorGameObject()
{

}
//-------------------------------------------------------------------
TDestructorGameObject::~TDestructorGameObject()
{

}
//-------------------------------------------------------------------
void TDestructorGameObject::Init( /*TPreDestructor::TVectorTypeTask& vec*/ )
{

}
//-------------------------------------------------------------------
bool TDestructorGameObject::DesctructObject( std::list<TGameObject*>& pListObject )
{
  return false;
}
//-------------------------------------------------------------------
TDestructorGameObject::State TDestructorGameObject::GetState()
{
  return mState;
}
//-------------------------------------------------------------------
void TDestructorGameObject::DestructFromThread_Ogre()
{

}
//-------------------------------------------------------------------
void TDestructorGameObject::DestructFromThread_Bullet()
{

}
//-------------------------------------------------------------------

