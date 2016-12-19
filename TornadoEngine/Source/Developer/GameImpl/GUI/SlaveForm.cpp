/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ui_SlaveForm.h"
#include "SlaveForm.h"

#include "ModuleLogic.h"
#include <boost/foreach.hpp>
#include "ListModules.h"
#include "ModuleMMOEngineSlave.h"

TSlaveForm::TSlaveForm(QWidget *parent)
{
  ui.setupUi(this);

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
TSlaveForm::~TSlaveForm()
{

}
//-----------------------------------------------------------
void TSlaveForm::customEvent( QEvent * event)
{

}
//-----------------------------------------------------------
void TSlaveForm::closeEvent(QCloseEvent * event)
{
  int type = 0;
  TModuleLogic::Get()->Exit();

  delete this;
}
//-----------------------------------------------------------
void TSlaveForm::SetConnect(bool val)
{
  QPixmap pixmap(20,20);
  if(val)
    pixmap.fill(QColor(Qt::green));
  else
    pixmap.fill(QColor(Qt::red));
  ui.lColor->setPixmap(pixmap);
}
//-----------------------------------------------------------
void TSlaveForm::Add(TDesc& desc)
{
  mMapID_SessionDesc.insert(TMapUintDesc::value_type(desc.id_session,desc));

  TModuleLogic::Get()->CallBackModuleParam(nsListModules::MMOEngineSlave, 
    &TSlaveForm::Update_MMOEngine, &desc.id_session);
}
//-----------------------------------------------------------
void TSlaveForm::Delete(unsigned int id_session)
{
  mMapID_SessionDesc.erase(id_session);

  Refresh();
}
//-----------------------------------------------------------
void TSlaveForm::Update_MMOEngine(unsigned int* pID)
{
  TDesc* pDesc = new TDesc;
  pDesc->id_session = *pID;

  bool resInfoSession = TModuleLogic::Get()->GetC()->pMMOEngineSlave->Get()->
    GetInfoSession( pDesc->id_session, pDesc->ip_port );
  BL_ASSERT(resInfoSession);
  
  TModuleLogic::Get()->CallBackModuleParam(nsListModules::AloneGUI, 
    &TSlaveForm::Update, pDesc);
}
//---------------------------------------------------------------------------------------------
void TSlaveForm::Update(TDesc* pDesc)
{
  TMapUintDescIt fit = mMapID_SessionDesc.find(pDesc->id_session);
  if(fit==mMapID_SessionDesc.end())
    return;
  fit->second = *pDesc;

  Refresh();
}
//-----------------------------------------------------------
void TSlaveForm::Refresh()
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
