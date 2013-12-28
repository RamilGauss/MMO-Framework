/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MasterFormH
#define MasterFormH

#include <QWidget>
#include "ui_MasterForm.h"
#include <map>
#include "ShareMisc.h"

class MasterForm : public QWidget
{
  Q_OBJECT

public:
  MasterForm(QWidget *parent = NULL);
  ~MasterForm();

  void SetConnect(bool val);

  struct TDesc
  {
    unsigned int id_session;
    TIP_Port     ip_port;
  };

  // добавление и удаление мастера
  void Add(TDesc& desc);               
  void Delete(unsigned int id_session);
protected:
	virtual void customEvent( QEvent * event  );
	virtual void closeEvent(QCloseEvent * event );

  void Refresh();

protected slots:
  void sl_CreateGroup();

private:
  typedef std::map<unsigned int,TDesc> TMapUintDesc;
  typedef TMapUintDesc::iterator TMapUintDescIt;
  TMapUintDesc mMapID_SessionDesc;
private:
  Ui::MasterFormClass ui;
};

#endif
