/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ConverterLocale.h"
#include <locale>
#include <string>

// source: https://github.com/svininykh/convert-utf8-to-cp1251/blob/master/main.cpp

typedef struct ConvLetter
{
  char	win1251;
  int		unicode;
} Letter;

static Letter g_letters [] =
{
{ (char)0x82, 0x201A }, // SINGLE LOW-9 QUOTATION MARK
{ (char)0x83, 0x0453 }, // CYRILLIC SMALL LETTER GJE
{ (char)0x84, 0x201E }, // DOUBLE LOW-9 QUOTATION MARK
{ (char)0x85, 0x2026 }, // HORIZONTAL ELLIPSIS
{ (char)0x86, 0x2020 }, // DAGGER
{ (char)0x87, 0x2021 }, // DOUBLE DAGGER
{ (char)0x88, 0x20AC }, // EURO SIGN
{ (char)0x89, 0x2030 }, // PER MILLE SIGN
{ (char)0x8A, 0x0409 }, // CYRILLIC CAPITAL LETTER LJE
{ (char)0x8B, 0x2039 }, // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
{ (char)0x8C, 0x040A }, // CYRILLIC CAPITAL LETTER NJE
{ (char)0x8D, 0x040C }, // CYRILLIC CAPITAL LETTER KJE
{ (char)0x8E, 0x040B }, // CYRILLIC CAPITAL LETTER TSHE
{ (char)0x8F, 0x040F }, // CYRILLIC CAPITAL LETTER DZHE
{ (char)0x90, 0x0452 }, // CYRILLIC SMALL LETTER DJE
{ (char)0x91, 0x2018 }, // LEFT SINGLE QUOTATION MARK
{ (char)0x92, 0x2019 }, // RIGHT SINGLE QUOTATION MARK
{ (char)0x93, 0x201C }, // LEFT DOUBLE QUOTATION MARK
{ (char)0x94, 0x201D }, // RIGHT DOUBLE QUOTATION MARK
{ (char)0x95, 0x2022 }, // BULLET
{ (char)0x96, 0x2013 }, // EN DASH
{ (char)0x97, 0x2014 }, // EM DASH
{ (char)0x99, 0x2122 }, // TRADE MARK SIGN
{ (char)0x9A, 0x0459 }, // CYRILLIC SMALL LETTER LJE
{ (char)0x9B, 0x203A }, // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
{ (char)0x9C, 0x045A }, // CYRILLIC SMALL LETTER NJE
{ (char)0x9D, 0x045C }, // CYRILLIC SMALL LETTER KJE
{ (char)0x9E, 0x045B }, // CYRILLIC SMALL LETTER TSHE
{ (char)0x9F, 0x045F }, // CYRILLIC SMALL LETTER DZHE
{ (char)0xA0, 0x00A0 }, // NO-BREAK SPACE
{ (char)0xA1, 0x040E }, // CYRILLIC CAPITAL LETTER SHORT U
{ (char)0xA2, 0x045E }, // CYRILLIC SMALL LETTER SHORT U
{ (char)0xA3, 0x0408 }, // CYRILLIC CAPITAL LETTER JE
{ (char)0xA4, 0x00A4 }, // CURRENCY SIGN
{ (char)0xA5, 0x0490 }, // CYRILLIC CAPITAL LETTER GHE WITH UPTURN
{ (char)0xA6, 0x00A6 }, // BROKEN BAR
{ (char)0xA7, 0x00A7 }, // SECTION SIGN
{ (char)0xA8, 0x0401 }, // CYRILLIC CAPITAL LETTER IO
{ (char)0xA9, 0x00A9 }, // COPYRIGHT SIGN
{ (char)0xAA, 0x0404 }, // CYRILLIC CAPITAL LETTER UKRAINIAN IE
{ (char)0xAB, 0x00AB }, // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
{ (char)0xAC, 0x00AC }, // NOT SIGN
{ (char)0xAD, 0x00AD }, // SOFT HYPHEN
{ (char)0xAE, 0x00AE }, // REGISTERED SIGN
{ (char)0xAF, 0x0407 }, // CYRILLIC CAPITAL LETTER YI
{ (char)0xB0, 0x00B0 }, // DEGREE SIGN
{ (char)0xB1, 0x00B1 }, // PLUS-MINUS SIGN
{ (char)0xB2, 0x0406 }, // CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I
{ (char)0xB3, 0x0456 }, // CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I
{ (char)0xB4, 0x0491 }, // CYRILLIC SMALL LETTER GHE WITH UPTURN
{ (char)0xB5, 0x00B5 }, // MICRO SIGN
{ (char)0xB6, 0x00B6 }, // PILCROW SIGN
{ (char)0xB7, 0x00B7 }, // MIDDLE DOT
{ (char)0xB8, 0x0451 }, // CYRILLIC SMALL LETTER IO
{ (char)0xB9, 0x2116 }, // NUMERO SIGN
{ (char)0xBA, 0x0454 }, // CYRILLIC SMALL LETTER UKRAINIAN IE
{ (char)0xBB, 0x00BB }, // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
{ (char)0xBC, 0x0458 }, // CYRILLIC SMALL LETTER JE
{ (char)0xBD, 0x0405 }, // CYRILLIC CAPITAL LETTER DZE
{ (char)0xBE, 0x0455 }, // CYRILLIC SMALL LETTER DZE
{ (char)0xBF, 0x0457 }  // CYRILLIC SMALL LETTER YI
};

