/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InitWindowsFeature.h"

namespace nsTornadoEditor
{
    void TInitWindowsFeature::InitConveyor()
    {
        Add(&mFileHierarchyWindowInitSystem);
        Add(&mObjectHierarchyWindowInitSystem);
    }
}