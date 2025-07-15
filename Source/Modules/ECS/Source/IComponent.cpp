/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IComponent.h"
#include "Base/Common/BL_Debug.h"

using namespace nsECSFramework;

IComponent::~IComponent()
{

}
//--------------------------------------------------------------
bool IComponent::IsLess(const IComponent* pOther) const
{
    BL_FIX_BUG();
    return true;
}
//--------------------------------------------------------------
bool IComponent::IsEqual(const IComponent* pOther) const
{
    BL_FIX_BUG();
    return true;
}
//--------------------------------------------------------------
size_t IComponent::GetHash() const
{
    BL_FIX_BUG();
    return 0;
}
//--------------------------------------------------------------
