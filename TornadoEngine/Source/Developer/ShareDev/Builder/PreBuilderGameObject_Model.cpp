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
