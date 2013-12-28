/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef IActorH
#define IActorH

#include <string>
#include "IBaseObjectCommon.h"

class IRoom;

//------------------------------------------------------------------------------
/*
  Активный участник сцены.
*/
class IActor : public IBaseObjectCommon
{
  unsigned int mID_Client;
  IRoom* pRoom;

public:
  IActor();
  virtual ~IActor();
  //--------------------------------------------------------------------------------
  // от IBaseObjectCommon
  virtual bool GetMirror(char** pData, int& size){return false;}
  virtual void SetMirror(char* pData, int size){}

  // IActor интерфейс
  void SetType(unsigned int id);
  unsigned int GetType();
//--------------------------------------------------------------------------------
public:

  void SetID_Client(unsigned int id);
  unsigned int GetID_Client();

protected:
};
//-----------------------------------------------------------------------------


#endif

