/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Light.h"

TPreBuilderGameObject_Light::TPreBuilderGameObject_Light()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Light::~TPreBuilderGameObject_Light()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Light::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Light::GetStrDesc()
{
  return "Light";
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Light::GetGameObject()
{
  return NULL;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Light::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return false;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Light::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Light::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Light::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
