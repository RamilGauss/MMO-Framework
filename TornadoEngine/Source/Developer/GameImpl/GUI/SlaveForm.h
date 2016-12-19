/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SlaveFormH
#define SlaveFormH

#include <QWidget>
#include "ui_SlaveForm.h"
#include <map>
#include "ShareMisc.h"

class TSlaveForm : public QWidget
{
  Q_OBJECT

public:
  TSlaveForm(QWidget *parent = NULL);
  ~TSlaveForm();

  void SetConnect(bool val);

  struct TDesc
  {
    unsigned int id_session;
    TIP_Port     ip_port;
  };

  // добавления и удаления клиентов
  void Add(TDesc& desc);
  void Delete(unsigned int id_session);
protected:
  void Update(TDesc* pDesc);
  void Update_MMOEngine(unsigned int* pID);

	virtual void customEvent( QEvent * event  );
	virtual void closeEvent(QCloseEvent * event );

  void Refresh();
protected slots:

private:
  typedef std::map<unsigned int,TDesc> TMapUintDesc;
  typedef TMapUintDesc::iterator TMapUintDescIt;
  TMapUintDesc mMapID_SessionDesc;

private:
  Ui::SlaveFormClass ui;
};

#endif
