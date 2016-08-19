/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ConverterLocale.h"

#include "BL_Debug.h"

namespace nsConverterLocale
{
  const char* sCode_UTF8 = "utf-8";
}

using namespace nsConverterLocale;

bool TConverterLocale::Setup(std::string coderFrom, std::string coderTo)
{
  mConvFrom = MakeCode( coderFrom );
  mConvTo   = MakeCode( coderTo );

  if( mConvFrom.get()==NULL || mConvTo.get()==NULL )
    return false;
  return true;
}
//------------------------------------------------------------------------------------------
std::auto_ptr<boost::locale::util::base_converter> TConverterLocale::MakeCode(std::string code)
{
  if(code==sCode_UTF8)
    return boost::locale::util::create_utf8_converter();

  return boost::locale::util::create_simple_converter( code );
}
//------------------------------------------------------------------------------------------
TContainer TConverterLocale::Convert(TContainer& cFrom)
{
  if( mConvFrom.get()==NULL || mConvTo.get()==NULL )
  {
    BL_FIX_BUG();
    return TContainer();
  }
  
  int newSize = cFrom.GetSize()*mConvTo->max_len() + 1;
  TContainer cResult;
  cResult.SetData(NULL, newSize);
  memset(cResult.GetPtr(), 0, cResult.GetSize());

  const char* pCurFrom = (const char*)(cFrom.GetPtr());
  char* pEndFrom = cFrom.GetPtr() + cFrom.GetSize();

  char* pCurTo = cResult.GetPtr();
  char* pEndTo = cResult.GetPtr() + cResult.GetSize();

  boost::uint32_t shiftTo = 0;
  while(true)
  {
    boost::uint32_t u = mConvFrom->to_unicode(pCurFrom, pEndFrom);
    boost::uint32_t result = mConvTo->from_unicode( u, pCurTo + shiftTo, pEndTo );
    if( int(result) <= 0)
      return cResult;
    shiftTo += result;
    if( pCurFrom - pEndFrom >= cFrom.GetSize() )
      break;
  }
  return cResult;
}
//------------------------------------------------------------------------------------------

