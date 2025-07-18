/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <string>
#include <vector>
#include <functional>

#include "Base/Common/TypeDef.h"
#include "Base/Common/CmdParam.h"

class DllExport TInputByCmd
{
protected:
    TCmdParam mCmdParam;
    typedef std::vector<std::string> TVectorStr;
    TVectorStr mVecDefKey;
private:

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