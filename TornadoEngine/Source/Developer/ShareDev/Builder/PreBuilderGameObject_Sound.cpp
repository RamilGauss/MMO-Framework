/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Sound.h"

TPreBuilderGameObject_Sound::TPreBuilderGameObject_Sound()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Sound::~TPreBuilderGameObject_Sound()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Sound::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Sound::GetStrDesc()
{
  return "Sound";
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Sound::GetGameObject()
{
  return NULL;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Sound::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return true;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Sound::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Sound::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Sound::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
