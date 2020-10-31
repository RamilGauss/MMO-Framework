/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include "FileLexer.h"
#include "TokenInfoManager.h"
#include "TypeManager.h"
#include "SingletonManager.h"

using namespace nsReflectionCodeGenerator;

TFileLexer::TFileLexer()
{
    mTokenMng = SingletonManager()->Get<TTokenInfoManager>();
    mTypeMng = SingletonManager()->Get<TTypeManager>();
    mConfig = SingletonManager()->Get<TConfigContainer>()->Config();
}
//---------------------------------------------------------------------------------------
void TFileLexer::Work()
{
    while (true) {
        auto tokenListPtr = SelectFile();
        if (tokenListPtr == nullptr)
            return;

        auto fileName = std::filesystem::path(mCurrentFile.data()).filename().string();
        TAST_StateMachine ast(tokenListPtr, fileName);
        ast.Work();
    }
}
//---------------------------------------------------------------------------------------
TTokenInfoManager::TTokenInfoList* TFileLexer::SelectFile()
{
    auto bit = mTokenMng->mTokenInfoMap.begin();// мне просто лень писать весь тип итератора
    if (mCurrentFile.length() > 0) {
        bit = mTokenMng->mTokenInfoMap.find(mCurrentFile);
        bit++;
    }
    if (bit == mTokenMng->mTokenInfoMap.end())
        return nullptr;
    mCurrentFile = bit->first;
    return &(bit->second);
}
//---------------------------------------------------------------------------------------
