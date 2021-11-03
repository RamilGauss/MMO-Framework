/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Identity.h"
#include "Geometry.h"

#include <vector>
#include <string>

namespace nsImGuiWidgets
{
    class TWindow;

    struct DllExport TDockNode : public TIdentity, public TGeometry
    {
        enum class Type
        {
            TAB, // with windows
            X_SPLIT, Y_SPLIT // no windows
        };

        Type type = Type::TAB;

        TDockNode* parent = nullptr;


        TDockNode* childs[2] = {nullptr};

        std::vector<std::string> windowNames;
        int selectedWindowIndex = 0;

        bool operator == (const TDockNode& other);

        TDockNode();
        ~TDockNode();

        void Build();

        bool HasDockChilds() const;
    private:
        // new only!
        TDockNode(const TDockNode& other);
        TDockNode& operator = (const TDockNode& other);
    };
}
