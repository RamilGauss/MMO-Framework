/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ConverterLocaleH
#define ConverterLocaleH

#include "TypeDef.h"
#include "ContainerTypes.h"

#include <boost/locale/util.hpp>
#include <boost/cstdint.hpp>

class DllExport TConverterLocale
{
public:
  TContainer Convert(std::string coderFrom, std::string coderTo, TContainer& cFrom);

	static TContainer ToUicode(std::string coderFrom, TContainer& cFrom);
	static TContainer FromUicode(std::string coderTo, TContainer& cTo);

	static std::wstring ConvertUtf8ToUnicode(std::string utf8);
private:
  static std::auto_ptr<boost::locale::util::base_converter> MakeCode(std::string code);
};


#endif