bool convert_utf8_to_windows1251( const char* utf8, char* windows1251, size_t n )
{
  int i = 0;
  int j = 0;
  for( ; i < (int) n && utf8[i] != 0; ++i )
  {
    char prefix = utf8[i];
    char suffix = utf8[i + 1];
    if( (prefix & 0x80) == 0 )
    {
      windows1251[j] = (char) prefix;
      ++j;
    }
    else if( (~prefix) & 0x20 )
    {
      int first5bit = prefix & 0x1F;
      first5bit <<= 6;
      int sec6bit = suffix & 0x3F;
      int unicode_char = first5bit + sec6bit;

      if( unicode_char >= 0x410 && unicode_char <= 0x44F )
      {
        windows1251[j] = (char) (unicode_char - 0x350);
      }
      else if( unicode_char >= 0x80 && unicode_char <= 0xFF )
      {
        windows1251[j] = (char) (unicode_char);
      }
      else if( unicode_char >= 0x402 && unicode_char <= 0x403 )
      {
        windows1251[j] = (char) (unicode_char - 0x382);
      }
      else
      {
        int count = sizeof( g_letters ) / sizeof( Letter );
        for( int k = 0; k < count; ++k )
        {
          if( unicode_char == g_letters[k].unicode )
          {
            windows1251[j] = g_letters[k].win1251;
            goto NEXT_LETTER;
          }
        }
        // can't convert this char
        return false;
      }
NEXT_LETTER:
      ++i;
      ++j;
    }
    else
    {
      // can't convert this chars
      return 0;
    }
  }
  //windows1251[j] = 0;
  return true;
}
//------------------------------------------------------------------------------------------
TContainer TConverterLocale::ConvertUtf8ToCp1251( TContainer& utf8 )
{
  TContainer cp1251;
  cp1251.SetData( nullptr, utf8.GetSize() );
  convert_utf8_to_windows1251( utf8.GetPtr(), cp1251.GetPtr(), utf8.GetSize() );
  return cp1251;
}
//------------------------------------------------------------------------------------------
std::wstring TConverterLocale::ConvertUtf8ToCp1251( std::string& utf8 )
{
  TContainer cUtf8;
  cUtf8.SetData( (char*) utf8.data(), utf8.size() );
  TContainer cWin1251 = TConverterLocale::ConvertUtf8ToCp1251( cUtf8 );

  std::wstring wstr(cWin1251.GetSize(), 0);
  std::use_facet<std::ctype<wchar_t> >( std::locale() ).widen
  ( cWin1251.GetPtr(), cWin1251.GetPtr() + cWin1251.GetSize(), &wstr[0] );
  return wstr;
}
//------------------------------------------------------------------------------------------
