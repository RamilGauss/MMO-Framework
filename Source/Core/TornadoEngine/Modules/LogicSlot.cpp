/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LogicSlot.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

void TLogicSlot::AddFeature(TFeature* p)
{
    p->SetEntMng(mEntMng);
    mFeatures.push_back(p);
}
//---------------------------------------------------------------------------------------
void TLogicSlot::RemoveFeature(TFeature* p)
{
    std::erase(mFeatures, p);
}
//---------------------------------------------------------------------------------------
bool TLogicSlot::HasFeature(nsECSFramework::TFeature* p)
{
    return std::find(mFeatures.begin(), mFeatures.end(), p) != mFeatures.end();
}
//---------------------------------------------------------------------------------------
void TLogicSlot::Work()
{
    for (auto& feature : mFeatures) {
        feature->Execute();
    }
}
//---------------------------------------------------------------------------------------
const std::list<TFeature*>* TLogicSlot::GetFeatures() const
{
    return &mFeatures;
}
//---------------------------------------------------------------------------------------
void TLogicSlot::SetEntMng(TEntityManager* pEntMng)
{
    mEntMng = pEntMng;
}
//---------------------------------------------------------------------------------------
TEntityManager* TLogicSlot::GetEntMng() const
{
    return mEntMng;
}
//---------------------------------------------------------------------------------------