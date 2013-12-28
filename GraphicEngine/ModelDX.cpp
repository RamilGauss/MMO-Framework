/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModelDX.h"

#include <stdlib.h>
#include <atlconv.h>
#include <boost/foreach.hpp>

#include "SDKmisc.h"
#include "LoaderModelDX.h"
#include "Logger.h"
#include "LoaderModelDX.h"
#include "BL_Debug.h"
#include "MakerLoaderModelGE.h"

#include "SortByAlphabetic.h"
#include "ManagerResourceDX.h"

#include "HiTimer.h"
#include "IGraphicEngine.h"


using namespace nsStruct3D;
using namespace std;

const char* NameBeginOutputParam = "BeginOutputParam";// в будущем перенести в файл настроек
const char* NameEndOutputParam   = "EndOutputParam";

TModelDX::TModelDX(TManagerResourceDX* managerResourceDX)
{
  mManagerResourceDX = managerResourceDX;

  mID = -1;
  m_pd3dDevice = NULL;
}
//----------------------------------------------------------------------------------------------------
TModelDX::~TModelDX()
{
  Done();
}
//----------------------------------------------------------------------------------------------------
void TModelDX::Draw(vector<void*>* pVecTexCubeMap,    //                           (От ObjectDX)
                    vector<unsigned char>* state, // какое состояние нарисовать (От ObjectDX)
                    vector<unsigned char>* mask,  // какую из частей нарисовать (От ObjectDX)
                    vector<TMatrix16*>* matrix,// ориентация составных частей внутри объекта, кол-во совпадает с cSubset (От ObjectDX)
                    TMatrix16* pWorld,// где и как расположен объект         (От ObjectDX)
                    float alphaTransparency,
                    const TMatrix16* pView,/*для определения дистанции*/ // расположение и ориентация камеры    (от ManagerDirectX)                   
                    void* pEffect)
{
  if(pEffect)
    DrawBy(pEffect,
           pVecTexCubeMap,    //                           (От ObjectDX)
           state, // какое состояние нарисовать (От ObjectDX)
           mask,  // какую из частей нарисовать (От ObjectDX)
           matrix,// ориентация составных частей внутри объекта, кол-во совпадает с cSubset (От ObjectDX)
           pWorld,// где и как расположен объект         (От ObjectDX)
           alphaTransparency,
           pView);/*для определения дистанции*/ // расположение и ориентация камеры    (от ManagerDirectX)                   
  else
    DrawSelf(pVecTexCubeMap,    //
             state, // какое состояние нарисовать 
             mask,  // какую из частей нарисовать 
             matrix,// ориентация составных частей внутри объекта, кол-во совпадает с cSubset
             pWorld,// где и как расположен объект 
             alphaTransparency,
             pView);/*для определения дистанции*/ // расположение и ориентация камеры
}
//----------------------------------------------------------------------------------------------------
void TModelDX::DrawSelf(vector<void*>* pVecTexCubeMap,    //    
										    vector<unsigned char>* state, // какое состояние нарисовать 
                        vector<unsigned char>* mask,  // какую из частей нарисовать 
                        vector<TMatrix16*>* matrix,// ориентация составных частей внутри объекта, кол-во совпадает с cSubset
                        TMatrix16* pWorld,// где и как расположен объект        
                        float alphaTransparency,
                        const TMatrix16* pView)/*для определения дистанции*/ // расположение и ориентация камеры
{
  D3DXMATRIXA16 mWorld;// только из набора видимых
  MATRIX16_EQUAL_M_P(mWorld,pWorld)

  //1 Выбрать по ЛОДу mesh
  // расчет расстояния
  float dist = CalcDist(pWorld,pView);
  //2 Настроить pEffect на координаты и ориентацию - передать в pEffect матрицу
  // если mArrMatrixSubset==NULL, то координаты и ориентация частей модели неизменны
  //3 Выбрать по состоянию subSet
  TLOD* pCurLOD = &mVectorLOD[0];
  if(mVectorLOD.size()>1)
    if(dist>mLOD)
      pCurLOD = &mVectorLOD[1];

  int cnt = GetCntEffect();
  int iView = 0;
  for(int i = 0 ; i < cnt ; i++)
  {
    if(mask->operator[](i)==1)
    {
      TEffectDX* pEffect = NULL;
      
      if(pCurLOD->normal.size()&&pCurLOD->damage.size())
      {
        pEffect = pCurLOD->normal[i];
        if(!state->operator[](i))
          pEffect = pCurLOD->damage[i];
      }
      else 
      {
        if(pCurLOD->normal.size())
          pEffect = pCurLOD->normal[i];
        else
          pEffect = pCurLOD->damage[i];
      }
      D3DXMATRIXA16 m;// только из набора видимых
      TMatrix16* pV = matrix->operator [](iView);// только из набора видимых
      MATRIX16_EQUAL_M_P(m,pV)

      D3DXMATRIXA16 mWorld_pro = m * mWorld;
      //-------------------------------------------------
      pEffect->SetAlphaTransparency(alphaTransparency);
      pEffect->SetInnerShaderParam();
      pEffect->SetMatrixWorld(&mWorld_pro);
			pEffect->SetTexCubeMap((IDirect3DCubeTexture9**)pVecTexCubeMap->at(i));
      SetShaderStack(pEffect,i);// все части, включая дубликаты
      Draw(pEffect, pEffect->GetMesh());
      iView++;
    }
  }
}
//---------------------------------------------------------------------------------------------------
void TModelDX::Draw( TEffectDX* pEffect, ID3DXMesh* pCurMesh)
{
  HRESULT hr;
  UINT iPass, cPasses;

  V( pEffect->Begin( &cPasses, 0 ) );
  for( iPass = 0; iPass < cPasses; iPass++ )
  {
    V( pEffect->BeginPass( iPass ) );
    // Render the mesh with the applied technique
      V( pCurMesh->DrawSubset( 0 /*Subset*/ ) );
    V( pEffect->EndPass() );
  }
  V( pEffect->End() );
}
//----------------------------------------------------------------------------------------------------
bool TModelDX::Init(IDirect3DDevice9* pd3dDevice, LPCWSTR strAbsPath/*путь к файлам модели*/)
{
  Done();
  m_pd3dDevice = pd3dDevice;
  // загрузка данных примитивов, текстур и индексов.
  GetLogger(STR_NAME_GE)->WriteF_time("Загрузка Mesh, ID=%u\n",mID);
  if(Load(strAbsPath)==false) 
    return false;

  GetLogger(STR_NAME_GE)->WriteF_time("Конец загрузки Mesh, ID=%u\n",mID);

  int cnt = mVectorAllEffect.size();
  // структурировать данные
  for(int i = 0 ; i < cnt ; i++)
  {
    TEffectDX* pEffectDX = mVectorAllEffect[i];
    LoadEffect(pEffectDX); 
    pEffectDX->Init();
  }
  SetupVectorLOD();

  SetupShaderStack();
  return true;
}
//----------------------------------------------------------------------------------------------------
void TModelDX::Destroy()
{
  int cnt = GetCntEffect();
  for(int i = 0 ; i < cnt ; i++)
    mVectorAllEffect[i]->Destroy();
}
//----------------------------------------------------------------------------------------------------
void TModelDX::LostDevice()
{
  int cnt = GetCntEffect();
  for(int i = 0 ; i < cnt ; i++)
    mVectorAllEffect[i]->LostDevice();
	LostCubeMap();
}
//----------------------------------------------------------------------------------------------------
void TModelDX::ResetDevice()
{
  int cnt = GetCntEffect();
  for(int i = 0 ; i < cnt ; i++)
    mVectorAllEffect[i]->ResetDevice();

	ResetCubeMap();
}
//----------------------------------------------------------------------------------------------------
bool TModelDX::Load(LPCWSTR strFilenameData)
{
  ILoaderModelGE* pLoadModel;
  TMakerLoaderModelGE makerLoaderModelGE;
  pLoadModel = makerLoaderModelGE.New(m_pd3dDevice);
  if(pLoadModel->Load((wchar_t*)strFilenameData)==false)
  {
    USES_CONVERSION;
    GetLogger(STR_NAME_GE)->WriteF_time("Не удалось загрузить модель: %s.\n",W2A(strFilenameData));
    delete pLoadModel;
    return false;
  }
  //-------------------------------------------------------------------------------------------
  mLOD = pLoadModel->GetLOD();
  int cnt = pLoadModel->GetCountGroup();
  for(int i = 0 ; i < cnt ; i++)
  {
    ILoaderModelGE::TDefGroup *pDef = pLoadModel->GetGroup(i);
    // заполнение
    AddEffectDX(pDef);
  }

  makerLoaderModelGE.Delete(pLoadModel);

  return true;
}
//----------------------------------------------------------------------------------------------------
bool TModelDX::AddEffectDX(ILoaderModelGE::TDefGroup * pDefGroup)
{
  TEffectDX* pEffect = new TEffectDX;

  pEffect->mTypeLOD     = pDefGroup->mTypeLOD;
  pEffect->mflgNormal   = pDefGroup->mflgNormal;
  //----------------------------------------------------------
  // Load material textures
  TEffectDX::Material* pMaterial = &pEffect->mMaterial;
  // заполнить материал данными
	pMaterial->flgUseCubeMap = pDefGroup->flgUseCubeMap;
  pMaterial->strTechnique  = pDefGroup->strTechnique;
  pMaterial->strName       = pDefGroup->strName;
  pMaterial->mNumUse       = pDefGroup->mNumUse;
  pMaterial->strTexture    = pDefGroup->strTexture;
  USES_CONVERSION;
  pMaterial->strShader = A2W(pDefGroup->strPathShader.data());

  pMaterial->vAmbient   = D3DXVECTOR3(pDefGroup->vAmbient.x, pDefGroup->vAmbient.y, pDefGroup->vAmbient.z );
  pMaterial->vDiffuse   = D3DXVECTOR3(pDefGroup->vDiffuse.x, pDefGroup->vDiffuse.y, pDefGroup->vDiffuse.z );
  pMaterial->vSpecular  = D3DXVECTOR3(pDefGroup->vSpecular.x,pDefGroup->vSpecular.y,pDefGroup->vSpecular.z);

  pMaterial->nShininess = pDefGroup->nShininess;

  pMaterial->bSpecular  = pDefGroup->bSpecular;

  LoadTexture(pEffect);

  pEffect->SetMesh( (ID3DXMesh*)pDefGroup->pMesh );

  mVectorAllEffect.push_back(pEffect);
  return true;
}
//----------------------------------------------------------------------------------------------------
unsigned int TModelDX::GetIndexVisualGroupByName(char* sName, int num)
{
  TLOD* pLOD = &mVectorLOD[0];
  vector<TEffectDX*>*  v = pLOD->GetNonZeroVector();
  int cnt = v->size();
  int iFound = 0;
  for(int i = 0 ; i < cnt ; i++)
  {
    if(strcmp(v->operator [](i)->mMaterial.strName.data(),sName)==0)
    {
      if(iFound==num)
        return i;
      iFound++;
    }
  }
  GetLogger(STR_NAME_GE)->WriteF_time("Не найден эффект модели имя %s номер %d\n",sName,num);
  return 0;
}
//----------------------------------------------------------------------------------------------------
const char* TModelDX::GetNameByIndex(int index)
{
  TLOD* pLOD = &mVectorLOD[0];
  vector<TEffectDX*>*  v = pLOD->GetNonZeroVector();
  return v->operator [](index)->mMaterial.strName.data();
}
//----------------------------------------------------------------------------------------------------
int TModelDX::GetNumUseByIndex(int index)
{
  TLOD* pLOD = &mVectorLOD[0];
  vector<TEffectDX*>*  v = pLOD->GetNonZeroVector();
  return v->operator [](index)->mMaterial.mNumUse;
}
//----------------------------------------------------------------------------------------------------
int TModelDX::GetCntEffect()
{
  TLOD* pLOD = &mVectorLOD[0];
  vector<TEffectDX*>*  v = pLOD->GetNonZeroVector();
  return v->size();
}
//----------------------------------------------------------------------------------------------------
void TModelDX::SetupVectorLOD()
{
  mVectorLOD.clear();
  TLOD lod;
  mVectorLOD.push_back(lod);
  bool TwoLOD = false;
  int cnt = mVectorAllEffect.size();
  for(int i = 0 ; i < cnt ; i++)
  {
    if(mVectorAllEffect[i]->mTypeLOD==1)
    {
      TwoLOD = true;
      break;
    }
  }
  //----------------------------------------------------------------------------------------------------
  if(TwoLOD)
  mVectorLOD.push_back(lod);
  //----------------------------------------------------------------------------------------------------
  // структурировать данные
  for(int i = 0 ; i < cnt ; i++)
  {
    TEffectDX* pEffectDX = mVectorAllEffect[i];
    if(pEffectDX->mflgNormal)
      mVectorLOD[pEffectDX->mTypeLOD].normal.push_back(pEffectDX);
    else
      mVectorLOD[pEffectDX->mTypeLOD].damage.push_back(pEffectDX);
  }
}
//----------------------------------------------------------------------------------------------------
void TModelDX::LoadTexture(TEffectDX* pEffectDX)
{
  TEffectDX::Material* pMaterial = &(pEffectDX->mMaterial);
  pMaterial->pTexture = (IDirect3DTexture9*)mManagerResourceDX->Load(pMaterial->strTexture.data());
}
//----------------------------------------------------------------------------------------------------
void TModelDX::LoadEffect(TEffectDX* pEffectDX)
{
  //unsigned int start = ht_GetMSCount();

  pEffectDX->SetEffect( (ID3DXEffect*)mManagerResourceDX->Load(pEffectDX->mMaterial.strShader.data()) );

  //start = ht_GetMSCount() - start;
  //GlobalLoggerGE.WriteF_time("Загрузка эффекта t=%u\n",start);
}
//----------------------------------------------------------------------------------------------------
void TModelDX::SortPartByAlphabetic()
{
  int cntLod = mVectorLOD.size();
  for(int i = 0 ; i < cntLod ; i++)
  {
    TLOD* pLOD = &mVectorLOD.at(i);
    vector<TEffectDX*>* pVecEffect = NULL;
    switch(i)
    {
      case 0:
        pVecEffect = &(pLOD->normal);
        break;
      case 1:
        pVecEffect = &(pLOD->damage);
        break;
      default:;     
    }
    //----------------------------------------------------
    int cntPart = pVecEffect->size();
    vector<TSortByAlphabetic::T> vectorName_Use;
    for(int iPart = 0 ; iPart < cntPart ; iPart++)
    {
      TEffectDX* pEffectDX = pVecEffect->at(iPart);
      TSortByAlphabetic::T t;
      t.s = pEffectDX->mMaterial.strName;
      t.v = pEffectDX->mMaterial.mNumUse;
      t.index = iPart;
      vectorName_Use.push_back(t);
    }
    // сортируем
    TSortByAlphabetic sort;
    sort.Sort(&vectorName_Use);
    // в соответствии с вектором индексов согласуем вектор эффектов
    vector<TEffectDX*> pNewEffect;
    for(int iPart = 0 ; iPart < cntPart ; iPart++)
    {
      int index = vectorName_Use.at(iPart).index;
      TEffectDX* pEffectDX = pVecEffect->at(index);
      pNewEffect.push_back(pEffectDX);
    }
    *pVecEffect = pNewEffect;
  }
}
//----------------------------------------------------------------------------------------------------
void TModelDX::SetShaderStackMask(vector<int>* pVectorMask)// по этой маске настраиваются шейдеры эффектов
{
  mVectorShaderStackMask = *pVectorMask;
}
//----------------------------------------------------------------------------------------------------
TShaderStack* TModelDX::GetShaderStack(int index)// взять стек для настройки
{
  return mVectorShaderStack[index];
}
//----------------------------------------------------------------------------------------------------
void TModelDX::Done()
{
  mVectorLOD.clear();
  int cnt = mVectorAllEffect.size();
  for(int i = 0 ; i < cnt ; i++ )
    delete mVectorAllEffect[i];

  mVectorAllEffect.clear();

  cnt = mVectorShaderStack.size();
  for(int i = 0 ; i < cnt ; i++ )
  {
    delete mVectorShaderStack.at(i);
  }
  mVectorShaderStack.clear();

  mVectorShaderStackMask.clear();
}
//----------------------------------------------------------------------------------------------------
void TModelDX::SetShaderStack(TEffectDX* pEffect,int index)
{
  if(mVectorShaderStackMask[index]==1)
  {
    TShaderStack* pSS = mVectorShaderStack[index];
    mExecSS.Set(pEffect->GetEffect(),pSS);
  }
}
//----------------------------------------------------------------------------------------------------
void TModelDX::SetupShaderStack()
{
  vector<TEffectDX*>* pPart = mVectorLOD.at(0).GetNonZeroVector();
  int cnt = pPart->size();
  for(int i = 0 ; i < cnt ; i++ )
  {
    TEffectDX* pEffectDX = pPart->at(i);
    if(pEffectDX->mflgNormal)
      AddShaderStack(pEffectDX->GetEffect());
  }
}
//----------------------------------------------------------------------------------------------------
void TModelDX::AddShaderStack(ID3DXEffect* p)
{
  char pData[200];// для ускорения загрузки фальшивых данных
  TShaderStack* pSS = new TShaderStack;
  mVectorShaderStack.push_back(pSS);
  mVectorShaderStackMask.push_back(0);
  //----------------------------------------
  HRESULT hr;
  D3DXEFFECT_DESC pDesc;
  V( p->GetDesc(&pDesc) );

  bool flgBeginParam = false;
  int cnt = pDesc.Parameters;
  // поиск начала output param
  for(int i = 0 ; i < cnt ; i++)
  {
    D3DXPARAMETER_DESC pDescParam;
    D3DXHANDLE handle = p->GetParameter( 0, i );
    V( p->GetParameterDesc( handle, &pDescParam ) );
    if(pDescParam.Semantic)
    if(strcmp(pDescParam.Semantic,NameBeginOutputParam)==0)
      flgBeginParam = true;
    else 
    {
      if(strcmp(pDescParam.Semantic,NameEndOutputParam)==0)
        flgBeginParam = false;
      else
      {
        if(flgBeginParam)
        {
          int size = pDescParam.Bytes;
          pSS->Push(pDescParam.Semantic,pData,size);
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------	
//вернет IDirect3DCubeTexture9**
void* TModelDX::MakeTextureForCubeMap(int index)// для получения текстуры - надо перебрать все эффекты
{
	if(mVectorAllEffect[index]->UseCubeMap())
	{
		IDirect3DCubeTexture9* pTexCubeMap = NULL;
		// Create the cube textures
		HRESULT hr = m_pd3dDevice->CreateCubeTexture( IGraphicEngine::eEnvMapSizeCubemap,
			1,
			D3DUSAGE_RENDERTARGET,
			D3DFMT_A16B16G16R16F,
			D3DPOOL_DEFAULT,
			&pTexCubeMap,
			NULL );
		mListCubeMap.push_back(pTexCubeMap);
		return &mListCubeMap.front();
	}

	return NULL;
}
//----------------------------------------------------------------------------------------------------	
void TModelDX::LostCubeMap()
{
  BOOST_FOREACH(IDirect3DCubeTexture9* p,mListCubeMap)
    SAFE_RELEASE(p);
}
//----------------------------------------------------------------------------------------------------	
void TModelDX::ResetCubeMap()
{
  BOOST_FOREACH(IDirect3DCubeTexture9*& pTexCubeMap,mListCubeMap)
  {
    HRESULT hr = m_pd3dDevice->CreateCubeTexture( IGraphicEngine::eEnvMapSizeCubemap,
      1,
      D3DUSAGE_RENDERTARGET,
      D3DFMT_A16B16G16R16F,
      D3DPOOL_DEFAULT,
      &pTexCubeMap, NULL );
  }
}
//----------------------------------------------------------------------------------------------------	
void TModelDX::DrawBy(void* pVecEffect,// пока один эффект на модель, но нужно будет переделать на вектор
                      vector<void*>* pVecTexCubeMap,    //                           
                      vector<unsigned char>* state,     //                           
                      vector<unsigned char>* mask,      //                           
                      vector<TMatrix16*>* matrix,//кол-во совпадает с cSubset 
                      TMatrix16* pWorld,    // где и как расположен объект         
                      float alphaTransparency,  // прозрачность                        
                      const TMatrix16* pView)// расположение и ориентация камеры    
{
  TEffectDX* pEffectBy   = (TEffectDX*)pVecEffect;// одним эффектом прорисовываются все части
  //------------------------------------------------
  D3DXMATRIXA16 mWorld;// только из набора видимых
  MATRIX16_EQUAL_M_P(mWorld,pWorld)

  //1 Выбрать по ЛОДу mesh
  // расчет расстояния
  float dist = CalcDist(pWorld,pView);
  //2 Настроить pEffect на координаты и ориентацию - передать в pEffect матрицу
  // если mArrMatrixSubset==NULL, то координаты и ориентация частей модели неизменны
  //3 Выбрать по состоянию subSet
  TLOD* pCurLOD = &mVectorLOD[0];
  if(mVectorLOD.size()>1)
    if(dist>mLOD)
      pCurLOD = &mVectorLOD[1];

  int cnt = GetCntEffect();
  int iView = 0;
  for(int i = 0 ; i < cnt ; i++)
  {
    if(mask->operator[](i)==1)
    {
      TEffectDX* pEffectSelf = NULL;// одним эффектом прорисовываются все части
      if(pCurLOD->normal.size()&&pCurLOD->damage.size())
      {
        pEffectSelf = pCurLOD->normal[i];
        if(!state->operator[](i))
          pEffectSelf = pCurLOD->damage[i];
      }
      else 
      {
        if(pCurLOD->normal.size())
          pEffectSelf = pCurLOD->normal[i];
        else
          pEffectSelf = pCurLOD->damage[i];
      }
      //------------------------------------------
      D3DXMATRIXA16 m;// только из набора видимых
      TMatrix16* pV = matrix->operator [](iView);// только из набора видимых
      MATRIX16_EQUAL_M_P(m,pV)

      D3DXMATRIXA16 mWorld_pro = m * mWorld;
      //-------------------------------------------------
      pEffectBy->SetAlphaTransparency(alphaTransparency);
      pEffectBy->SetInnerShaderParam();
      pEffectBy->SetMatrixWorld(&mWorld_pro);
      pEffectBy->SetTexCubeMap((IDirect3DCubeTexture9**)pVecTexCubeMap->at(i));
      SetShaderStack(pEffectBy,i);// все части, включая дубликаты
      Draw(pEffectBy, pEffectSelf->GetMesh());
      iView++;
    }
  }
}
//----------------------------------------------------------------------------------------------------	
