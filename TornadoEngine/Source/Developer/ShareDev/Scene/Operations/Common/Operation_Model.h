/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef Operation_ModelH
#define Operation_ModelH

#include "BaseOperation_Pattern.h"

class TPattern_Model;

class DllExport TOperation_Model : public TBaseOperation_Pattern
{
protected:

  TPattern_Model* mPatternModel;
public:

  TOperation_Model();
  virtual ~TOperation_Model();

  virtual void SetPattern(TBehaviourPattern* pPattern);
  // концепция работы с Operation: 
  //       вызов метода операции (поэтому интерфейс должен быть сформирован), 
  //       операция берёт данные из паттерна, производит работу,
  //       результат помещает в паттерн.
};

#endif
