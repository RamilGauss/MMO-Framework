/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ui_MasterForm.h"
#include "MasterForm.h"

#include <QLabel>

#include "ModuleLogic.h"
#include <boost/foreach.hpp>
#include "ListModules.h"
#include "MasterLogic.h"

TMasterForm::TMasterForm(QWidget *parent)
{
  ui.setupUi(this);
  setWindowTitle(tr("Master"));

  SetConnect(false);
  
  Refresh();

  connect(ui.bCreateGroup, SIGNAL(clicked()), this, SLOT(sl_CreateGroup()));
}
//-----------------------------------------------------------
TMasterForm::~TMasterForm()
{

}
//-----------------------------------------------------------
void TMasterForm::customEvent( QEvent * event)
{

}
//-----------------------------------------------------------
void TMasterForm::closeEvent(QCloseEvent * event)
{
  TModuleLogic::Get()->Exit();
  delete this;
}
//-----------------------------------------------------------
void TMasterForm::SetConnect(bool val)
{
  QPixmap pixmap(20,20);
  if(val)
    pixmap.fill(QColor(Qt::green));
  else
    pixmap.fill(QColor(Qt::red));
  ui.lColor->setPixmap(pixmap);
}
//-----------------------------------------------------------
void TMasterForm::Add(TDesc& desc)
{
  mMapID_SessionDesc.insert(TMapUintDesc::value_type(desc.id_session,desc));

  Refresh();
}
//-----------------------------------------------------------
void TMasterForm::Delete(unsigned int id_session)
{
  mMapID_SessionDesc.erase(id_session);

  Refresh();
}
//-----------------------------------------------------------
void TMasterForm::Refresh()
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
void TMasterForm::sl_CreateGroup()
{
  TModuleLogic::Get()->CallBackModule(nsListModules::MMOEngineMaster, &TMasterLogic::CreateGroup );
}
//-----------------------------------------------------------
