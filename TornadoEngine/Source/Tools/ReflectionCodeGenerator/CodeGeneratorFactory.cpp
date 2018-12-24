/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CodeGeneratorFactory.h"
#include "fmt/time.h"
#include "fmt/color.h"


using namespace fmt::literals;

class IStringed
{
public:
  virtual std::string ToString() = 0;
};

class TMethodBegin : public IStringed
{
public:
  std::string mReturnedType = "void";
  std::string mNameMethod;
  std::string mEndMethod = ";";

  //std::vector<T>

  virtual std::string ToString() override
  {
    return fmt::format( "{} {}({}){}", mReturnedType, mNameMethod, mEndMethod );
  }
};
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
ICodeGenerator* TCodeGeneratorFactory::Get( std::string& name )
{
  return nullptr;
}
//---------------------------------------------------------------------------------------------

