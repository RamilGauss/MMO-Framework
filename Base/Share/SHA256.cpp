/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SHA256.h"

#include <openssl/sha.h>

namespace nsSHA256
{
  #define CONTEXT ((SHA256_CTX*)mContext)
}

using namespace nsSHA256;

TSHA256::TSHA256()
{
  mContext = new SHA256_CTX;
}
//-------------------------------------------------------------
TSHA256::~TSHA256()
{
  delete CONTEXT;
}
//-------------------------------------------------------------
void TSHA256::Begin()
{
  // Инициализируем контекст
  SHA256_Init(CONTEXT);
}
//-------------------------------------------------------------
void TSHA256::Calc(void* pIn, int sizeIn)
{
  SHA256_Update(CONTEXT, pIn, sizeIn);
}
//-------------------------------------------------------------
void TSHA256::End(TContainer& result)
{
  result.SetData(NULL, SHA256_DIGEST_LENGTH);

  SHA256_Final((unsigned char*)result.GetPtr(), CONTEXT);
}
//-------------------------------------------------------------
void TSHA256::FastCalc(void* pIn, int sizeIn, TContainer& result)
{
  Begin();
  Calc(pIn, sizeIn);
  End(result);
}
//-------------------------------------------------------------