/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ui_SlaveForm.h"
#include "SlaveForm.h"

#include "../QtLib/IQtLib.h"
#include "../GameLib/IServerDeveloperTool.h"
#include "TestControlTank.h"


#define GUN_SPEED    0.00035f
#define TURRET_SPEED 0.00035f

SlaveForm::SlaveForm(QWidget *parent)
{
  ui.setupUi(this);

	mTCT = NULL;

	connect(ui.bDown,  SIGNAL(pressed()), this, SLOT(sl_DownPressed()));
	connect(ui.bUp,    SIGNAL(pressed()), this, SLOT(sl_UpPressed()));
	connect(ui.bLeft,  SIGNAL(pressed()), this, SLOT(sl_LeftPressed()));
	connect(ui.bRight, SIGNAL(pressed()), this, SLOT(sl_RightPressed()));

	connect(ui.bDown,  SIGNAL(released()), this, SLOT(sl_DownReleased()));
	connect(ui.bUp,    SIGNAL(released()), this, SLOT(sl_UpReleased()));
	connect(ui.bLeft,  SIGNAL(released()), this, SLOT(sl_LeftReleased()));
	connect(ui.bRight, SIGNAL(released()), this, SLOT(sl_RightReleased()));

	setWindowTitle(tr("Slave"));

  SetConnect(false);
  Refresh();
}
//-----------------------------------------------------------
SlaveForm::~SlaveForm()
{

}
//-----------------------------------------------------------
void SlaveForm::customEvent( QEvent * event)
{

}
//-----------------------------------------------------------
void SlaveForm::closeEvent(QCloseEvent * event)
{
  int type = 0;
  IServerDeveloperTool::Singleton()->GetComponent()->mQtGUI->AddEventCopy(&type,sizeof(type));

  delete this;
}
//-----------------------------------------------------------
void SlaveForm::SetConnect(bool val)
{
  QPixmap pixmap(20,20);
  if(val)
    pixmap.fill(QColor(Qt::green));
  else
    pixmap.fill(QColor(Qt::red));
  ui.lColor->setPixmap(pixmap);
}
//-----------------------------------------------------------
void SlaveForm::Add(TDesc& desc)
{
  mMapID_SessionDesc.insert(TMapUintDesc::value_type(desc.id_session,desc));

  Refresh();
}
//-----------------------------------------------------------
void SlaveForm::Delete(unsigned int id_session)
{
  mMapID_SessionDesc.erase(id_session);

  Refresh();
}
//-----------------------------------------------------------
void SlaveForm::Refresh()
{
  QString sCount = QString("%1").arg(mMapID_SessionDesc.size());
  ui.lCount->setText(sCount);
  ui.table->setRowCount(mMapID_SessionDesc.size());

  union IP
  {
    unsigned char c[4];
    unsigned int  d;
  };

  int iRow = 0;
  BOOST_FOREACH(TMapUintDesc::value_type& bit, mMapID_SessionDesc)
  {
    QTableWidgetItem* item = new QTableWidgetItem;
    QString sSession = QString("%1").arg(bit.second.id_session);
    item->setText(sSession);
    ui.table->setItem(iRow, 0, item);
    //-------------------------------------------------------
    IP ip;
    ip.d = bit.second.ip_port.ip;
    item = new QTableWidgetItem();
    QString sIP_Port = QString("%1.%2.%3.%4:%5").
      arg(ip.c[3]).arg(ip.c[2]).arg(ip.c[1]).arg(ip.c[0]).
      arg(bit.second.ip_port.port);
    item->setText(sIP_Port); 
    ui.table->setItem(iRow, 1, item);
    iRow++;
  }
  ui.table->resizeColumnsToContents();
}
//-----------------------------------------------------------
void SlaveForm::SetControlTank(TTestControlTank* pTCT)
{
	mTCT = pTCT;
}
//-----------------------------------------------------------
void SlaveForm::sl_DownPressed()
{
	mTCT->SetSpeedRotateGun(GUN_SPEED);
}
//-----------------------------------------------------------
void SlaveForm::sl_UpPressed()
{
	mTCT->SetSpeedRotateGun(-GUN_SPEED);
}
//-----------------------------------------------------------
void SlaveForm::sl_LeftPressed()
{
	mTCT->SetSpeedRotateTurret(-TURRET_SPEED);
}
//-----------------------------------------------------------
void SlaveForm::sl_RightPressed()
{
	mTCT->SetSpeedRotateTurret(TURRET_SPEED);
}
//-----------------------------------------------------------
void SlaveForm::sl_DownReleased()
{
	mTCT->SetSpeedRotateGun(0);
}
//-----------------------------------------------------------
void SlaveForm::sl_UpReleased()
{
	mTCT->SetSpeedRotateGun(0);
}
//-----------------------------------------------------------
void SlaveForm::sl_LeftReleased()
{
	mTCT->SetSpeedRotateTurret(0);
}
//-----------------------------------------------------------
void SlaveForm::sl_RightReleased()
{
	mTCT->SetSpeedRotateTurret(0);
}
//-----------------------------------------------------------
