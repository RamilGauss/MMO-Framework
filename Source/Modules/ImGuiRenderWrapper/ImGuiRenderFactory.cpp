/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiRenderFactory.h"
#include "Directx9_ImGuiRender.h"

using namespace nsImGuiRenderWrapper;

IImGuiRender* TImGuiRenderFactory::Make(Implementation implementaion)
{
    IImGuiRender* render = nullptr;
    switch (implementaion) {
        case Implementation::DIRECTX_9:
            render = new TDirectx9_ImGuiRender();
            break;
        case Implementation::DIRECTX_10:
            //render = new TDirectx10_ImGuiRender();
            break;
        case Implementation::DIRECTX_11:
            //render = new TDirectx11_ImGuiRender();
            break;
        case Implementation::DIRECTX_12:
            //render = new TDirectx12_ImGuiRender();
            break;
        case Implementation::OPEN_GL_2:
            //render = new TOpenGL2_ImGuiRender();
            break;
        case Implementation::OPEN_GL_3:
            //render = new TOpenGL3_ImGuiRender();
            break;
    }
    return render;
}
//--------------------------------------------------------------------------------------
void TImGuiRenderFactory::Done(IImGuiRender* render)
{
    delete render;
}
//--------------------------------------------------------------------------------------