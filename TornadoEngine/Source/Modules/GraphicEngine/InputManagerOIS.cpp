/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "InputManagerOIS.h"

using namespace std;

#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
#include <windows.h>
#endif

#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
//----------------------------------------------------------------------------------
MyGUI::Char translateWin32Text(MyGUI::KeyCode kc)
{
	static WCHAR deadKey = 0;

	BYTE keyState[256];
	HKL  layout = GetKeyboardLayout(0);
	if ( GetKeyboardState(keyState) == 0 )
		return 0;

	int code = *((int*)&kc);
	unsigned int vk = MapVirtualKeyEx((UINT)code, 3, layout);
	if ( vk == 0 )
		return 0;

	WCHAR buff[3] = { 0, 0, 0 };
	int ascii = ToUnicodeEx(vk, (UINT)code, keyState, buff, 3, 0, layout);
	if (ascii == 1 && deadKey != '\0' )
	{
		// A dead key is stored and we have just converted a character key
		// Combine the two into a single character
		WCHAR wcBuff[3] = { buff[0], deadKey, '\0' };
		WCHAR out[3];

		deadKey = '\0';
		if (FoldStringW(MAP_PRECOMPOSED, (LPWSTR)wcBuff, 3, (LPWSTR)out, 3))
			return out[0];
	}
	else if (ascii == 1)
	{
		// We have a single character
		deadKey = '\0';
		return buff[0];
	}
	else if (ascii == 2)
	{
		// Convert a non-combining diacritical mark into a combining diacritical mark
		// Combining versions range from 0x300 to 0x36F; only 5 (for French) have been mapped below
		// http://www.fileformat.info/info/unicode/block/combining_diacritical_marks/images.htm
		switch (buff[0])
		{
		case 0x5E: // Circumflex accent: в
			deadKey = 0x302;
			break;
		case 0x60: // Grave accent: а
			deadKey = 0x300;
			break;
		case 0xA8: // Diaeresis: ь
			deadKey = 0x308;
			break;
		case 0xB4: // Acute accent: й
			deadKey = 0x301;
			break;
		case 0xB8: // Cedilla: з
			deadKey = 0x327;
			break;
		default:
			deadKey = buff[0];
			break;
		}
	}
	return 0;
}
#endif
//----------------------------------------------------------------------------------
TInputManagerOIS::TInputManagerOIS() :
mInputManager(0), mKeyboard(0), mMouse(0),
mCursorX(0), mCursorY(0)
{
}
//----------------------------------------------------------------------------------
TInputManagerOIS::~TInputManagerOIS()
{
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::CreateInput(size_t _handle)
{
	std::ostringstream windowHndStr;
	windowHndStr << _handle;

	OIS::ParamList pl;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
#if defined OIS_WIN32_PLATFORM
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
#elif defined OIS_LINUX_PLATFORM
	pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
	pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
	pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
	pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
#endif

	mInputManager = OIS::InputManager::createInputSystem(pl);

	mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
	mKeyboard->setEventCallback(this);

	mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));
	mMouse->setEventCallback(this);
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::DestroyInput()
{
	if(mInputManager)
	{
		if(mMouse)
		{
			mInputManager->destroyInputObject( mMouse );
			mMouse = nullptr;
		}
		if(mKeyboard)
		{
			mInputManager->destroyInputObject( mKeyboard );
			mKeyboard = nullptr;
		}
		OIS::InputManager::destroyInputSystem(mInputManager);
		mInputManager = nullptr;
	}
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::CaptureInput()
{
	if(mMouse)    mMouse->capture();
	if(mKeyboard) mKeyboard->capture();
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::SetInputViewSize(int _width, int _height)
{
	if(mMouse)
	{
		const OIS::MouseState& ms = mMouse->getMouseState();
		ms.width = _width;
		ms.height = _height;

		CheckPosition();
	}
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::SetMousePosition(int _x, int _y)
{
	mCursorX = _x;
	mCursorY = _y;

	CheckPosition();
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::CheckPosition()
{
	const OIS::MouseState& ms = mMouse->getMouseState();

	if(mCursorX < 0)
		mCursorX = 0;
	else if (mCursorX >= ms.width)
		mCursorX = ms.width - 1;

	if (mCursorY < 0)
		mCursorY = 0;
	else if (mCursorY >= ms.height)
		mCursorY = ms.height - 1;
}
//----------------------------------------------------------------------------------
void TInputManagerOIS::ConvertOIS2MyGUI(const OIS::KeyEvent &arg, MyGUI::Char& text, MyGUI::KeyCode& key )
{
  text = (MyGUI::Char)arg.text;
  key = MyGUI::KeyCode::Enum(arg.key);
  int scan_code = key.getValue();

  if (scan_code > 70 && scan_code < 84)
  {
    static MyGUI::Char nums[13] = { 55, 56, 57, 45, 52, 53, 54, 43, 49, 50, 51, 48, 46 };
    text = nums[scan_code-71];
  }
  else if (key == MyGUI::KeyCode::Divide)
  {
    text = '/';
  }
  else
  {
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
    text = translateWin32Text(key);
#endif
  }
}
//----------------------------------------------------------------------------------
#define KEY_TO_STR(K) \
case OIS::K: \
  sResult = #K; \
break;

string TInputManagerOIS::ConvertKey2Str(const OIS::KeyCode key)
{
  string sResult;
  switch(key)
  {
    KEY_TO_STR(KC_UNASSIGNED  );
    KEY_TO_STR(KC_ESCAPE      );
    KEY_TO_STR(KC_1           );
    KEY_TO_STR(KC_2           );
    KEY_TO_STR(KC_3           );
    KEY_TO_STR(KC_4           );
    KEY_TO_STR(KC_5           );
    KEY_TO_STR(KC_6           );
    KEY_TO_STR(KC_7           );
    KEY_TO_STR(KC_8           );
    KEY_TO_STR(KC_9           );
    KEY_TO_STR(KC_0           );
    KEY_TO_STR(KC_MINUS       );
    KEY_TO_STR(KC_EQUALS      );
    KEY_TO_STR(KC_BACK        );
    KEY_TO_STR(KC_TAB         );
    KEY_TO_STR(KC_Q           );
    KEY_TO_STR(KC_W           );
    KEY_TO_STR(KC_E           );
    KEY_TO_STR(KC_R           );
    KEY_TO_STR(KC_T           );
    KEY_TO_STR(KC_Y           );
    KEY_TO_STR(KC_U           );
    KEY_TO_STR(KC_I           );
    KEY_TO_STR(KC_O           );
    KEY_TO_STR(KC_P           );
    KEY_TO_STR(KC_LBRACKET    );
    KEY_TO_STR(KC_RBRACKET    );
    KEY_TO_STR(KC_RETURN      );
    KEY_TO_STR(KC_LCONTROL    );
    KEY_TO_STR(KC_A           );
    KEY_TO_STR(KC_S           );
    KEY_TO_STR(KC_D           );
    KEY_TO_STR(KC_F           );
    KEY_TO_STR(KC_G           );
    KEY_TO_STR(KC_H           );
    KEY_TO_STR(KC_J           );
    KEY_TO_STR(KC_K           );
    KEY_TO_STR(KC_L           );
    KEY_TO_STR(KC_SEMICOLON   );
    KEY_TO_STR(KC_APOSTROPHE  );
    KEY_TO_STR(KC_GRAVE       );
    KEY_TO_STR(KC_LSHIFT      );
    KEY_TO_STR(KC_BACKSLASH   );
    KEY_TO_STR(KC_Z           );
    KEY_TO_STR(KC_X           );
    KEY_TO_STR(KC_C           );
    KEY_TO_STR(KC_V           );
    KEY_TO_STR(KC_B           );
    KEY_TO_STR(KC_N           );
    KEY_TO_STR(KC_M           );
    KEY_TO_STR(KC_COMMA       );
    KEY_TO_STR(KC_PERIOD      );
    KEY_TO_STR(KC_SLASH       );
    KEY_TO_STR(KC_RSHIFT      );
    KEY_TO_STR(KC_MULTIPLY    );
    KEY_TO_STR(KC_LMENU       );
    KEY_TO_STR(KC_SPACE       );
    KEY_TO_STR(KC_CAPITAL     );
    KEY_TO_STR(KC_F1          );
    KEY_TO_STR(KC_F2          );
    KEY_TO_STR(KC_F3          );
    KEY_TO_STR(KC_F4          );
    KEY_TO_STR(KC_F5          );
    KEY_TO_STR(KC_F6          );
    KEY_TO_STR(KC_F7          );
    KEY_TO_STR(KC_F8          );
    KEY_TO_STR(KC_F9          );
    KEY_TO_STR(KC_F10         );
    KEY_TO_STR(KC_NUMLOCK     );
    KEY_TO_STR(KC_SCROLL      );
    KEY_TO_STR(KC_NUMPAD7     );
    KEY_TO_STR(KC_NUMPAD8     );
    KEY_TO_STR(KC_NUMPAD9     );
    KEY_TO_STR(KC_SUBTRACT    );
    KEY_TO_STR(KC_NUMPAD4     );
    KEY_TO_STR(KC_NUMPAD5     );
    KEY_TO_STR(KC_NUMPAD6     );
    KEY_TO_STR(KC_ADD         );
    KEY_TO_STR(KC_NUMPAD1     );
    KEY_TO_STR(KC_NUMPAD2     );
    KEY_TO_STR(KC_NUMPAD3     );
    KEY_TO_STR(KC_NUMPAD0     );
    KEY_TO_STR(KC_DECIMAL     );
    KEY_TO_STR(KC_OEM_102     );
    KEY_TO_STR(KC_F11         );
    KEY_TO_STR(KC_F12         );
    KEY_TO_STR(KC_F13         );
    KEY_TO_STR(KC_F14         );
    KEY_TO_STR(KC_F15         );
    KEY_TO_STR(KC_KANA        );
    KEY_TO_STR(KC_ABNT_C1     );
    KEY_TO_STR(KC_CONVERT     );
    KEY_TO_STR(KC_NOCONVERT   );
    KEY_TO_STR(KC_YEN         );
    KEY_TO_STR(KC_ABNT_C2     );
    KEY_TO_STR(KC_NUMPADEQUALS);
    KEY_TO_STR(KC_PREVTRACK   );
    KEY_TO_STR(KC_AT          );
    KEY_TO_STR(KC_COLON       );
    KEY_TO_STR(KC_UNDERLINE   );
    KEY_TO_STR(KC_KANJI       );
    KEY_TO_STR(KC_STOP        );
    KEY_TO_STR(KC_AX          );
    KEY_TO_STR(KC_UNLABELED   );
    KEY_TO_STR(KC_NEXTTRACK   );
    KEY_TO_STR(KC_NUMPADENTER );
    KEY_TO_STR(KC_RCONTROL    );
    KEY_TO_STR(KC_MUTE        );
    KEY_TO_STR(KC_CALCULATOR  );
    KEY_TO_STR(KC_PLAYPAUSE   );
    KEY_TO_STR(KC_MEDIASTOP   );
    KEY_TO_STR(KC_VOLUMEDOWN  );
    KEY_TO_STR(KC_VOLUMEUP    );
    KEY_TO_STR(KC_WEBHOME     );
    KEY_TO_STR(KC_NUMPADCOMMA );
    KEY_TO_STR(KC_DIVIDE      );
    KEY_TO_STR(KC_SYSRQ       );
    KEY_TO_STR(KC_RMENU       );
    KEY_TO_STR(KC_PAUSE       );
    KEY_TO_STR(KC_HOME        );
    KEY_TO_STR(KC_UP          );
    KEY_TO_STR(KC_PGUP        );
    KEY_TO_STR(KC_LEFT        );
    KEY_TO_STR(KC_RIGHT       );
    KEY_TO_STR(KC_END         );
    KEY_TO_STR(KC_DOWN        );
    KEY_TO_STR(KC_PGDOWN      );
    KEY_TO_STR(KC_INSERT      );
    KEY_TO_STR(KC_DELETE      );
    KEY_TO_STR(KC_LWIN        );
    KEY_TO_STR(KC_RWIN        );
    KEY_TO_STR(KC_APPS        );
    KEY_TO_STR(KC_POWER       );
    KEY_TO_STR(KC_SLEEP       );
    KEY_TO_STR(KC_WAKE        );
    KEY_TO_STR(KC_WEBSEARCH   );
    KEY_TO_STR(KC_WEBFAVORITES);
    KEY_TO_STR(KC_WEBREFRESH  );
    KEY_TO_STR(KC_WEBSTOP     );
    KEY_TO_STR(KC_WEBFORWARD  );
    KEY_TO_STR(KC_WEBBACK     );
    KEY_TO_STR(KC_MYCOMPUTER  );
    KEY_TO_STR(KC_MAIL        );
    KEY_TO_STR(KC_MEDIASELECT );
  }

  return sResult;
}
//----------------------------------------------------------------------------------
