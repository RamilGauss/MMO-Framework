/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Terrain.h"

TPreBuilderGameObject_Terrain::TPreBuilderGameObject_Terrain()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Terrain::~TPreBuilderGameObject_Terrain()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Terrain::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Terrain::GetStrDesc()
{
  return "Terrain";
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Terrain::GetGameObject()
{
  return NULL;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Terrain::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return false;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Terrain::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Terrain::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Terrain::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
