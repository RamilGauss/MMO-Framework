/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <string>
#include "Base/Common/ContainerTypes.h"
#include "Base/Common/ConverterLocale.h"

//------------------------------------------------------------------------------
#if defined(_WIN32)//-----------------------------------------------------------
//------------------------------------------------------------------------------
#include <windows.h>
#include <shlwapi.h>
#include "Base/Common/BL_Debug.h"

bool BL_MessageBug_Utf8(const char* sMsgUtf8)
{
    size_t lenMsgUtf8 = strlen(sMsgUtf8);
    TContainer cUtf8;
    cUtf8.SetData((char*)sMsgUtf8, lenMsgUtf8);
    TConverterLocale cnvUtf8ToWin1251;
    TContainer cWin1251 = cnvUtf8ToWin1251.ConvertUtf8ToCp1251(cUtf8);
    return BL_MessageBug(cWin1251.GetPtr());
}
//-----------------------------------------------------------------------------
// Сообщение об ошибке зафиксированной в теле программы
// lpszMsg - текст сообщения
// вернет реакцию пользователя на сообщение - OK - true, Cancel - false
//******************************************************************************
bool BL_MessageBug(const char* lpszMsg)
{
    std::string text;
    text = lpszMsg;
    char caption[MAX_PATH];
    //if (::GetModuleFileNameA(NULL, caption, MAX_PATH))
    //    PathStripPathA(caption);
    //else
        lstrcpy(caption, "Зафиксирован сбой");

    if (::MessageBoxA(NULL, text.data(), caption, MB_OKCANCEL | MB_SYSTEMMODAL | MB_TOPMOST) != IDOK)
        return false;
    return true;
}
//-----------------------------------------------------------------------------
// Сообщение об ошибке зафиксированной в теле программы
// lpszFileName - имя файла где зафиксирована ошибка
// nLine - номер строки
//******************************************************************************
void BL_MessageBug(const char* lpszFileName, int nLine)
{
    static bool show = true;
    if (show) {
        char text[MAX_PATH];
        wsprintf(text, "%s, %d", lpszFileName, nLine);
        if (BL_MessageBug(text) == false)
            show = false;
    }
}
//------------------------------------------------------------------------------
#else //defined(_WIN32)//-------------------------------------------------------
//------------------------------------------------------------------------------

#include "Base/Common/BL_Debug.h"

//------------------------------------------------------------------------------
bool BL_MessageBug(const char* lpszMsg)
{
    fprintf(stderr, "%s\n", lpszMsg);
    fflush(stderr);
    return true;
}
//------------------------------------------------------------------------------
void BL_MessageBug(const char* lpszFileName, int nLine)
{
    fprintf(stderr, "Fix bug: %s, %d\n", lpszFileName, nLine);
    fflush(stderr);
}
//------------------------------------------------------------------------------
#endif //TD_TARGET
//------------------------------------------------------------------------------

