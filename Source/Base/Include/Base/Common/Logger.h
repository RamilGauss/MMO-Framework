/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <string>

#include "Base/Common/SaveToFile.h"
#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TLogger
    {
        typedef std::vector<TSaveToFile*> TVectorPtr;
        TVectorPtr mVecPtr;

        struct TDescFile
        {
            std::string sExtension;
            TSaveToFile stf;
        };

        typedef std::map<std::string, TDescFile*> TMapStrPtr;
        TMapStrPtr mMapNamePtr;

        std::string sPrefix;

        bool flgPrintf;
        bool flgEnable;
        bool flgBuffer;

    public:
        TLogger()
        {
            flgPrintf = true;
            flgEnable = true;
            flgBuffer = true;
        }

        virtual ~TLogger();

        // return false if name is same
        bool Register(const std::string& nameLogger, const std::string& extension = "log");

        void Init(const std::string& sPrefix);
        void Done();
        TSaveToFile* Get(const std::string& nameLog);

        void SetPrintf(bool val);
        bool GetPrintf();

        void SetEnable(bool val);
        bool GetEnable();

        void SetBufferization(bool val);
        bool GetBufferization();

        int GetCount();
        TSaveToFile* GetByIndex(int index);

    protected:
        void InitLogger(TSaveToFile* saver, const std::string& sName, const std::string& extension);
    };
}
