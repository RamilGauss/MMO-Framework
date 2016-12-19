/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ui_SuperServerForm.h"
#include "SuperServerForm.h"

#include "BL_Debug.h"
#include "ModuleLogic.h"
#include <boost/foreach.hpp>
#include "ModuleMMOEngineSuperServer.h"
#include "ListModules.h"

TSuperServerForm::TSuperServerForm(QWidget *parent)
{
  ui.setupUi(this);
  setWindowTitle(tr("SuperServer"));
  Refresh();
}
//-----------------------------------------------------------
TSuperServerForm::~TSuperServerForm()
{

}
//-----------------------------------------------------------
void TSuperServerForm::customEvent( QEvent * event)
{

}
//-----------------------------------------------------------
void TSuperServerForm::closeEvent(QCloseEvent * event)
{
  // создать событие для главного потока, здесь менять нельзя, мы находимся в потоке Qt
  TModuleLogic::Get()->Exit();

  delete this;
}
//-----------------------------------------------------------
void TSuperServerForm::Add(TDesc& desc)
{
  mMapID_SessionDesc.insert(TMapUintDesc::value_type(desc.id_session,desc));

  TModuleLogic::Get()->CallBackModuleParam(nsListModules::MMOEngineSuperServer, 
    &TSuperServerForm::Update_MMOEngine, &desc.id_session);
}
//-----------------------------------------------------------
void TSuperServerForm::Delete(unsigned int id_session)
{
  mMapID_SessionDesc.erase(id_session);
  
  Refresh();
}
//-----------------------------------------------------------
void TSuperServerForm::Update_MMOEngine(unsigned int* pID)
{
  TDesc* pDesc = new TDesc;
  pDesc->id_session = *pID;

  bool resInfoSession = TModuleLogic::Get()->GetC()->pMMOEngineSuperServer->Get()->
    GetInfoSession( pDesc->id_session, pDesc->ip_port );
  BL_ASSERT(resInfoSession);

  TModuleLogic::Get()->CallBackModuleParam(nsListModules::AloneGUI, 
    &TSuperServerForm::Update, pDesc);
}
//---------------------------------------------------------------------------------------------
void TSuperServerForm::Update(TDesc* pDesc)
{
  TMapUintDescIt fit = mMapID_SessionDesc.find(pDesc->id_session);
  if(fit==mMapID_SessionDesc.end())
    return;
  fit->second = *pDesc;

  Refresh();
}
//-----------------------------------------------------------
void TSuperServerForm::Refresh()
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
