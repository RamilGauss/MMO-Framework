/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Model.h"

TPattern_Model::TPattern_Model()
{

}
//---------------------------------------------------------------------------
TPattern_Model::~TPattern_Model()
{

}
//---------------------------------------------------------------------------
bool TPattern_Model::SetParameterFromPattern(TContainer c)
{
  return true;
}
//---------------------------------------------------------------------------
TContainer TPattern_Model::GetParameterToPattern()
{
  TContainer c;
  return c;
}
//---------------------------------------------------------------------------
void TPattern_Model::SetPosition(nsMathTools::TVector3& v)
{
  // подготовить задание для физики
  nsMathTools::TVector3* pV = new nsMathTools::TVector3(v);
  mPipePositionLogic2Bullet.Add(pV);
}
//---------------------------------------------------------------------------
void TPattern_Model::GetPosition(nsMathTools::TVector3& v)
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SetOrientation(nsMathTools::TVector3& v)
{
  // подготовить задание для физики
  nsMathTools::TVector3* pV = new nsMathTools::TVector3(v);
  mPipeOrientationLogic2Bullet.Add(pV);
}
//---------------------------------------------------------------------------
void TPattern_Model::GetOrientation(nsMathTools::TVector3& v)
{

}
//---------------------------------------------------------------------------
bool TPattern_Model::LoadFromParameterMap()
{
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::UpdateFromGameItem(TBaseItem* pBI)
{
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::Unload()
{
  return true;
}
//---------------------------------------------------------------------------
int TPattern_Model::GetProgressLoad()
{
  return 100;
}
//---------------------------------------------------------------------------
int TPattern_Model::GetProgressUnload()
{
  return 100;
}
//---------------------------------------------------------------------------
void TPattern_Model::LoadFromThread_Ogre(bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::LoadFromThread_Bullet(bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::LoadFromThread_OpenAL(bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadFromThread_Ogre(bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadFromThread_Bullet(bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadFromThread_OpenAL(bool fast )
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_Logic()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_Ogre()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_Bullet()
{
  // проверка на изменение позиции и ориентации
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroFromThread_OpenAL()
{

}
//---------------------------------------------------------------------------
