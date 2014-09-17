/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MainForm.h"

#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include "BL_Debug.h"


TMainForm::TMainForm(QWidget *parent)
: QWidget(parent)
{
  m_pd3dDevice = NULL;
  m_pD3D       = NULL;

  ui.setupUi(this);

  setWindowTitle(tr("Конвертер из Obj в Bj"));

  LoadFromReestr();

  connect(ui.bSetPath,SIGNAL(clicked()),SLOT(sl_SetPath()));
  connect(ui.bStart,  SIGNAL(clicked()),SLOT(sl_Start()));
}
//---------------------------------------------------------------------------------------------
TMainForm::~TMainForm()
{
  SaveInReestr();
}
//---------------------------------------------------------------------------------------------
void TMainForm::sl_SetPath()
{
  QString path = ui.lePath->text();
  QFileDialog fileDialog;
  if(!path.isEmpty())
    fileDialog.setDirectory(path);
  fileDialog.setFileMode(QFileDialog::Directory);

  if(fileDialog.exec())
    ui.lePath->setText(fileDialog.directory().absolutePath());

  SaveInReestr();
}
//---------------------------------------------------------------------------------------------
void TMainForm::sl_Start()
{
  // для загрузки Mesh нужно устройство
  MakeDevice();
  // создать список файлов
  MakeListPath();
  // загружать по одному и сохранять
  ConvertAll();

  DestroyDevice();
}
//---------------------------------------------------------------------------------------------
void TMainForm::SaveInReestr()
{
  QString path = ui.lePath->text();

  QSettings settings("RUSSIA","ConverterMesh");
  settings.setValue("path", path);
}
//-----------------------------------------------------------------
void TMainForm::LoadFromReestr()
{
  QSettings settings("RUSSIA","ConverterMesh");
  QString path = settings.value("path", QString()).toString();
  ui.lePath->setText(path);
}
//---------------------------------------------------------------------------------------------
void TMainForm::MakeListPath()
{
  mListPath.clear();
  // сканируем установленную директорию
  // ищем все что содержит расширение "obj"
  QDir dir(ui.lePath->text());
  QStringList nameFilters;
  nameFilters << tr("*.obj");
  mListPath = dir.entryInfoList(nameFilters, QDir::Files );
}
//---------------------------------------------------------------------------------------------
void TMainForm::ConvertAll()
{
  int cnt = mListPath.size();
  for(int i = 0 ; i < cnt ; i++)
    Convert(mListPath[i].filePath());
}
//---------------------------------------------------------------------------------------------
void TMainForm::Convert(QString sPathObj)
{
  QString sPathBj = sPathObj;
  int len = sPathBj.length();
  sPathBj.remove(len - 3,1);// .obj -> .bj

  ID3DXMesh* pMesh = mMeshFile.Load(m_pd3dDevice,sPathObj.toLocal8Bit().data());
  BL_ASSERT(pMesh);
  mMeshFile.SaveAsBj(sPathBj.toLocal8Bit().data(),pMesh);
  SAFE_RELEASE(pMesh);
}
//---------------------------------------------------------------------------------------------
void TMainForm::DestroyDevice()
{
  SAFE_RELEASE(m_pd3dDevice) ;
  SAFE_RELEASE(m_pD3D);
}
//---------------------------------------------------------------------------------------------
void TMainForm::MakeDevice()
{
  // Создание объекта Direct3D
  m_pD3D = Direct3DCreate9( D3D_SDK_VERSION);
  if( !m_pD3D )
    BL_FIX_BUG();

  // Создание устройства рендера.
  D3DPRESENT_PARAMETERS d3dpp = {0};
  d3dpp.Windowed = TRUE;
  d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
  d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
  d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
  d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  d3dpp.EnableAutoDepthStencil = TRUE;
  d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
  HRESULT hr;
  hr = m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, winId(),
    D3DCREATE_SOFTWARE_VERTEXPROCESSING,
    &d3dpp, &m_pd3dDevice );
  if( FAILED(hr) || !m_pd3dDevice)
    BL_FIX_BUG();
}
//---------------------------------------------------------------------------------------------
