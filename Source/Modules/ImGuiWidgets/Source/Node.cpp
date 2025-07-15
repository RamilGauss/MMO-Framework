/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ImGuiWidgets/Include/Node.h"

using namespace nsImGuiWidgets;

TNode::TNode() : TWidgetContainer(this)
{

}
//-------------------------------------------------------------------------
TWidget::SubType TNode::GetSubType() const
{
    return SubType::NODE;
}
//-------------------------------------------------------------------------
