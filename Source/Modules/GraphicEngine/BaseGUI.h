/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef BaseGUIH
#define BaseGUIH

//#include <MyGUI.h>
#include <atlconv.h>
#include <boost/lexical_cast.hpp>

//#include "BaseLayout/BaseLayout.h"
#include "TypeDef.h"
#include "CallBackRegistrator.h"

#ifdef WIN32
#pragma warning(disable: 4275)
#endif

#define ASSIGN_WIDGET(name) \
assignWidget(name,#name);

class DllExport TBaseGUI// : public wraps::BaseLayout
{
    TCallBackRegistrator0 mCB_Show;
    TCallBackRegistrator0 mCB_Hide;

protected:
    //MyGUI::VectorWidgetPtr mVectorChild_Tab;

public:
    TBaseGUI() {};
    virtual ~TBaseGUI() {};

    //virtual void Show();
    //virtual void Hide();

    TCallBackRegistrator0* GetCB_Show();
    TCallBackRegistrator0* GetCB_Hide();

    //bool IsVisible();

    //void Shutdown();

    //template <typename T>
    //T GetValueFromEditBox(MyGUI::EditBox* pEB);

    //template <typename T>
    //void SetValueFromEditBox(MyGUI::EditBox* pEB, T& t);
protected:
    virtual void Activate() = 0;
    virtual const char* GetNameLayout() = 0;
    virtual void* GetParent() = 0;

    virtual void SetupTabChild() {};

    //virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char) {}

private:
    void InitTabJump();
    void RegisterOnKeyEvent();

    //void sl_TabJump(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
    //void sl_KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);

};
//-------------------------------------------------------------------------------
//template <typename T>
//T TBaseGUI::GetValueFromEditBox(MyGUI::EditBox* pEB)
//{
//    USES_CONVERSION;
//    std::string s = W2A((LPCWSTR) pEB->getOnlyText().data());
//    T retValue = s.length() ? boost::lexical_cast<T>(s.data()) : T();
//    return retValue;
//}
//-------------------------------------------------------------------------------
//template <typename T>
//void TBaseGUI::SetValueFromEditBox(MyGUI::EditBox* pEB, T& t)
//{
//    USES_CONVERSION;
//
//    std::string sValue = boost::lexical_cast<std::string>(t);
//    LPWSTR wValue = A2W(sValue.data());
//    pEB->setOnlyText(wValue);
//}
//-------------------------------------------------------------------------------
#endif // BaseGUI
