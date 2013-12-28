/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ui_SuperServerForm.h"
#include "SuperServerForm.h"

#include "../QtLib/IQtLib.h"
#include "../GameLib/IServerDeveloperTool.h"
#include "BL_Debug.h"

SuperServerForm::SuperServerForm(QWidget *parent)
{
  ui.setupUi(this);
  setWindowTitle(tr("SuperServer"));
  Refresh();
}
//-----------------------------------------------------------
SuperServerForm::~SuperServerForm()
{

}
//-----------------------------------------------------------
void SuperServerForm::customEvent( QEvent * event)
{

}
//-----------------------------------------------------------
void SuperServerForm::closeEvent(QCloseEvent * event)
{
  int type = 0;
  // создать событие для главного потока, здесь менять нельзя, мы находимся в потоке Qt
  IServerDeveloperTool::Singleton()->GetComponent()->mQtGUI->AddEventCopy(&type,sizeof(type));

  delete this;
}
//-----------------------------------------------------------
void SuperServerForm::Add(TDesc& desc)
{
  mMapID_SessionDesc.insert(TMapUintDesc::value_type(desc.id_session,desc));

  Refresh();
}
//-----------------------------------------------------------
void SuperServerForm::Delete(unsigned int id_session)
{
  mMapID_SessionDesc.erase(id_session);
  
  Refresh();
}
//-----------------------------------------------------------
void SuperServerForm::Refresh()
{
  QString sCount = QString("%1").arg(mMapID_SessionDesc.size());
  ui.lCount->setText(sCount);
	ui.table->setRowCount(mMapID_SessionDesc.size());

  union IP
  {
    unsigned char c[4];
    unsigned int d;
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
