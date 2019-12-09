/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IHandlerScene.h"

IHandlerScene::IHandlerScene()
{

}
//-----------------------------------------------------------------
TScene* IHandlerScene::GetScenePtr()
{
  return &mScene;
}
//-----------------------------------------------------------------
