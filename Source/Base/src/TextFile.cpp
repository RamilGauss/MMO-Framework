/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/
#include "Base/Common/TextFile.h"


TTextFile::TTextFile(const std::string& path)
{
    mPath = path;
}
//-------------------------------------------------------------------
void TTextFile::Load(std::string& str)
{
    if (mLoader.ReOpen((char*) mPath.data()) == false) {
        return;
    }

    TContainer c;
    mLoader.ReadSmall(c);
    str = std::string(c.GetPtr(), c.GetSize());
}
//-------------------------------------------------------------------
void TTextFile::Load(const std::string& path, std::string& str)
{
    TTextFile tf(path);
    tf.Load(str);
}
//-------------------------------------------------------------------
void TTextFile::Save(std::string& str, bool append)
{
    if (mSaver.ReOpen((char*) mPath.data(), append) == false) {
        return;
    }
    mSaver.Write((char*) str.data(), str.length());
}
//-------------------------------------------------------------------
void TTextFile::Save(const std::string& path, std::string& str, bool append)
{
    TTextFile tf(path);
    tf.Save(str, append);
}
//-------------------------------------------------------------------
