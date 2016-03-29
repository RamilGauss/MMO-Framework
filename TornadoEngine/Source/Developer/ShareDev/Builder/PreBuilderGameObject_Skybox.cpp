/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Skybox.h"

TPreBuilderGameObject_Skybox::TPreBuilderGameObject_Skybox()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Skybox::~TPreBuilderGameObject_Skybox()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Skybox::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Skybox::GetStrDesc()
{
  return "Skybox";
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Skybox::GetGameObject()
{
  return NULL;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Skybox::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return true;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Skybox::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Skybox::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Skybox::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
