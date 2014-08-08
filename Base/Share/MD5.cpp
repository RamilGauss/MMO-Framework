/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MD5.h"

#include <openssl/md5.h>

namespace nsMD5
{
  #define CONTEXT ((MD5_CTX*)mContext)
}

using namespace nsMD5;

TMD5::TMD5()
{
  mContext = new MD5_CTX;
}
//-------------------------------------------------------------
TMD5::~TMD5()
{
  delete CONTEXT;
}
//-------------------------------------------------------------
void TMD5::Begin()
{
  // Инициализируем контекст
  MD5_Init(CONTEXT);
}
//-------------------------------------------------------------
void TMD5::Calc(void* pIn, int sizeIn)
{
  MD5_Update(CONTEXT, pIn, sizeIn);
}
//-------------------------------------------------------------
void TMD5::End(TContainer& result)
{
  result.SetData(NULL, MD5_DIGEST_LENGTH);

  MD5_Final((unsigned char*)result.GetPtr(), CONTEXT);
}
//-------------------------------------------------------------
void TMD5::FastCalc(void* pIn, int sizeIn, TContainer& result)
{
  Begin();
  Calc(pIn, sizeIn);
  End(result);
}
//-------------------------------------------------------------