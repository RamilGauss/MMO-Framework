/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IContext.h"

using namespace nsTornadoEngine;

IContext::~IContext()
{

}
//------------------------------------------------------------------------------------------
void IContext::IncrementReference()
{
    mReferenceCount++;
}
//------------------------------------------------------------------------------------------
void IContext::DecrementReference()
{
    mReferenceCount--;
}
//------------------------------------------------------------------------------------------
int IContext::GetReferenceCount() const 
{ 
    return mReferenceCount; 
}
//------------------------------------------------------------------------------------------