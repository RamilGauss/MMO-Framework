/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <windows.h>
#include "MapSystemKey.h"
#include "DescEvent.h"

using namespace nsKey;


int TMapSystemKey::Get(int k)
{
  int res = 0;
  switch(k)
  {
    case '1': res = e_1;   break;
    case '2': res = e_2;   break;
    case '3': res = e_3;   break;
    case '4': res = e_4;   break;
    case '5': res = e_5;   break;
    case '6': res = e_6;   break;
    case '7': res = e_7;   break;
    case '8': res = e_8;   break;
    case '9': res = e_9;   break;
    case '0': res = e_0;   break;
    case 'A': res = e_A;   break;
    case 'B': res = e_B;   break;
    case 'C': res = e_C;   break;
    case 'D': res = e_D;   break;
    case 'E': res = e_E;   break;
    case 'G': res = e_G;   break;
    case 'F': res = e_F;   break;
    case 'I': res = e_I;   break;
    case 'H': res = e_H;   break;
    case 'J': res = e_J;   break;
    case 'K': res = e_K;   break;
    case 'L': res = e_L;   break;
    case 'M': res = e_M;   break;
    case 'N': res = e_N;   break;
    case 'O': res = e_O;   break;
    case 'P': res = e_P;   break;
    case 'Q': res = e_Q;   break;
    case 'R': res = e_R;   break;
    case 'S': res = e_S;   break;
    case 'T': res = e_T;   break;
    case 'U': res = e_U;   break;
    case 'W': res = e_W;   break;
    case 'V': res = e_V;   break;
    case 'X': res = e_X;   break;
    case 'Y': res = e_Y;   break;
    case 'Z': res = e_Z;   break;
    case VK_SPACE:      res = e_Space;    break;
    case VK_PRIOR:      res = e_Prior;    break;
    case VK_NEXT:       res = e_Next;     break;
    case VK_END:        res = e_End;      break;
    case VK_HOME:       res = e_Home;     break;
    case VK_LEFT:       res = e_Left;     break;
    case VK_UP:         res = e_Up;       break;
    case VK_RIGHT:      res = e_Right;    break;
    case VK_DOWN:       res = e_Down;     break;
    case VK_SELECT:     res = e_Select;   break;
    case VK_PRINT:      res = e_Print;    break;
    case VK_EXECUTE:    res = e_Execute;  break;
    case VK_SNAPSHOT:   res = e_Snapshot; break;
    case VK_INSERT:     res = e_Insert;   break;
    case VK_DELETE:     res = e_Delete;   break;
    case VK_HELP:       res = e_Help;     break;
    case VK_BACK:       res = e_Back;     break;
    case VK_TAB:        res = e_Tab;      break;
    case VK_CLEAR:      res = e_Clear;    break;
    case VK_RETURN:     res = e_Return;   break;
    case VK_SHIFT:      res = e_Shift;    break;
    case VK_CONTROL:    res = e_Control;  break;
    case VK_MENU:       res = e_Menu;     break;
    case VK_PAUSE:      res = e_Pause;    break;
    case VK_CAPITAL:    res = e_Capital;  break;
    case VK_KANA:       res = e_Kana;     break;
    case VK_JUNJA:      res = e_Junja;    break;
    case VK_FINAL:      res = e_Final;    break;
    case VK_HANJA:      res = e_Hanja;    break;
    case VK_ESCAPE:     res = e_Escape;   break;
    case VK_CONVERT:    res = e_Convert;  break;
    case VK_NONCONVERT: res = e_Nonconvert;break;
    case VK_ACCEPT:     res = e_Accept;    break;
    case VK_MODECHANGE: res = e_Modechange;break;
    case VK_LWIN:       res = e_LWin;      break;
    case VK_RWIN:       res = e_RWin;      break;
    case VK_APPS:       res = e_Apps;      break;
    case VK_SLEEP:      res = e_Sleep;     break;
    case VK_NUMPAD0:    res = e_Numpad0;   break;
    case VK_NUMPAD1:    res = e_Numpad1;   break;
    case VK_NUMPAD2:    res = e_Numpad2;   break;
    case VK_NUMPAD3:    res = e_Numpad3;   break;
    case VK_NUMPAD4:    res = e_Numpad4;   break;
    case VK_NUMPAD5:    res = e_Numpad5;   break;
    case VK_NUMPAD6:    res = e_Numpad6;   break;
    case VK_NUMPAD7:    res = e_Numpad7;   break;
    case VK_NUMPAD8:    res = e_Numpad8;   break;
    case VK_NUMPAD9:    res = e_Numpad9;   break;
    case VK_MULTIPLY:   res = e_Multiply;  break;
    case VK_ADD:        res = e_Add;       break;
    case VK_SEPARATOR:  res = e_Separator; break;
    case VK_SUBTRACT:   res = e_Subtract;  break;
    case VK_DECIMAL:    res = e_Decimal;   break;
    case VK_DIVIDE:     res = e_Divide;     break;
    case VK_F1:         res = e_F1;         break;
    case VK_F2:         res = e_F2;         break;
    case VK_F3:         res = e_F3;         break;
    case VK_F4:         res = e_F4;         break;
    case VK_F5:         res = e_F5;         break;
    case VK_F6:         res = e_F6;         break;
    case VK_F7:         res = e_F7;         break;
    case VK_F8:         res = e_F8;         break;
    case VK_F9:         res = e_F9;         break;
    case VK_F10:        res = e_F10;        break;
    case VK_F11:        res = e_F11;        break;
    case VK_F12:        res = e_F12;        break;
    case VK_F13:        res = e_F13;        break;
    case VK_F14:        res = e_F14;        break;
    case VK_F15:        res = e_F15;        break;
    case VK_F16:        res = e_F16;        break;
    case VK_F17:        res = e_F17;        break;
    case VK_F18:        res = e_F18;        break;
    case VK_F19:        res = e_F19;        break;
    case VK_F20:        res = e_F20;        break;
    case VK_F21:        res = e_F21;        break;
    case VK_F22:        res = e_F22;        break;
    case VK_F23:        res = e_F23;        break;
    case VK_F24:        res = e_F24;        break;
    case VK_NUMLOCK:    res = e_Numlock;    break;
    case VK_SCROLL:     res = e_Scroll;     break;
    case VK_LSHIFT:     res = e_LShift;     break;
    case VK_RSHIFT:     res = e_RShift;     break;
    case VK_LCONTROL:   res = e_LControl;   break;
    case VK_RCONTROL:   res = e_RControl;   break;
    case VK_LMENU:      res = e_LMenu;      break;
    case VK_RMENU:      res = e_RMenu;      break;
  }
  return res;                                    
}
//--------------------------------------------------------------

