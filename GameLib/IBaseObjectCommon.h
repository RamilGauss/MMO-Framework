/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBaseObjectCommonH
#define IBaseObjectCommonH

#include "IBaseObjectGE.h"
#include "IBaseObjectPrediction.h"


class IBaseObjectCommon : public IBaseObjectGE, public IBaseObjectPrediction
{

public:
  IBaseObjectCommon();
  virtual ~IBaseObjectCommon();


  // зеркальное отражение такого же объекта на "той стороне"
  // отдать свое сообщение
  virtual bool GetMirror(char** pData, int& size) = 0;
  // настроиться объекту
  virtual void SetMirror(char* pData, int size) = 0;

  // реакция на человеческие действия
  virtual void SetHuman(char* pData, int size){};// для активных объектов, управляемых на клиентской стороне


  // не забыть!!!!!!!
  // delete []p;
  virtual int GetSizeProperty(){return 0;};
  virtual char* GetProperty(){return NULL;};
  virtual void SetProperty(char* pData,int size){};

};
//-------------------------------------------------------------

#endif