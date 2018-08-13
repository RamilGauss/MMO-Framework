/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ControlClippingCursorH
#define ControlClippingCursorH

#include "TypeDef.h"

class DllExport TControlClippingCursor
{
public:
  
  TControlClippingCursor();
  ~TControlClippingCursor();

  void Init(size_t handleWin);

  struct TRect
  {
    int x;
    int y;
    int w;
    int h;
  };
  void SetClipRect(TRect& rect);
  void GetClipRect(TRect& rect);

  void Unclip();
protected:
  TRect mRect;
  size_t mHandleWin;
};

#endif
