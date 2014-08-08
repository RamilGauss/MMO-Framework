/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ProgressBarH
#define ProgressBarH

struct IDirect3DDevice9;

class TProgressBar
{

public:
  TProgressBar();
  virtual ~TProgressBar();

  void CreateDeviceEvent(IDirect3DDevice9* pDevice);
  void VisualEvent(unsigned char procent);
  void Clear();

};


#endif