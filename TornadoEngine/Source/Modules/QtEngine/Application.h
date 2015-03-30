/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class TApplication : public QApplication
{
  Q_OBJECT

public:
  TApplication(int arc, char** arv);

protected:
  virtual void customEvent(QEvent *pE);
};


#endif