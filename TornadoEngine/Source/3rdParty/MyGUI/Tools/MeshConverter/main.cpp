/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <QWindowsStyle>
#include "MainForm.h"

int main(int argc, char *argv[])
{
  QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));

  QApplication a(argc, argv);

  TMainForm mainForm;
  mainForm.show();

  a.exec();

  return 0;
}
