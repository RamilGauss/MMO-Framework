/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Node.h"

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
void TNode::SetTexture(void* textureId, int width, int height)
{
    mTextureId = textureId;
    mWidth = width;
    mHeight = height;
}
//-------------------------------------------------------------------------
void TNode::RenderContent(float offset_from_start_x, float spacing)
{
    ImGui::SameLine(offset_from_start_x, spacing);
    if (mTextureId != nullptr) {
        ImGui::Image(mTextureId, ImVec2(mWidth, mHeight));
        ImGui::SameLine();
    }

    mChooseText = ImGui::Selectable(GetTitle().c_str(), false);
}
//-------------------------------------------------------------------------
