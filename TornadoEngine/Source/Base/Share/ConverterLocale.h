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
  std::auto_ptr<boost::locale::util::base_converter> mConvFrom;
  std::auto_ptr<boost::locale::util::base_converter> mConvTo;

public:
  bool Setup(std::string coderFrom, std::string coderTo);
  TContainer Convert(TContainer& cFrom);
private:
  std::auto_ptr<boost::locale::util::base_converter> MakeCode(std::string code);
};

#endif
