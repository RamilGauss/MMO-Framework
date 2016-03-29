/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Animated.h"
#include "GameObject_Animated.h"

TPreBuilderGameObject_Animated::TPreBuilderGameObject_Animated()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Animated::~TPreBuilderGameObject_Animated()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Animated::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Animated::GetStrDesc()
{
  return TGameObject_Animated::GetType();
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Animated::GetGameObject()
{
  return new TGameObject_Animated;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Animated::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return true;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Animated::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Animated::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Animated::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
