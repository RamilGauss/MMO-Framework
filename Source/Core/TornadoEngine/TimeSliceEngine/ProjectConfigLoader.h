/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#pragma once

#include "TypeDef.h"
#include "Logger.h"
#include "ProjectConfigContainer.h"
#include "TimeSliceEngine.h"

namespace nsTornadoEngine
{
    class DllExport TProjectConfigLoader
    {
        static TProjectConfigContainer* mPcc;
    public:
        static bool Load(TProjectConfigContainer* pcc);
    private:
        static bool LoadProjectConfig();
        static bool LoadConveyor();
        static bool LoadBinary();
        static bool LoadResources();

        template<typename ... Args>
        static void Log(const char* format, Args && ... args)
        {
            GetLogger(TTimeSliceEngine::NAME)->WriteF_time(format, std::forward<Args>(args)...);
        }

        template<typename T>
        static bool Load(std::string absPath, T* p)
        {
            std::string jsonContent;
            TTextFile::Load(absPath, jsonContent);
            if (jsonContent.length() == 0) {
                Log("%s no such file", absPath.c_str());
                return false;
            }
            std::string err;
            auto deserResult = TTornadoEngineJsonSerializer::Deserialize(p, jsonContent, err);
            if (!deserResult) {
                Log("%s %s", absPath.c_str(), err.c_str());
            }
            return deserResult;
        }
        //------------------------------------------------------------------------

    };
}