/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/  

#include "PreBuilderGameObject_Model.h"
#include "GameObject_Model.h"

TPreBuilderGameObject_Model::TPreBuilderGameObject_Model()
{

}
//----------------------------------------------------------------------------
TPreBuilderGameObject_Model::~TPreBuilderGameObject_Model()
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Model::SetObjectItem(TMapItem::TObject* pObjectItem)
{

}
//----------------------------------------------------------------------------
std::string TPreBuilderGameObject_Model::GetStrDesc()
{
  return "Model";
}
//----------------------------------------------------------------------------
TGameObject* TPreBuilderGameObject_Model::GetGameObject()
{
  return NULL;//new TGameObject_Model;
}
//----------------------------------------------------------------------------
bool TPreBuilderGameObject_Model::GenerateTask(TVectorTypeTask& vecTypeTask)
{
  return true;
}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Model::TakeTask_Ogre(TListTaskOgre& listOgre)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Model::TakeTask_Bullet(TListTaskBullet& listBullet)
{

}
//----------------------------------------------------------------------------
void TPreBuilderGameObject_Model::TakeTask_OpenAL(TListTaskOpenAL& listOpenAL)
{

}
//----------------------------------------------------------------------------
