/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <string>
#include <vector>

#include "CmdParam.h"
#include <functional>

class DllExport TInputByCmd
{
protected:
    TCmdParam mCmdParam;
private:
    typedef std::vector<std::string> TVectorStr;
    TVectorStr mVecDefKey;

    using ParseFunc = std::function<void(std::string&)>;

    typedef std::map<std::string, ParseFunc> TStrParseFuncMap;
    TStrParseFuncMap mKeyFuncMap;
public:
    virtual void Init() = 0;

    void SetArg(int argc, char** argv);
    void SetArg(std::vector<std::string>& vecArgv);
protected:
    void Add(std::string& sKey, ParseFunc func);
};