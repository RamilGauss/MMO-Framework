/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef MainFormConverter_H
#define MainFormConverter_H

#include "ui_MainForm.h"

#include <QString>
#include <QWidget>
#include <QList>
#include <QFileInfo>

#include "..\GraphicEngine\MeshMakerDX.h"

class TMainForm : public QWidget
{
  Q_OBJECT

  QFileInfoList mListPath;

  TMeshMakerDX      mMeshFile;
  LPDIRECT3DDEVICE9 m_pd3dDevice;
  LPDIRECT3D9       m_pD3D;

public:
  TMainForm(QWidget *parent = NULL);
  virtual ~TMainForm();


protected slots:

  void sl_SetPath();
  void sl_Start();

protected:
  
  void SaveInReestr();
  void LoadFromReestr();

  void MakeListPath();
  void ConvertAll();
  void Convert(QString sPathObj);

  void DestroyDevice();
  void MakeDevice();

private:
  Ui::FormMainForm ui;
};

#endif // EDITORMODEL_H
