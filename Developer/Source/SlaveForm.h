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

class TTestControlTank;

class SlaveForm : public QWidget
{
  Q_OBJECT

	TTestControlTank* mTCT;

public:
  SlaveForm(QWidget *parent = NULL);
  ~SlaveForm();

	void SetControlTank(TTestControlTank* pTCT);

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
		void sl_DownPressed();
		void sl_UpPressed();
		void sl_LeftPressed();
		void sl_RightPressed();
		void sl_DownReleased();
		void sl_UpReleased();
		void sl_LeftReleased();
		void sl_RightReleased();

private:
  typedef std::map<unsigned int,TDesc> TMapUintDesc;
  typedef TMapUintDesc::iterator TMapUintDescIt;
  TMapUintDesc mMapID_SessionDesc;

private:
  Ui::SlaveFormClass ui;
};

#endif
