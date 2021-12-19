/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <BL_Debug.h>

#include "Dialog.h"
#include "DialogStack.h"

using namespace nsImGuiWidgets;

void TDialogStack::Render()
{
    if (mDialogs.empty()) {
        return;
    }

    mDialogs.front()->Render();
}
//---------------------------------------------------------------------------
void TDialogStack::RenderNextDialog(TDialog* pCurrent)
{
    auto fit = std::find(mDialogs.begin(), mDialogs.end(), pCurrent);
    BL_ASSERT(fit != mDialogs.end());

    fit++;

    if (fit == mDialogs.end()) {
        return;
    }

    fit.operator*()->Render();
}
//---------------------------------------------------------------------------
void TDialogStack::Add(TDialog* pDialog)
{
    pDialog->SetStack(this);

    mDialogs.push_back(pDialog);
}
//---------------------------------------------------------------------------
void TDialogStack::Remove(TDialog* pDialog)
{
    pDialog->SetStack(nullptr);

    mDialogs.remove(pDialog);
}
//---------------------------------------------------------------------------
