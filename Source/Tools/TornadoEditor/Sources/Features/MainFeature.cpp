/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEditor/Sources/Features/MainFeature.h"

using namespace nsTornadoEditor;

void TMainFeature::InitConveyor()
{
    Add(&mInitWindowsFeature);
    //Add(&mFileHierarchyWindowRefreshSystem);
    //Add(&mObjectHierarchyWindowRefreshSystem);
}
