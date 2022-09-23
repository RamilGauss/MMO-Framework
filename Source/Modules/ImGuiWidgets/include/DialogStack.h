/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "GraphicEngine/IRenderable.h"

namespace nsImGuiWidgets
{
    class TDialog;

    class DllExport TDialogStack : public nsGraphicEngine::IRenderable
    {
        std::list<TDialog*> mDialogs;

    public:
        void Render() override;

        void Add(TDialog* pDialog);
        void Remove(TDialog* pDialog);
    protected:
        friend class TDialog;

        void RenderNextDialog(TDialog* pCurrent);

    };
}
