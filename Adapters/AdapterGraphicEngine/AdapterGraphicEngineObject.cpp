/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterGraphicEngineObject.h"
#include "IBaseObjectGE.h"
#include "AdapterModelGE.h"

#include <boost/foreach.hpp>

AdapterGraphicEngineObject::AdapterGraphicEngineObject(int typeDX):
TObjectGE(typeDX)
{
  mGameObject = NULL;
}
//-----------------------------------------------------------------------------------
AdapterGraphicEngineObject::~AdapterGraphicEngineObject()
{

}
//-----------------------------------------------------------------------------------
bool AdapterGraphicEngineObject::Animate(unsigned int time_ms)
{
  return mGameObject->Animate(time_ms);
}
//-----------------------------------------------------------------------------------
bool AdapterGraphicEngineObject::IsGlowEffect()
{
  return mGameObject->IsGlowEffect();
}
//-----------------------------------------------------------------------------------
bool AdapterGraphicEngineObject::IsGlowable()
{
  return mGameObject->IsGlowable();
}
//-----------------------------------------------------------------------------------
void AdapterGraphicEngineObject::SetupShaderStackModelGE()
{
  mGameObject->SetupShaderStackModelGE();
}
//-----------------------------------------------------------------------------------
void AdapterGraphicEngineObject::EventSetModelGE()
{
  AdapterModelGE* pModel = new AdapterModelGE;
  pModel->SetModelGE(GetModel());

  mGameObject->SetModel(pModel);
  mGameObject->EventSetModelGE();
}
//-----------------------------------------------------------------------------------
void AdapterGraphicEngineObject::SetGameObject(IBaseObjectGE* pObject)
{
  mGameObject = pObject;
  mGameObject->SetObjectGE(this);
  mGameObject->RegisterForUpdate(&AdapterGraphicEngineObject::UpdateObject,this);
  // скопировать свойства
  SetWorld((nsMathTools::TMatrix16*)mGameObject->GetWorld());
  SetShow(mGameObject->IsShow());
  SetAlphaTransparency(mGameObject->GetAlphaTransparency());
  SetID_Model(mGameObject->GetID_Model());
  SetTree(mGameObject->GetTree());
	AssignVectorMatrix();
}
//-----------------------------------------------------------------------------------
IBaseObjectGE* AdapterGraphicEngineObject::GetGameObject()
{
  return mGameObject;
}
//-----------------------------------------------------------------------------------
void AdapterGraphicEngineObject::UpdateObject( PrototypeObject* p, int type_event)
{
  switch(type_event)
  {
    case IBaseObject::eWorld:
      SetWorld((nsMathTools::TMatrix16*)mGameObject->GetWorld());
      break;
    case IBaseObjectGE::eShow:
      SetShow(mGameObject->IsShow());
      break;
    case IBaseObjectGE::eAlphaTransparency:
      SetAlphaTransparency(mGameObject->GetAlphaTransparency());
      break;
    case IBaseObject::eTree:
      AssignTree();
      break;
    case IBaseObject::eVectorMatrix:
			AssignVectorMatrix();
      break;
  }
}
//-----------------------------------------------------------------------------------
void AdapterGraphicEngineObject::AssignVectorMatrix()
{
	if(mGameObject->GetVectorMatrix()->size()==mVectorMatrix.size())
	{
		int cnt = mGameObject->GetVectorMatrix()->size();
		for( int i = 0 ; i < cnt ; i++)
			*(mVectorMatrix[i]) = *(mGameObject->GetVectorMatrix()->operator[](i));
	}
	else
	{
		BOOST_FOREACH(nsMathTools::TMatrix16* pMatrix, mVectorMatrix)
			delete pMatrix;
		mVectorMatrix.clear();
		int cnt = mGameObject->GetVectorMatrix()->size();
		for( int i = 0 ; i < cnt ; i++)
		{
			mVectorMatrix[i] = new nsMathTools::TMatrix16;
			*(mVectorMatrix[i]) = *(mGameObject->GetVectorMatrix()->operator[](i));
		}
	}
}
//-----------------------------------------------------------------------------------
void AdapterGraphicEngineObject::AssignTree()
{
  mTree = *(mGameObject->GetReadyTree());
}
//-----------------------------------------------------------------------------------
