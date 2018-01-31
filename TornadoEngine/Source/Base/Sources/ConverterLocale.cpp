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

std::auto_ptr<boost::locale::util::base_converter> TConverterLocale::MakeCode(std::string code)
{
  if(code==sCode_UTF8)
    return boost::locale::util::create_utf8_converter();

  return boost::locale::util::create_simple_converter( code );
}
//------------------------------------------------------------------------------------------
TContainer TConverterLocale::Convert(std::string coderFrom, std::string coderTo, TContainer& cFrom)
{
  TContainer cUnicode = ToUicode(coderFrom, cFrom);
  return FromUicode(coderTo, cUnicode);
}
//------------------------------------------------------------------------------------------
TContainer TConverterLocale::ToUicode(std::string coderFrom, TContainer& cFrom)
{
  std::auto_ptr<boost::locale::util::base_converter> coder = MakeCode(coderFrom);

  int newSize = cFrom.GetSize()*coder->max_len() + 1;
  TContainer cTemp;
  cTemp.SetData(NULL, newSize);
  memset(cTemp.GetPtr(), 0, cTemp.GetSize());

  const char* pCurFrom = (const char*)(cFrom.GetPtr());
  char* pEndFrom = cFrom.GetPtr() + cFrom.GetSize();

  char* pCurTo = cTemp.GetPtr();
  char* pEndTo = cTemp.GetPtr() + cTemp.GetSize();

  boost::uint32_t shiftTo = 0;
  while(true)
  {
    boost::uint32_t u = coder->to_unicode(pCurFrom, pEndFrom);
    if( u==coder->illegal )
    {
      BL_FIX_BUG();
      return cTemp;
    }
    memcpy(pCurTo + shiftTo, &u, sizeof(wchar_t));
    shiftTo += sizeof(wchar_t);
    if( pCurFrom >= pEndFrom )
      break;
  }
  TContainer cResult;
  cResult.SetData(cTemp.GetPtr(), shiftTo);
  return cResult;
}
//------------------------------------------------------------------------------------------
TContainer TConverterLocale::FromUicode(std::string coderFrom, TContainer& cFrom)
{
  std::auto_ptr<boost::locale::util::base_converter> coder = MakeCode(coderFrom);

  int newSize = cFrom.GetSize()*coder->max_len() + 1;
  TContainer cTemp;
  cTemp.SetData(NULL, newSize);
  memset(cTemp.GetPtr(), 0, cTemp.GetSize());

  wchar_t* pCurFrom = (wchar_t*)(cFrom.GetPtr());

  char* pCurTo = cTemp.GetPtr();
  char* pEndTo = cTemp.GetPtr() + cTemp.GetSize();

  int cnt = cFrom.GetSize()/sizeof(wchar_t);
  boost::uint32_t shiftTo = 0;
  for( int i = 0 ; i < cnt ; i++ )
  {
    boost::uint32_t u = pCurFrom[i];
    boost::uint32_t result = coder->from_unicode(u, pCurTo + shiftTo, pEndTo);
    shiftTo += result;
  }
  shiftTo += 1;
  TContainer cResult;
  cResult.SetData(cTemp.GetPtr(), shiftTo);
  char* p = cResult.GetPtr();
  p[shiftTo - 1] = 0;
  return cResult;
}
//------------------------------------------------------------------------------------------
std::wstring TConverterLocale::ConvertUtf8ToUnicode(std::string utf8)
{
  TContainer cUtf8;
  cUtf8.SetData( (char*)utf8.data(), utf8.length());
  TContainer cUnicode = ToUicode("utf-8", cUtf8);

  std::wstring result;

  wchar_t* pUnicode = (wchar_t*)cUnicode.GetPtr();
  int cnt = cUnicode.GetSize()/sizeof(wchar_t);
  for( int i = 0 ; i < cnt ; i++ )
  {
    result += pUnicode[i];
  }
  return result;
}
//------------------------------------------------------------------------------------------
