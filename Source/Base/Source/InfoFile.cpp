/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/InfoFile.h"

namespace nsBase::nsCommon
{
    TInfoFile::TInfoFile()
    {
        pFile = NULL;
    }
    //------------------------------------------------------------------
    TInfoFile::~TInfoFile()
    {
        Close();
    }
    //------------------------------------------------------------------
    bool TInfoFile::IsExist(char* path)
    {
        if (path == NULL) {
            return false;
        }

        const char* sMode = "r";
        FILE* pTmpFile = fopen(path, sMode);
        if (pTmpFile == NULL) {
            return false;
        }

        fclose(pTmpFile);
        return true;
    }
    //------------------------------------------------------------------
    bool TInfoFile::IsOpen()
    {
        return (pFile != NULL);
    }
    //------------------------------------------------------------------
    void TInfoFile::Close()
    {
        if (pFile == NULL) {
            return;
        }
        fclose(pFile);
        pFile = NULL;
    }
    //------------------------------------------------------------------
    void TInfoFile::GetName(std::string& path_name)
    {
        if (IsOpen() == false) {
            return;
        }
        // первый тип разделителя
        int index = sPath.rfind('\\');
        if (index == -1) {
            // второй тип разделителя
            index = sPath.rfind('/');
        }
        path_name = sPath.data() + index + 1;
    }
    //------------------------------------------------------------------
    void TInfoFile::GetPath(std::string& path_name)
    {
        if (IsOpen() == false) {
            return;
        }
        path_name = sPath;
    }
    //------------------------------------------------------------------
}
