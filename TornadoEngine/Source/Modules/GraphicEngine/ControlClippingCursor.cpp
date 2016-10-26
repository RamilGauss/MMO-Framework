#include "ControlClippingCursor.h"

#ifdef WIN32
#include <windows.h>
#endif

TControlClippingCursor::TControlClippingCursor()
{

}
//-----------------------------------------------------------------------------
TControlClippingCursor::~TControlClippingCursor()
{
  Unclip();
}
//-----------------------------------------------------------------------------
void TControlClippingCursor::Init(size_t handleWin)
{
  mHandleWin = handleWin;
}
//-----------------------------------------------------------------------------
void TControlClippingCursor::SetClipRect(TRect& rect)
{
  mRect = rect;
#ifdef WIN32
  RECT rc;
  POINT point;
  point.x = mRect.x;
  point.y = mRect.y;
  ClientToScreen((HWND)mHandleWin, &point);
  rc.left = point.x;
  rc.top  = point.y;

  point.x = mRect.w;
  point.y = mRect.h;
  ClientToScreen((HWND)mHandleWin, &point);
  rc.right  = point.x;
  rc.bottom = point.y;

  ClipCursor(&rc);
#else
  // TODO: X11, how clip cursor?
#endif
}
//-----------------------------------------------------------------------------
void TControlClippingCursor::GetClipRect(TRect& rect)
{
  rect = mRect;
}
//-----------------------------------------------------------------------------
void TControlClippingCursor::Unclip()
{
#ifdef WIN32
  RECT rc;
  rc.left = 0;
  rc.top  = 0;
  rc.right  = 10000;
  rc.bottom = 10000;
  ClipCursor(&rc);
#else

#endif
}
//-----------------------------------------------------------------------------
