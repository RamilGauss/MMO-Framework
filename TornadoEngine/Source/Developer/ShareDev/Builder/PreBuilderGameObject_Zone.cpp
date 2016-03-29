/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Zone.h"

TPreBuilderGameObject_Zone::TPreBuilderGameObject_Zone()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Zone::~TPreBuilderGameObject_Zone()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Zone::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Zone::GetStrDesc()
{
  return "Zone";
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Zone::GetGameObject()
{
  return NULL;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Zone::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return true;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Zone::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Zone::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Zone::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
