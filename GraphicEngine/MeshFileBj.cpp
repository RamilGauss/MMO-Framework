/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MeshFileBj.h"
#include "SaveOnHDD.h"
#include "LoadFromHDD.h"
#include "IXML.h"

using namespace nsMeshStruct;


TMeshFileBj::TMeshFileBj()
{
  pReadData = NULL;
}
//-----------------------------------------------------------------------------------
TMeshFileBj::~TMeshFileBj()
{

}
//-----------------------------------------------------------------------------------
bool TMeshFileBj::Load(const char* strFilename, 
            VERTEX*&      pVertex, unsigned int& cntV,
            unsigned int*& pIndex, unsigned int& cntI)
{
  Done();
  /*
    4 байта - число точек (DWORD)
     точки по 32 байта
    все остальное - это индексы
  */
  TLoadFromHDD loader;
  if(loader.ReOpen((char*)strFilename)==false) return false;
  int size = loader.Size();

  pReadData = new char[size];
  loader.Read(pReadData,size);
  char* buffer = pReadData;

  // вершины
  cntV = *((unsigned int*)buffer);
  pVertex = new VERTEX[cntV];
  buffer += sizeof(cntV);
  memcpy(pVertex,buffer,cntV*sizeof(VERTEX));

  // индексы
  cntI = (size - sizeof(cntV)-cntV*sizeof(VERTEX))/sizeof(unsigned int);
  pIndex = new unsigned int[cntI];
  buffer += cntV*sizeof(VERTEX);
  memcpy(pIndex, buffer, cntI*sizeof(unsigned int));

  return true;
}
//-----------------------------------------------------------------------------------
bool TMeshFileBj::Save(const char* strFilename, 
                  VERTEX*       pVertex, unsigned int cntV,
                  unsigned int* pIndex,  unsigned int cntI) 
{
  TSaveOnHDD saver;
  RET_FALSE(saver.ReOpen((char*)strFilename));

  saver.Write(&cntV,sizeof(cntV));// кол-во точек
  // сохранить вершины
  saver.Write( pVertex, cntV*sizeof( VERTEX ) );
  saver.Write( pIndex, cntI*sizeof( unsigned int ) );
  return true;
}
//-----------------------------------------------------------------------------------
void TMeshFileBj::Done()
{
  delete[] pReadData;
  pReadData = NULL;
}
//-----------------------------------------------------------------------------------
