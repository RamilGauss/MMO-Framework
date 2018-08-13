/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "GraphicEngine/BaseGUI.h"
#include <MyGUI.h>
#include <Ogre.h>
#include <vector>

class TDialogOpenSave : public TBaseGUI
{
public:
  typedef enum
  {
    eUndef, eAccept, eReject
  } Result;

  TDialogOpenSave();
  virtual ~TDialogOpenSave();

  struct TInitStruct
  {
    bool readOnly_ebName;

    int         currentItem;
    std::string nameCurrentItem;
    std::vector<std::string> vecItems;

    std::string caption;
    std::string nameButton;
  };

  void Init( TInitStruct& initStruct );

  Result GetResult();
  std::string GetResultName();
protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent( MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char );
protected:
  void sl_Action( MyGUI::Widget* _sender );
  void sl_Close( MyGUI::Window* _sender, const std::string& _name );

  void sl_DoubleSelectItem( MyGUI::ListBox* _sender, size_t _index );
  void sl_SelectItem( MyGUI::ListBox* _sender, size_t _index );

  void SelectItem( int index );

  void ShowEvent();

  void Accept();
  void Reject();
protected:
  MyGUI::Button*  bAction;
  MyGUI::EditBox* ebName;
  MyGUI::ListBox* lbItems;

  Result mResultExec;

  TInitStruct mInitStruct;
};
